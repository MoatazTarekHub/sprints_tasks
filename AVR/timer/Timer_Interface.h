/*
 * Timer_Interface.h
 *
 *  Created on: Dec 15, 2020
 *      Author: Al Badr
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void Timer0_Init(void);

void Timer0_Duty(u8 duty);

void Timer0_Delay(u32 time);

#endif /* TIMER_INTERFACE_H_ */
