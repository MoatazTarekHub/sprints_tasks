/*
 * SPI_tst.c
 *
 *  Created on: Jul 25, 2021
 *      Author: Al Badr
 */


/*
 * SPI_tst.c
 *
 *  Created on: Jul 25, 2021
 *      Author: Al Badr
 */

#include <assert.h>
#include <stdio.h>
#include "../../lib/DataTypes.h"
#include "../../lib/BIT_Math.h"

uint8_t SPDR;
uint8_t SPSR;
uint8_t SPCR;


EN_ERRORSTATE_t  SPI_MasterInit(void){


	uint8_t SPCR_HELP=0;
		SETBIT(SPCR_HELP,6);//spi enable

		//SETBIT(SPCR_HELP,5);//lsb
		SETBIT(SPCR_HELP,4);//master
		//SETBIT(SPCR_HELP,3);//rising
		//SETBIT(SPCR_HELP,2);//setup then sample
		//clk f/4
		CLRBIT(SPCR_HELP,1);
		CLRBIT(SPCR_HELP,0);
		CLRBIT(SPSR,0);
	SPCR=SPCR_HELP;

return E_OK;


}

EN_ERRORSTATE_t SPI_SlaveInit(void){
	uint8_t SPCR_HELP=0;


			SETBIT(SPCR_HELP,6);//spi enable

				//SETBIT(SPCR_HELP,5);//lsb
				CLRBIT(SPCR_HELP,4);//slave
				CLRBIT(SPCR_HELP,3);//rising
				CLRBIT(SPCR_HELP,2);//setup then sample
				//clk f/4
				CLRBIT(SPCR_HELP,1);
				CLRBIT(SPCR_HELP,0);
				//CLRBIT(SPSR,0);

			SPCR=SPCR_HELP;
			return E_OK;

}


EN_ERRORSTATE_t SPI_MasterTransmit(uint8_t cData){
	SPDR = cData;

cData=SPDR;
return E_OK;
}


uint8_t SPI_SlaveReceive(void){

	return SPDR;

}


void spi_InitTest(void)
{
    assert(SPI_SlaveInit() == E_OK);
    assert(SPCR==64);

}


void spi_SendDataTest(void)
{
    assert(SPI_MasterTransmit('k')==E_OK);
}

void spi_ReceiveTest(void)
{
    assert(SPI_SlaveReceive()=='k');
}
void main()
{
    spi_InitTest();
    spi_SendDataTest();
    spi_ReceiveTest();
    printf("No Error");

}
