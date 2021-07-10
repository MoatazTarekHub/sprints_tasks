/*
 * Timer_Program.c
 *
 *  Created on: Dec 15, 2020
 *      Author: Al Badr
 */

#ifndef TIMER_PROGRAM_C_
#define TIMER_PROGRAM_C_


#include "std_type.h"
#include "bit_math.h"
#include "DIO_Interface.h"
#include "Timer_Private.h"
#include "Timer_Confige.h"

#include <avr/delay.h>
volatile u32 counter_ov;
volatile u8 preload;
void Timer0_Duty(u8 duty){
	OCR0=duty;
	//OCR0=(duty*256)/100;

}
void Timer0_Delay(u32 time){
#if Clock_Select ==   PRESCALER_8

float t_ov=(256*8.0)/(8);
counter_ov=time/t_ov;
preload=time%256;
#endif
}
void Timer0_Init(void){
	SET_BIT(SREG,7);// global inturbt enable
	/*  Select the Operation_Mode  */

	#if Operation_Mode == Normal_Mode
		CLR_BIT(TCCR0,6);
		CLR_BIT(TCCR0,3);
		// Overflow Interrupt
		//preload value
		TCNT0=preload;
		// enable over flow Interrupt mode for timer 0
		SET_BIT(TIMSK,0);
		// while using this mode don't forget the global Interrupt GIE


	#elif Operation_Mode == Phase_Correct_Mode
		CLR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
	#elif Operation_Mode == CTC_Mode

		CLR_BIT(TCCR0,6); // WGM00
		SET_BIT(TCCR0,3); // WGM01
		// Output Compare Match Interrupt Enable
		// while using this mode don't forget the global Interrupt GIE
		SET_BIT(TIMSK,1);
		/* CTC value*/
		OCR0 = OCR_VALUE ;

	#elif Operation_Mode ==	Fast_PWM_Mode
		SET_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);

	#endif


#if Operation_Mode == Phase_Correct_Mode
	#if WAVEFORM == NON_INVERTED_MODE
		CLEAR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	#elif  WAVEFORM == INVERTED_MODE
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	#elif  WAVEFORM  == OC0_DISCONNECTED
		CLEAR_BIT(TCCR0,4);
		CLEAR_BIT(TCCR0,5);

	#endif

#elif Operation_Mode == CTC_Mode
#if COMPARE_MODE_MATCH   == OC0_DISCONNECT
	CLEAR_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
#elif COMPARE_MODE_MATCH == OC0_SET
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif COMPARE_MODE_MATCH == OC0_TOGGLE
	SET_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
#elif COMPARE_MODE_MATCH   ==  OC0_ClEAR
	CLEAR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

#endif

#endif


	// normal mode
	//CLR_BIT(TCCR0,6);
	//CLR_BIT(TCCR0,3);
//CTC mode
	//SET_BIT(TCCR0,6);
	//CLR_BIT(TCCR0,3);
// fast pwm
	//SET_BIT(TCCR0,6);
	//SET_BIT(TCCR0,3);
///////////////////////
//normal
	//CLR_BIT(TCCR0,5);
	//CLR_BIT(TCCR0,4);
//Clear OC0 on compare match, set OC0 at TOP
	//SET_BIT(TCCR0,5);
	//CLR_BIT(TCCR0,4);


	/*   Select the clock source    */
#if Clock_Select ==   NO_CLOCK_SOURCE

	CLR_BIT(TCCR0,0); // CS00
	CLR_BIT(TCCR0,1); // CS01
	CLR_BIT(TCCR0,2); // CS02

#elif Clock_Select ==   PRESCALER_NO
	SET_BIT(TCCR0,0); // CS00
	CLR_BIT(TCCR0,1); // CS01
	CLR_BIT(TCCR0,2); // CS02

#elif Clock_Select ==   PRESCALER_8
	CLR_BIT(TCCR0,0); // CS00
	SET_BIT(TCCR0,1); // CS01
	CLR_BIT(TCCR0,2); // CS02

#elif Clock_Select ==   PRESCALER_64
	SET_BIT(TCCR0,0); // CS00
	SET_BIT(TCCR0,1); // CS01
	CLR_BIT(TCCR0,2); // CS02

#elif Clock_Select ==   PRESCALER_265
	CLR_BIT(TCCR0,0); // CS00
	CLR_BIT(TCCR0,1); // CS01
	SET_BIT(TCCR0,2); // CS02

#elif Clock_Select ==   PRESCALER_1024
	SET_BIT(TCCR0,0); // CS00
	CLR_BIT(TCCR0,1); // CS01
	SET_BIT(TCCR0,2); // CS02
#endif




//overflow mode
	//CLR_BIT(TIMSK,1);
	//SET_BIT(TIMSK,0);
//compare mode
	//SET_BIT(TIMSK,1);
	//CLR_BIT(TIMSK,0);
//preload value
	// TCNT0=0xf7;
	 //OCR0=200;
}
#if Operation_Mode == Normal_Mode

void __vector_11(void){
	static u32 counter=0;

	counter++;
 if(counter == counter_ov){
	 TCNT0=preload;
	 DIO_VidTogglePin(DIO_PORTA,DIO_PIN0);
	 counter=0;

 }

}

/*
void __vector_10(void){

	 DIO_VidTogglePin(DIO_PORTA,DIO_PIN0);
 }*/
#elif Operation_Mode == CTC_Mode

void __vector_10(void){
	static u32 counter=0;

	counter++;
	if(2500==counter){
		 DIO_VidTogglePin(DIO_PORTA,DIO_PIN0);
		 	 counter=0;
	}
}

#endif
#endif /* TIMER_PROGRAM_C_ */
