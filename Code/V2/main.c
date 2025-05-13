/*
 * main.c
 *
 *  Created on: Oct 15, 2024
 *      Author: yasmeen
 */

#include "Dc_Motors.h"
#include "ULTRASONIC.h"
#include"avr/delay.h"
#include"UART.h"
#include "Timer.h"
#include "avr/interrupt.h"
#include"IR.h"

void main(void)
{
	u8 x=0;
	u8 control = 0;
	u32 read ;

	//USART_VIDInit();
	Timers_VidTimer0Init();
	Dc_Motor_Init();
	ULSONIC_VIDInit();
	USART_VIDInit();
	IR_init();

	/*lED FOR TESTING*/
	//DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN3,DIO_OUTPUT);
	//DIO_VidSetPinValue(DIO_PORTA,DIO_PIN3,DIO_LOW);

	/*FOR UART INITILIZATION AS PIN0 INPUT FOR RECIVING & PIN1 FOR TRANSMITTING*/
	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN0,DIO_INPUT);
	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);


	DIO_VidSetPinDirection(DIO_PORTC,DIO_PIN6, DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTC,DIO_PIN7, DIO_OUTPUT);



	while(1)
	{
		/*READING DISTANCE FROM ULTRASONIC*/
		read =  ULSONIC_U32GetDistance();


    	if(read>=30)
    	{

    		DIO_VidSetPinValue(DIO_PORTC, DIO_PIN7, DIO_HIGH);
    		x=USART_U8RECIEVEChar();
    		if (x=='1' || x== '2')
    		{
    			control = x;
    		}
    		else{
  			  //DC_MOTOR_Stop();
    		}
    		_delay_ms(200);
    		if(control=='1')
    		{
    			//LCD_SEND_COMMAND(0x01);
    			DIO_VidSetPinValue(DIO_PORTC, DIO_PIN6, DIO_HIGH);
    			DC_MOTOR_MoveForward();
    			IR_MakeDecision();

    		}
    		else if (control== '2')
    		{
    		   DIO_VidSetPinValue(DIO_PORTC, DIO_PIN6, DIO_LOW);
			   //DC_MOTOR_Stop();
			  // _delay_ms(1000);
    		   //DC_MOTOR_MoveForwardRight();
    		   //IR_MakeDecision();
    		   DC_MOTOR_Stop();

    		}

    	}
    	else
    		{

    		DIO_VidSetPinValue(DIO_PORTC, DIO_PIN7, DIO_LOW);
            DC_MOTOR_Stop();
    		//DC_MOTOR_MoveForwardRight();

    		}


	}

}
