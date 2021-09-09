/*
 * RTOS_Interfacing.h
 *
 *  Created on: Jan 10, 2021
 *      Author: Al Badr
 */

#ifndef RTOS_INTERFACING_H_
#define RTOS_INTERFACING_H_




void RTOS_CreateTask(u16 Copy_periodicity,void (*ptr)(void), u8 periority, u8 task_del);
//void ISR_FUN(void(*copy_pfun)(void));
void RTOS_vidStart(void);
void RTOS_vidSchadular(void);
void RTOS_vidSuspendTask(u8 periority);
void RTOS_vidResumedTask(u8 periority);
void RTOS_vidKillTask(u8 periority);
#endif /* RTOS_INTERFACING_H_ */
