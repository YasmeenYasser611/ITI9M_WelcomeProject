/*
 * IR.c
 *
 *  Created on: Oct 16, 2024
 *      Author: yasmeen
 */
#include"DIO.h"
#include"IR.h"
#include "Dc_Motors.h"
#include"avr/delay.h"
//#include"LCD.h"

void IR_init()
{

	DIO_VidSetPinDirection(IR1_PORT,IR1_PIN,DIO_INPUT);
	DIO_VidSetPinValue(IR1_PORT,IR1_PIN,DIO_HIGH);

	DIO_VidSetPinDirection(IR2_PORT,IR2_PIN,DIO_INPUT);
	DIO_VidSetPinValue(IR2_PORT,IR2_PIN,DIO_HIGH);

}

u8 IR1_read()
{
	u8 read;
	read=DIO_U8Get_PinValue(IR1_PORT,IR1_PIN);
	return read;
}

u8 IR2_read()
{
	u8 read;
	read=DIO_U8Get_PinValue(IR2_PORT,IR2_PIN);
	return read;
}

void IR_MakeDecision()
{
	u8 left = IR1_read();
	u8 right = IR2_read();
	//let 0 is black(line) , 1 is white
	if(left ==1 && right ==1) // 2 ir see white so go forward
	{
		//LCD_SEND_COMMAND(0x01);
		//LCD_VidSendStrig("move forword");
		DC_MOTOR_MoveForward();
		//DC_MOTOR_Stop();

	}
	else if(left ==1 && right ==0) // the right ir see black(line) so car must move forward right
	{
		//DC_MOTOR_Stop();
		//_delay_ms(100);
		DC_MOTOR_MoveForwardRight();
		//LCD_SEND_COMMAND(0x01);
		//LCD_VidSendStrig("move forword Right");
		_delay_ms(100);
		//IR_MakeDecision();
		//DC_MOTOR_MoveForward();


	}
	else if(left ==0 && right ==1) //the left see the line so car move forward left
	{
		//DC_MOTOR_Stop();
		//_delay_ms(100);
		DC_MOTOR_MoveForwardLeft();
		//LCD_SEND_COMMAND(0x01);
		//LCD_VidSendStrig("move forword left");
		_delay_ms(100);
		//IR_MakeDecision();
		//DC_MOTOR_MoveForward();
	}
	else
	{
		DC_MOTOR_MoveForward();
		//DC_MOTOR_Stop();
	}

}
