/*
 * Dc_Motors.h
 *
 *  Created on: Oct 15, 2024
 *      Author: yasmeen
 */

#ifndef DC_MOTORS_H_
#define DC_MOTORS_H_

#include"DIO.h"
#include "Timer.h"

/*CONNECTION FOR MOTOR1 AND MOTOR4*/
#define IN1_PIN DIO_PIN0
#define IN2_PIN DIO_PIN1

/*CONNECTION FOR MOTOR1 AND MOTOR4 Enabble*/
#define ENA_PIN DIO_PIN3

/*CONNECTION FOR MOTOR2 AND MOTOR3*/
#define IN3_PIN DIO_PIN2
#define IN4_PIN DIO_PIN4

/*CONNECTION FOR MOTOR2 AND MOTOR3 Enabble*/
#define ENB_PIN DIO_PIN3


#define  DC_MOTOR_PORT      DIO_PORTB

/*functions*/
void Dc_Motor_Init();
void DC_MOTOR_MoveForward();
void DC_MOTOR_Movebackward();
void DC_MOTOR_MoveForwardRight();
void DC_MOTOR_MoveForwardLeft();
void DC_MOTOR_MovebackwardRight();
void DC_MOTOR_MovebackwardLeft();
void DC_MOTOR_Stop();

#endif /* DC_MOTORS_H_ */
