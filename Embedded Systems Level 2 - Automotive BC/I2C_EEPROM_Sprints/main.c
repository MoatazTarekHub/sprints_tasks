/*
 * main.c
 *
 *  Created on: Jul 16, 2021
 *      Author: Al Badr
 */



#include "DataTypes.h"
#include "DIO_Interface.h"
#include <util/delay.h>
#include "I2C_Interface.h"
#include  "Uart_Interface.h"
	uint8_t add[100];

	uint8_t check(uint8_t *str,uint8_t address);

uint8_t change_stringToBin(uint8_t*str);
void eeprom_recieve_string(uint8_t *str);
void eeprom_send_string(uint8_t *str);

int main(void){
	uint8_t data[100];

	uint8_t value;
	I2C_MasterInit();

		UART_Init(9600);



		while(1){

			UART_Transmite_String("\r\n you want write or read operation");
			 UART_Recive_String(data);
				UART_Transmite_String("\r\n enter the address ");
				 UART_Recive_String(add);
				value= change_stringToBin(add);
			value=check(data,value);

	}


}



uint8_t check(uint8_t *str,uint8_t address){
	uint8_t value;

	if(str[0]=='w'){
		UART_Transmite_String("\r\n you want write operation");


		eeprom_send_string("11234");
	}
	else if(str[0]=='r'){
		UART_Transmite_String("\r\n you want  read operation");

		eeprom_recieve_string(add);

	}

return value;
}
void eeprom_send_string(uint8_t *str){


	uint8_t i=0,value;
				I2C_MasterStart();
				I2C_SendSlaveAddressWithWrite(0b01010000);
				I2C_WriteDataByte(0b00000001);
			    while (str[i] != '\0')
			    {
			    	I2C_WriteDataByte(str[i] - '0');
			        i++;
			    }
				 I2C_MasterStop();

}
void eeprom_recieve_string(uint8_t *str){

	uint8_t i=0,value;
				I2C_MasterStart();
				I2C_SendSlaveAddressWithWrite(0b01010000);
				I2C_WriteDataByte(0b00000001);

			while(i != 4){
				I2C_MasterStart();
				I2C_SendSlaveAddressWithRead(0b01010000);
				 value= I2C_ReadDataByte();
				UART_Transmite_String("\r");


				 I2C_MasterStop();
				UART_Transmite(value);
					i++;
			}



}

uint8_t change_stringToBin(uint8_t*str){
	uint32_t num=0;
	uint32_t bin=0;
	uint8_t temp=0;
	uint8_t weight=1;

	for (uint8_t i = 0 ; i<8 ; i++)
	    {
		num = num * 10 + str[i] - '0';
	    }


	while(num>0){
		temp=num%10;
		num=num/10;
		bin=bin+temp*weight;
		weight*=2;
	}
return bin;
}
