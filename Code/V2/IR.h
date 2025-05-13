/*
 * IR.h
 *
 *  Created on: Oct 16, 2024
 *      Author: yasmeen
 */

#ifndef IR_H_
#define IR_H_

#define IR1_PIN  DIO_PIN3
#define IR1_PORT DIO_PORTA

#define IR2_PIN  DIO_PIN4
#define IR2_PORT DIO_PORTA


void IR_init();
u8 IR1_read();
u8 IR2_read();
void IR_MakeDecision();

#endif /* IR_H_ */
