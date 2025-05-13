/*
 * DC_Motors.c
 *
 *  Created on: Oct 15, 2024
 *      Author: yasmeen
 */

#include"Dc_Motors.h"
#include"DIO.h"
void Dc_Motor_Init()
{

	//DIO_VidSetPortDirection(DC_MOTOR_PORT , DIO_ALL_OUTPUT);
	DIO_VidSetPinDirection(DC_MOTOR_PORT,ENA_PIN, DIO_OUTPUT );

	DIO_VidSetPinDirection(DC_MOTOR_PORT,IN1_PIN, DIO_OUTPUT );
	DIO_VidSetPinDirection(DC_MOTOR_PORT,IN2_PIN, DIO_OUTPUT );
	DIO_VidSetPinDirection(DC_MOTOR_PORT,IN3_PIN, DIO_OUTPUT );
	DIO_VidSetPinDirection(DC_MOTOR_PORT,IN4_PIN, DIO_OUTPUT );

}
void DC_MOTOR_MoveForward()
{
	//DIO_VidSetPinValue(DC_MOTOR_PORT,ENA_PIN , DIO_HIGH );
	//DIO_VidSetPinValue(DC_MOTOR_PORT,ENB_PIN , DIO_HIGH );
	Timer0_VidTimer0SetOCR_FASRPWM(Timer0_OCR0);

	DIO_VidSetPinValue(DC_MOTOR_PORT,IN1_PIN , DIO_HIGH );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN2_PIN , DIO_LOW );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN3_PIN , DIO_HIGH );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN4_PIN , DIO_LOW );

}
void DC_MOTOR_Movebackward()
{
	//DIO_VidSetPinValue(DC_MOTOR_PORT,ENA_PIN , DIO_HIGH );
	//DIO_VidSetPinValue(DC_MOTOR_PORT,ENB_PIN , DIO_HIGH );
	Timer0_VidTimer0SetOCR_FASRPWM(Timer0_OCR0);

	DIO_VidSetPinValue(DC_MOTOR_PORT,IN1_PIN , DIO_LOW );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN2_PIN , DIO_HIGH );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN3_PIN , DIO_LOW );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN4_PIN , DIO_HIGH );


}
void DC_MOTOR_MoveForwardRight()
{
	//DIO_VidSetPinValue(DC_MOTOR_PORT,ENA_PIN , DIO_HIGH );
	//DIO_VidSetPinValue(DC_MOTOR_PORT,ENB_PIN , DIO_HIGH );
	Timer0_VidTimer0SetOCR_FASRPWM(Timer0_OCR0);

	DIO_VidSetPinValue(DC_MOTOR_PORT,IN1_PIN , DIO_HIGH );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN2_PIN , DIO_LOW );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN3_PIN , DIO_LOW );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN4_PIN , DIO_HIGH );



}
void DC_MOTOR_MoveForwardLeft()
{
	//DIO_VidSetPinValue(DC_MOTOR_PORT,ENA_PIN , DIO_HIGH );
	//DIO_VidSetPinValue(DC_MOTOR_PORT,ENB_PIN , DIO_HIGH );
	Timer0_VidTimer0SetOCR_FASRPWM(Timer0_OCR0);

	DIO_VidSetPinValue(DC_MOTOR_PORT,IN1_PIN , DIO_LOW );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN2_PIN , DIO_HIGH);
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN3_PIN , DIO_HIGH );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN4_PIN , DIO_LOW );


}
void DC_MOTOR_MovebackwardRight()
{
	//DIO_VidSetPinValue(DC_MOTOR_PORT,ENA_PIN , DIO_HIGH );
	//DIO_VidSetPinValue(DC_MOTOR_PORT,ENB_PIN , DIO_HIGH );
	Timer0_VidTimer0SetOCR_FASRPWM(Timer0_OCR0);

	DIO_VidSetPinValue(DC_MOTOR_PORT,IN1_PIN , DIO_LOW );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN2_PIN , DIO_HIGH);
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN3_PIN , DIO_HIGH );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN4_PIN , DIO_LOW );


}
void DC_MOTOR_MovebackwardLeft()
{
	//DIO_VidSetPinValue(DC_MOTOR_PORT,ENA_PIN , DIO_HIGH );
	//DIO_VidSetPinValue(DC_MOTOR_PORT,ENB_PIN , DIO_HIGH );
	Timer0_VidTimer0SetOCR_FASRPWM(Timer0_OCR0);

	DIO_VidSetPinValue(DC_MOTOR_PORT,IN1_PIN , DIO_HIGH);
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN2_PIN , DIO_LOW);
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN3_PIN , DIO_LOW );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN4_PIN , DIO_HIGH);

}
void DC_MOTOR_Stop()
{
	//DIO_VidSetPinValue(DC_MOTOR_PORT,ENA_PIN , DIO_LOW );
	//DIO_VidSetPinValue(DC_MOTOR_PORT,ENB_PIN , DIO_LOW );
	Timer0_VidTimer0SetOCR_FASRPWM(Timer0_OCR0);

	DIO_VidSetPinValue(DC_MOTOR_PORT,IN1_PIN , DIO_LOW );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN2_PIN , DIO_LOW );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN3_PIN , DIO_LOW );
	DIO_VidSetPinValue(DC_MOTOR_PORT,IN4_PIN , DIO_LOW );

}
