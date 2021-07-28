/*
 * App.c
 *
 *  Created on: Jul 22, 2021
 *      Author: Al Badr
 */
#include "Uart_Interface.h"
#include "DIO/DIO_Interface.h"
#include <util/delay.h>

	 uint8_t recive[100];

void check(uint8_t *str){
	int index=-1;
	uint8_t states[4][10]={"start","wait","stop","at"};
	for (int i=0;i<4;i++){
		for(int j=0;j<10;j++){
			if(str[j]!=states[i][j]){

				break;
			}

			if (str[j]=='\0'){
				index=i;

			}
		}
	}
	if(index==-1){
			UART_Transmite_String("\r\n error  state ");

		 }

	else if(index==0){
		UART_Transmite_String("\r\n green led on");
		 DIO_voidSetPinValue(PORT_A,PIN0,HIGH);
		 DIO_voidSetPinValue(PORT_A,PIN1,LOW);
		 DIO_voidSetPinValue(PORT_A,PIN2,LOW);

	 }

	 else if(index==1){
		UART_Transmite_String("\r\n Yellow led on");
		 DIO_voidSetPinValue(PORT_A,PIN1,HIGH);
		 DIO_voidSetPinValue(PORT_A,PIN0,LOW);
		 DIO_voidSetPinValue(PORT_A,PIN2,LOW);

			 }
	 else if(index==2){
		UART_Transmite_String("\r\n red led on");
		 DIO_voidSetPinValue(PORT_A,PIN2,HIGH);
		 DIO_voidSetPinValue(PORT_A,PIN1,LOW);
		 DIO_voidSetPinValue(PORT_A,PIN0,LOW);

			 }
	 else if(index==3){
		UART_Transmite_String("\r\n OK");

			 }

}



void App_Init(void){
	 UART_Init(9600);
	 UART_Recive_String(recive);

	 UART_Transmite_String(recive);
	 DIO_voidSetPinDirection(PORT_A,PIN0,OUTPUT);
	 DIO_voidSetPinDirection(PORT_A,PIN1,OUTPUT);
	 DIO_voidSetPinDirection(PORT_A,PIN2,OUTPUT);
	 	_delay_ms(1000);

	 UART_Transmite_String("\r\n done");

}
void App_Check(void){
	 UART_Transmite_String("\r\n start, wait , stop,at");

	 UART_Recive_String(recive);
	 check(recive);

}









