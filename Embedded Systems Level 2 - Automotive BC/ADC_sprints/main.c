/*
 * main.c
 *
 *  Created on: Jul 19, 2021
 *      Author: Al Badr
 */
#include "DataTypes.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "LM_35_Interface.h"
#include "KEYPAD_Interface.h"
#include <avr/delay.h>



uint8_t compare(uint8_t temp,uint8_t *str);

int main(){
	uint8_t temp =0,num;
	uint8_t value[2] ={0};

	LCD_VidInit();
	LM35_VoidInit();
	KeyPad_Init();
	DIO_voidSetPinDirection(PORT_A,PIN2,OUTPUT);

	value[0]=Read_Pin();
	LCD_IntegerToString(value[0]);
	value[1]=Read_Pin();
	LCD_IntegerToString(value[1]);


	_delay_ms(1000);

	LCD_VidDisplayStringRow(0,0,"temp is ");
	while(1){


		temp = LM35_U16Read(0);
		_delay_ms(1000);
		LCD_IntegerToString(temp);
		_delay_ms(2000);
		if(compare(temp,value)){

			DIO_voidSetPinValue(PORT_A,PIN2,HIGH);
			LCD_VidDisplayStringRow(1,0,"FAN on ");
		}else{

			DIO_voidSetPinValue(PORT_A,PIN2,LOW);
			LCD_VidDisplayStringRow(1,0,"FAN off ");

		}



	}
}
uint8_t compare(uint8_t temp,uint8_t *str){
	uint8_t num;
	num=(str[0]*10)+(str[1]);
	LCD_VidClearScreen();
	LCD_IntegerToString(num);
	if (num>temp){
		return 0;

	}
	else{
		return 1;
	}


}
