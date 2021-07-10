/*
 * Timer_Confige.h
 *
 *  Created on: Dec 19, 2020
 *      Author: Al Badr
 */

#ifndef TIMER_CONFIGE_H_
#define TIMER_CONFIGE_H_

#define Normal_Mode    		 		0
#define Phase_Correct_Mode    		1
#define CTC_Mode  					2
#define Fast_PWM_Mode   		 	3


#define Operation_Mode 			Normal_Mode
#if Operation_Mode == Normal_Mode
#define PRELOAD_VALUE				 192
#endif

#if Operation_Mode == CTC_Mode
#define OCR_VALUE     				200
#endif


#define NO_CLOCK_SOURCE			0
#define PRESCALER_NO			1
#define PRESCALER_8				2
#define PRESCALER_64			3
#define PRESCALER_256			4
#define PRESCALER_1024			5

#define Clock_Select   PRESCALER_8

/*compare match modes*/
#define OC0_DISCONNECT    1
#define OC0_TOGGLE        2
#define OC0_ClEAR         3
#define OC0_SET           4

#define COMPARE_MODE_MATCH        OC0_DISCONNECT

/*compare output mode, fast PWM mode */
#define OC0_DISCONNECTED    1
#define NON_INVERTED_MODE   2
#define INVERTED_MODE       3

#define WAVEFORM      INVERTED_MODE

#endif /* TIMER_CONFIGE_H_ */
