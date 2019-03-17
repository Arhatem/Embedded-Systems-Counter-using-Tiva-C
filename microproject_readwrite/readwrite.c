#include "tm4c123gh6pm.h"
#include "MC_header.h"


				uint8 pins_level;
				
	

uint8 DIO_ReadPort(uint8 port_index,uint8 pins_mask)
			{
				
				uint8 x=0;
				
				
				switch(port_index)
				{
					case 0:
						x= GPIO_PORTA_DATA_R|pins_mask;
					
					case 1:
						x=GPIO_PORTB_DATA_R|pins_mask;
					
					case 2:
						x=GPIO_PORTC_DATA_R|pins_mask;
					
					case 3:
						x=GPIO_PORTD_DATA_R|pins_mask;
					
					case 4:
						x=GPIO_PORTE_DATA_R|pins_mask;
					
					case 5:
						x=GPIO_PORTF_DATA_R|pins_mask;
					
			
				}
				
				pins_level=x;
				return pins_level;
				
				
			}
			

			void DIO_WritePort(uint8 port_index,uint8 pins_mask,enum Dio_LevelType pins_level )
			{
			switch(port_index)
				{
					case 0:
						if(pins_level)
							{
								GPIO_PORTA_DATA_R |=pins_mask;
							}
						else
							{
								GPIO_PORTA_DATA_R &=~pins_mask;
							}
					case 1:
						if(pins_level)
							{
								GPIO_PORTB_DATA_R |=pins_mask;

							}
						else
							{
								GPIO_PORTB_DATA_R &=~pins_mask;
							}
						
					case 2:
						if(pins_level)
							{
								GPIO_PORTC_DATA_R |=pins_mask;
								
							}
						else
							{
								GPIO_PORTC_DATA_R &=~pins_mask;
							}
					
					case 3:
						if(pins_level)
							{
								GPIO_PORTD_DATA_R |=pins_mask;
							}
						else
							{
								GPIO_PORTD_DATA_R &=~pins_mask;
							}
					case 4:
						if(pins_level)
							{
								GPIO_PORTE_DATA_R |=pins_mask;
							}
						else
							{
								GPIO_PORTE_DATA_R &=~pins_mask;
							}
					case 5:
						if(pins_level)
							{
								GPIO_PORTF_DATA_R |=pins_mask;
							}
						else
							{
								GPIO_PORTE_DATA_R &=~pins_mask;
							}
			
				}
			}
			
