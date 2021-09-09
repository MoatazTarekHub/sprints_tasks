/*
 * RTOS_Private.h
 *
 *  Created on: Jan 10, 2021
 *      Author: Al Badr
 */

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

//#define Null ((void*) 0)


typedef struct{
	u16 periodicity;
	void (*TaskFunction)(void);
	u8 state;
	u8 first_delay;

}Task_t;

#endif /* RTOS_PRIVATE_H_ */
