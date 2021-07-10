/*
 * main.c

 *
 *  Created on: Dec 15, 2020
 *      Author: Al Badr
 */


/*
 * main.c
 *
 *  Created on: Dec 6, 2020
 *      Author: Moataz Tarek
 */
#include "std_type.h"
#include "DIO_Interface.h"
#include "Timer_Interface.h"
#include <util/delay.h>

int main(void){

	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);// led
	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN4,DIO_OUTPUT);// led
	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);// led
	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);// led

	Timer0_Init();
	//DIO_VidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);// led

	while(1){
		//DIO_VidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_HIGH);// led
		 Timer0_Delay(500000);

		//Timer0_Duty(64);
		//_delay_ms(1000);
		//Timer0_Duty(128);
		//_delay_ms(1000);


		//DIO_VidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_HIGH);// led

	}

}




