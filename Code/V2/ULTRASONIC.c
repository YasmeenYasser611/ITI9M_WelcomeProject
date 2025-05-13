/*
 * ULTRASONIC.c
 *
 *  Created on: Sep 5, 2023
 *      Author: dell
 */
#include "avr/io.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "avr/interrupt.h"
#include "Util/delay.h"
#include "ULTRASONIC.h"

u32 TimerOverflow = 0;

ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count */
}

void ULSONIC_VIDInit()
{
	DIO_VidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
	DIO_VidSetPinValue(DIO_PORTD,DIO_PIN6, DIO_OUTPUT);
	sei();			            /* Enable global interrupt */
	SET_BIT(TIMSK, TOIE1);  	/* Enable Timer1 overflow interrupts */
	TCCR1A = 0;		            /* Set all bit to zero Normal operation */
}

u32 ULSONIC_U32GetDistance()
{
	u32 distance ;
	u32 count;
	/* Give 10us trigger pulse on trig. pin to HC-SR04 */
	SET_BIT(PORTA,TRIG_PIN);
	_delay_us(10);
	CLR_BIT(PORTA, TRIG_PIN);

	TCNT1 = 0;	/* Clear Timer counter */
	SET_BIT(TIFR,ICF1);	/* Clear ICP flag (Input Capture flag) */
	SET_BIT(TIFR,TOV1);	/* Clear Timer Overflow flag */
	TCCR1B = 0x41;	/* Capture on rising edge, No prescaler*/


	/*Calculate width of Echo by Input Capture (ICP) */

	while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */
	TCNT1 = 0;	/* Clear Timer counter */
	SET_BIT(TIFR,ICF1);	/* Clear ICP flag (Input Capture flag) */
	SET_BIT(TIFR,TOV1);	/* Clear Timer Overflow flag */
	TimerOverflow = 0;/* Clear Timer overflow count */
	TCCR1B = 0x01;	/* Capture on falling edge, No prescaler */

	while ((TIFR & (1 << ICF1)) == 0);/* Wait for falling edge */
	count = ICR1 + (65535 * TimerOverflow);	/* Take count */
	/* 8MHz Timer freq, sound speed =343 m/s */
	distance = (double)count / 466.47;
	distance++;
	return distance;

}
