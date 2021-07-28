/*
 * I2C_tst.c
 *
 *  Created on: Jul 25, 2021
 *      Author: Al Badr
 */




#include <assert.h>
#include <stdio.h>
#include "../../lib/DataTypes.h"
#include "../../lib/BIT_Math.h"


uint8_t TWAR;
uint8_t TWCR;
uint8_t TWSR;
uint8_t TWBR;
uint8_t TWDR;

EN_ERRORSTATE_t I2C_MasterInit(void){

// prescaler =1
	CLRBIT(TWSR,0);
	CLRBIT(TWSR,1);
	TWBR=32;//400khz
	SETBIT(TWCR,6);// enable ACK

	SETBIT(TWCR,2);// enable

	TWAR=0b00000111;

return E_OK;
}
EN_ERRORSTATE_t I2C_MasterStart(void){

	SETBIT(TWCR,5);// enable start bit
	SETBIT(TWCR,7);// clear flag
	return E_OK;


}


void I2C_SlaveInit(void){
	TWBR=32;//400khz
		SETBIT(TWCR,6);// enable ack

		SETBIT(TWCR,2);// enable i2c

		TWAR=0b00000010;

}

void I2C_SendSlaveAddressWithWrite(uint8_t address){
	TWDR=(address<<1);
	/* Write operation */
		CLRBIT(TWDR,0);
			CLRBIT(TWCR,5);// clear start bit
			SETBIT(TWCR,7);// clear flag
			while(GETBIT(TWCR,7)==0);
}

void I2C_SendSlaveAddressWithRead(uint8_t address){
	TWDR=(address<<1);
	SETBIT(TWDR,0);// read

	CLRBIT(TWCR,5);// clear start bit
	SETBIT(TWCR,7);// clear flag
	while(GETBIT(TWCR,7)==0);
}

EN_ERRORSTATE_t I2C_WriteDataByte(uint8_t data){

TWDR=data;
SETBIT(TWCR,7);// clear flag
return E_OK;

}
uint8_t I2C_ReadDataByte(void){
	uint8_t value;
SETBIT(TWCR,7);// clear flag

value=TWDR;
return value;
}
EN_ERRORSTATE_t I2C_MasterStop(void){

	SETBIT(TWCR,4);// enable stop bit
	SETBIT(TWCR,7);// clear flag

return E_OK;
}


void I2C_InitTest(void)
{
    assert(I2C_MasterInit() == E_OK);
    assert(TWCR==68);
    assert(I2C_MasterStart() == E_OK);
    assert(TWCR == 228);
    assert(I2C_MasterStop() == E_OK);
    assert(TWCR == 244);

    assert(TWBR== 32);
}


void I2C_SendDataTest(void)
{
    assert(I2C_WriteDataByte('k')==E_OK);
}

void I2C_ReceiveTest(void)
{
    assert(I2C_ReadDataByte()=='k');
}
void main()
{
	I2C_InitTest();
	I2C_SendDataTest();
	I2C_ReceiveTest();
    printf("No Error");

}
