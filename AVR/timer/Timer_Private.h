/*
 * Timer_Private.h
 *
 *  Created on: Dec 15, 2020
 *      Author: Al Badr
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TCCR0 *((u8*)0x53)
#define TCNT0 *((u8*)0x52)
#define TIMSK *((u8*)0x59)
#define SREG   *((u8*)0x5F)
#define OCR0   	*((u8*)0x5C)



void __vector_11(void) __attribute__((signal));
void __vector_10(void) __attribute__((signal));

#endif /* TIMER_PRIVATE_H_ */
