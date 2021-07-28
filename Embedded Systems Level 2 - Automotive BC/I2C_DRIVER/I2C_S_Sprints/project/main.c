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


int main(void){
	uint8_t data[100];
	uint8_t value;
	I2C_SlaveInit();

	//DIO_voidSetPortDirection(PORT_A,0xff);
	//DIO_voidSetPortDirection(PORT_B,0xff);
	//I2C_MasterStart();

	//I2C_SendSlaveAddressWithWrite(0b00000010);
	 //I2C_WriteDataByte('a');
	  //I2C_MasterStop();

	//I2C_ReadDataByte();
	// _delay_ms(10);
value= I2C_ReadDataByte();
DIO_voidSetPortValue(PORT_A,value);
DIO_voidSetPortValue(PORT_B,0xff);
		while(1){
	}


}

