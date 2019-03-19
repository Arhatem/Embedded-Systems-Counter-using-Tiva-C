#include "Increment.h"

void delay_func( unsigned long  time);
unsigned long delay_1;
unsigned long num_1 , num_2 , num_3 ;
void Increment(void){
	delay_1 = 320000 ;
	delay_func(delay_1); //due to switch debouncing 
	if(DIO_ReadPort(0,0x04) ) // BUTTON D0 PRESSED ?
	{
		delay_1 = 3200000 ; 
		delay_func(delay_1);

		if(DIO_ReadPort(0,0x04))
		{

			if( ( DIO_ReadPort(4,0x0F) == 9 ) && ( DIO_ReadPort(1,0x0F) != 9 ) && ( DIO_ReadPort(3,0x0F)!= 9 )  )	//**9
			{
				delay_func(delay_1) ; // Delay 0.2 seconds 
				num_1 = 0 ; 
				GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ;
				num_2++ ; 
				GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xF0 ) | (num_2 & 0x0F ) ;
			}
			else if( ( DIO_ReadPort(4,0x0F)  == 9 ) && ( DIO_ReadPort(1,0x0F) == 9 ) && ( DIO_ReadPort(3,0x0F)!= 9 )  ) //*99
			{
				delay_func(delay_1) ; // Delay 0.2 seconds 
				num_1 = 0 ; 
				GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ;
				num_2 = 0 ; 
				GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xF0 ) | (num_2 & 0x0F ) ;
				num_3++ ;
				GPIO_PORTD_DATA_R = ( GPIO_PORTD_DATA_R & 0xF0 ) | (num_3 & 0x0F ) ;

			}
			else if( ( DIO_ReadPort(4,0x0F) == 9 ) && ( DIO_ReadPort(1,0x0F) == 9 ) && ( DIO_ReadPort(3,0x0F)== 9 )  ) //999
			{
				// do nothing 
			}
			else if( (  DIO_ReadPort(4,0x0F)   == 9 ) && (  DIO_ReadPort(1,0x0F) != 9 ) && ( DIO_ReadPort(3,0x0F)== 9 )  ) //9*9
			{
				delay_func(delay_1) ; // Delay 0.2 seconds 
				num_1 = 0 ; 
				GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ;
				num_2++ ; 
				GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xF0 ) | (num_2 & 0x0F ) ;

			}
			else //any number for ex : 576 
			{
				delay_func(delay_1) ; // Delay 0.2 seconds 
				num_1++ ; 
				GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ; 

			}

		}

	}
}
