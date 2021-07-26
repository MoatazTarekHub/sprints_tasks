/*
 * key_pad.c
 *
 *  Created on: Dec 2, 2020
 *      Author: Moataz Tarek
 */



#include "DataTypes.h"
#include "DIO_Interface.h"
#include "KEYPAD_Interface.h"
#include <avr/delay.h>



uint8_t Read_Pin(void){
	//u8 col,row;
	uint8_t c=0;
	uint8_t pressed_default=0;
	uint8_t	keys [4][4]={
			{'/', 9, 8, 7 },
			{'*', 6, 5, 4 },
			{'-', 3, 2, 1 },
			{'+','=',0,0x0D}
	};
	while(1){
		for ( c=0;c<=3;c++){
			DIO_voidSetPinValue     (KEYPAD_PORT, c,LOW);
			for(uint8_t r=4 ;r<=7;r++){
				if (   DIO_u8GetPinValue (KEYPAD_PORT, r)==0){
					while ( DIO_u8GetPinValue (KEYPAD_PORT, r)==0);

					//_delay_ms(20);
					return pressed_default=keys[r-4][c];


				}
			}
			DIO_voidSetPinValue     (KEYPAD_PORT, c,HIGH);



			//_delay_ms(10);

		}

	}
}
void KeyPad_Init(void){
	DIO_voidSetPinDirection (KEYPAD_PORT,PIN0,OUTPUT );
	DIO_voidSetPinDirection (KEYPAD_PORT,PIN1,OUTPUT );
	DIO_voidSetPinDirection (KEYPAD_PORT,PIN2,OUTPUT );
	DIO_voidSetPinDirection (KEYPAD_PORT,PIN3,OUTPUT );
	DIO_voidSetPinDirection (KEYPAD_PORT,PIN4,INPUT );
	DIO_voidSetPinDirection (KEYPAD_PORT,PIN5,INPUT );
	DIO_voidSetPinDirection (KEYPAD_PORT,PIN6,INPUT);
	DIO_voidSetPinDirection (KEYPAD_PORT,PIN7,INPUT);


	DIO_voidSetPortValue    (KEYPAD_PORT, 0xff);


}






