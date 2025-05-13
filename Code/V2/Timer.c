/*
 * Timer0.C
 *
 *  Created on: Aug 20, 2023
 *      Author: yasmeen
 *       SWC:Timers
 *      Version:1.2
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer.h"
#include "avr/io.h"
#include "avr/interrupt.h"

/*Step 3 in setting call back --> define Global Pointer to function  */
void (*Timer_PFUN)(void);


void Timers_VidTimer0Init()
{
	                           /*1-Select mode*/
#if Timer0_Mode_Select == Timer0_OVF_Mode
	/* Normal mode */

	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif Timer0_Mode_Select == Timer0_CTC_Mode
	//CTC MODE
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#elif Timer0_Mode_Select == Timer0_FastPWM_Mode
	//FAST PWM MODE
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#elif Timer0_Mode_Select == Timer0_PhaseCorrectPWM_Mode
	//FAST PWM MODE
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);

#endif


	//SET ON TOP CLLEAR ON COMPARE MODE ==== FOR CONFIGURE THE HARDWARE PIN FOR FAST PWM
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	/*
	//SET ON TOP CLLEAR ON COMPARE MODE ==== FOR CONFIGURE THE HARDWARE PIN FOR PHASE CORRECT PWM
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);

	/*2-GLOBAL Interrupt enable */
	/*FIRST STEP: GIE ENABLE*/
	SET_BIT(SREG, 7);

	                        /*3-PERIPHERAL Interrupt enable */
//the gray area will not be down loaded in the flash memory
#if Timer0_Mode_Select == Timer0_OVF_Mode
	/*SECOND STEP: PIE--->OVF ENABLE*/
	SET_BIT(TIMSK, TOIE0);
#elif Timer0_Mode_Select == Timer0_CTC_Mode
	SET_BIT(TIMSK,OCIE0);  //FOR CTC
#endif

                         	/*4-Pre_load value*/
#if Timer0_Mode_Select == Timer0_OVF_Mode
	TCNT0 = 128; //for orerflow
#elif Timer0_Mode_Select == Timer0_CTC_Mode
	OCR0=99;
#endif

	                        /* 5-pre_scalar */  //to enable the timer after all the previous steps(LAST STEP)
#if TIMER0_PRESCALE_Select == TIMER0_TIMER_OFF
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);

#elif TIMER0_PRESCALE_Select == TIMER0_NO_PRESCALE
	SET_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);

#elif TIMER0_PRESCALE_Select == TIMER0_PRESCALE_8
	CLR_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
#elif TIMER0_PRESCALE_Select == TIMER0_PRESCALE_64
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
#elif TIMER0_PRESCALE_Select == TIMER0_PRESCALE_256
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
#elif TIMER0_PRESCALE_Select == TIMER0_PRESCALE_1024
	SET_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
#endif
}
/*Step 2 in setting call back --> Implement Function to Recive the function from the main */
void Timer0_SETCallBack(void (*TIMER0_PTR)(void))
{
	/*Step 4 in setting call back --> passing the address of the function to the global pointer  */
	Timer_PFUN=TIMER0_PTR;
}


ISR(TIMER0_OVF_vect)
{
	static u16 Local_U16Counter=0; //U16 BEC WE WANT TO COUNT 3907 SO U8 IS NOT SUIT
		Local_U16Counter++;
		if(Local_U16Counter==7813)  //7813 for 16 bits
		{
			Local_U16Counter=0;
			TCNT0=128;    //FOR 16 BIT
			//TCNT0=192;
			Timer_PFUN();
		}
}

ISR(TIMER0_COMP_vect)
{
	static u16 Local_U16Counter = 0 ;
	Local_U16Counter++ ;

	if( Local_U16Counter == 20000 )
	{
		Local_U16Counter = 0 ;

		Timer_PFUN();
	}
}

//FOR FAST PWM
void Timer0_VidTimer0SetOCR_FASRPWM(u8 copy_u8OCR_FASRPWMValue)
{
	OCR0=copy_u8OCR_FASRPWMValue;
}
