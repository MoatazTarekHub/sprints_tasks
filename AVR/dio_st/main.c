
#include "DIO_Interface.h"
#include "util/delay.h"

int main()
{
   // ST_DIO_config_t DIO_1;
   // ST_DIO_config_t DIO_2;
    ST_DIO_config_t dio[4]={{PORTB_ID,PIN0,OUTPUT,LOW},{PORTA_ID,PIN2,OUTPUT,LOW},{PORTB_ID,PIN3,OUTPUT,HIGH},{PORTA_ID,PIN0,INPUT,HIGH}};


    DIO_voidInit(dio);
    //dio[0].state = HIGH;
    //DIO_voidInit(dio);

    //DIO_voidSetPinValue(dio);
    DIO_write(PORTB_ID,PIN0,HIGH);
    DIO_write(PORTB_ID,PIN3,LOW);


    int data;
    while(1){

    	while(DIO_read(PORTA_ID,PIN0)!=0){

    	}
    	DIO_toggle(PORTB_ID,PIN3);
    	_delay_ms(500);

    }
}
