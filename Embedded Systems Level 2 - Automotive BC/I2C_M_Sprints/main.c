/*
 * main.c
 *
 *  Created on: Jul 16, 2021
 *      Author: Al Badr
 */



#include "DataTypes.h"
//#include "DIO_Interface.h"
#include <util/delay.h>
#include "I2C_Interface.h"


int main(void){
	uint8_t data;
	uint8_t value;
	I2C_MasterInit();

	I2C_MasterStart();

	I2C_SendSlaveAddressWithWrite(0b00000001);
	 I2C_WriteDataByte('a');
	  I2C_MasterStop();
	// _delay_ms(10);


//	value= I2C_ReadDataByte(data);

		while(1){
	}


}

