/*
 *  Author: Moataz
 *  Created on: 17/2/2021
 */
#ifndef DIO_PROGRAM_H_
#define DIO_PROGRAM_H_

#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"
#include "DIO_priv.h"

void DIO_voidInit(ST_DIO_config_t *Port)
{for (int i =0;i<4;i++){
    if (INPUT == Port[i].Direction)
    {
        switch (Port[i].portname)
        {
        case PORTA_ID:
            CLRBIT(DDRA, Port[i].pin_no);
            break;
        case PORTB_ID:
            CLRBIT(DDRB, Port[i].pin_no);
            break;
        case PORTC_ID:
            CLRBIT(DDRC, Port[i].pin_no);

            break;
        case PORTD_ID:
            CLRBIT(DDRD, Port[i].pin_no);
            break;

        default:
            break;
        }
    }

    else if (OUTPUT == Port[i].Direction)
    {
        switch (Port[i].portname)
        {
        case PORTA_ID:
            SETBIT(DDRA, Port[i].pin_no);
            break;
        case PORTB_ID:
            SETBIT(DDRB, Port[i].pin_no);
            break;
        case PORTC_ID:
            SETBIT(DDRC, Port[i].pin_no);
            break;
        case PORTD_ID:
            SETBIT(DDRD, Port[i].pin_no);
            break;

        default:
            break;
        }
    }
    if (LOW == Port[i].state)
    {
        switch (Port[i].portname)
        {
        case PORTA_ID:
            CLRBIT(PORTA, Port[i].pin_no);
            break;
        case PORTB_ID:
            CLRBIT(PORTB, Port[i].pin_no);
            break;
        case PORTC_ID:
            CLRBIT(PORTC, Port[i].pin_no);

            break;
        case PORTD_ID:
            CLRBIT(PORTD, Port[i].pin_no);
            break;

        default:
            break;
        }
    }
    else if (HIGH == Port[i].state)
    {
        switch (Port[i].portname)
        {
        case PORTA_ID:
            SETBIT(PORTA, Port[i].pin_no);
            break;
        case PORTB_ID:
            SETBIT(PORTB, Port[i].pin_no);
            break;
        case PORTC_ID:
            SETBIT(PORTC, Port[i].pin_no);
            break;
        case PORTD_ID:
            SETBIT(PORTD, Port[i].pin_no);
            break;

        default:
            break;
        }
    }
}
}
void DIO_voidSetPinValue(ST_DIO_config_t *Port){


	   if (LOW == Port->state)
	    {
	        switch (Port->portname)
	        {
	        case PORTA_ID:
	            CLRBIT(PORTA, Port->pin_no);
	            break;
	        case PORTB_ID:
	            CLRBIT(PORTB, Port->pin_no);
	            break;
	        case PORTC_ID:
	            CLRBIT(PORTC, Port->pin_no);

	            break;
	        case PORTD_ID:
	            CLRBIT(PORTD, Port->pin_no);
	            break;

	        default:
	            break;
	        }
	    }
	    else if (HIGH == Port->state)
	    {
	        switch (Port->portname)
	        {
	        case PORTA_ID:
	            SETBIT(PORTA, Port->pin_no);
	            break;
	        case PORTB_ID:
	            SETBIT(PORTB, Port->pin_no);
	            break;
	        case PORTC_ID:
	            SETBIT(PORTC, Port->pin_no);
	            break;
	        case PORTD_ID:
	            SETBIT(PORTD, Port->pin_no);
	            break;

	        default:
	            break;
	        }
	    }


}
void DIO_write(EN_portname_t port,EN_pinnum_t pin, EN_initValue_t data){
	  if (LOW == data)
		    {
		        switch (port)
		        {
		        case PORTA_ID:
		            CLRBIT(PORTA, pin);
		            break;
		        case PORTB_ID:
		            CLRBIT(PORTB,pin);
		            break;
		        case PORTC_ID:
		            CLRBIT(PORTC, pin);

		            break;
		        case PORTD_ID:
		            CLRBIT(PORTD, pin);
		            break;

		        default:
		            break;
		        }
		    }
		    else if (HIGH == data)
		    {
		        switch (port)
		        {
		        case PORTA_ID:
		            SETBIT(PORTA, pin);
		            break;
		        case PORTB_ID:
		            SETBIT(PORTB, pin);
		            break;
		        case PORTC_ID:
		            SETBIT(PORTC, pin);
		            break;
		        case PORTD_ID:
		            SETBIT(PORTD, pin);
		            break;

		        default:
		            break;
		        }
		    }

}
int DIO_read(EN_portname_t port,EN_pinnum_t pin)
{	int data;
		switch(port){

			 case PORTA_ID:
				 data=GETBIT( PINA , pin );
			 break;
			 case PORTB_ID:
				 data=GETBIT( PINB, pin );
			 break;
			 case PORTC_ID:
				 data=GETBIT( PINC, pin );
			  break;
			 case PORTD_ID:
				 data= GETBIT( PIND, pin );
			  break;
			}
		return data;
}
void DIO_toggle(EN_portname_t port,EN_pinnum_t pin){


	switch(port){

			 case PORTA_ID:
				 TGLBIT(PORTA, pin );
			 break;
			 case PORTB_ID:
				 TGLBIT( PORTB, pin );
			 break;
			 case PORTC_ID:
				 TGLBIT( PORTC, pin );
			  break;
			 case PORTD_ID:
				 TGLBIT( PORTD, pin );
			  break;
			}




}

#endif
