#include "Port_Init.h"
#include "DIO_ReadPort.h"
uint8 DIO_ReadPort(uint8 port_index,uint8 pins_mask)
{
				
				uint8 x=0;
				
				
				switch(port_index)
				{
					case 0:
						x= GPIO_PORTA_DATA_R&pins_mask;
					break;
					
					case 1:
						x=GPIO_PORTB_DATA_R&pins_mask;
					break;
					case 2:
						x=GPIO_PORTC_DATA_R&pins_mask;
					break;
					case 3:
						x=GPIO_PORTD_DATA_R&pins_mask;
					break;
					case 4:
						x=GPIO_PORTE_DATA_R&pins_mask;
					break;
					case 5:
						x=GPIO_PORTF_DATA_R&pins_mask;
					break;
					
			
				}
				
				
				return x;
				
				
			}
