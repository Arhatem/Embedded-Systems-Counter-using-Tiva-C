#include "tm4c123gh6pm.h"
#include "Port_SetPinPullDown.h"
void Port_SetPinPullDown(  uint8 port_index , uint8 pins_mask , uint8 enable  )
{
 if(port_index==5)
 {
 if(enable)
 GPIO_PORTF_PDR_R |= pins_mask ; 
 else
 GPIO_PORTF_PDR_R &= ~(pins_mask) ; 
 
 }
 if(port_index==4)
 {
 if(enable)
 GPIO_PORTE_PDR_R |= pins_mask ; 
 else
 GPIO_PORTE_PDR_R &= ~(pins_mask) ; 
 
 }
 if(port_index==3)
 {
 if(enable)
 GPIO_PORTD_PDR_R |= pins_mask ; 
 else
 GPIO_PORTD_PDR_R &= ~(pins_mask) ; 
 
 }
 if(port_index==2)
 {
 if(enable)
 GPIO_PORTC_PDR_R |= pins_mask ; 
 else
 GPIO_PORTC_PDR_R &= ~(pins_mask) ; 
 
 }
 if(port_index==1)
 {
 if(enable)
 GPIO_PORTB_PDR_R |= pins_mask ; 
 else
 GPIO_PORTB_PDR_R &= ~(pins_mask) ; 
 
 }
 if(port_index==0)
 {
 if(enable)
 GPIO_PORTA_PDR_R |= pins_mask ; 
 else
 GPIO_PORTA_PDR_R &= ~(pins_mask) ; 
 
 }
	



}