/*
 * Timer0.h
 *
 *  Created on: Aug 20, 2023
 *      Author: yasmeen
 *       SWC:Timers
 *      Version:1.2
 */
#ifndef TIMERS_H
#define TIMERS_H

#define Timer0_OCR0              125

//to select the timer mode
#define Timer0_OVF_Mode              0
#define Timer0_CTC_Mode              1
#define Timer0_FastPWM_Mode          2
#define Timer0_PhaseCorrectPWM_Mode  3
//we could select which mode
#define Timer0_Mode_Select  Timer0_FastPWM_Mode
//-----------------------------------------------------------------------

//FOR PRESCALE SELECT
#define TIMER0_TIMER_OFF         0
#define TIMER0_NO_PRESCALE       1
#define TIMER0_PRESCALE_8        2
#define TIMER0_PRESCALE_64       3
#define TIMER0_PRESCALE_256      4
#define TIMER0_PRESCALE_1024     5

#define TIMER0_PRESCALE_Select  TIMER0_PRESCALE_8
//------------------------------------------------------------------------------------
void Timers_VidTimer0Init();
void Timer0_SETCallBack(void (*TIMER0_PTR)(void));
void Timer0_VidTimer0SetOCR_FASRPWM(u8 copy_u8OCR_FASRPWMValue);



#endif
