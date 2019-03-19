void Port_SetPinPullUp(  unsigned char port_index , unsigned char pins_mask , unsigned char enable  )
{
 if(port_index==5)
 {
 if(enable)
 GPIO_PORTF_PUR_R |= pins_mask ; 
 else
 GPIO_PORTF_PUR_R &= ~(pins_mask) ; 
 
 }
 if(port_index==4)
 {
 if(enable)
 GPIO_PORTE_PUR_R |= pins_mask ; 
 else
 GPIO_PORTE_PUR_R &= ~(pins_mask) ; 
 
 }
 if(port_index==3)
 {
 if(enable)
 GPIO_PORTD_PUR_R |= pins_mask ; 
 else
 GPIO_PORTD_PUR_R &= ~(pins_mask) ; 
 
 }
 if(port_index==2)
 {
 if(enable)
 GPIO_PORTC_PUR_R |= pins_mask ; 
 else
 GPIO_PORTC_PUR_R &= ~(pins_mask) ; 
 
 }
 if(port_index==1)
 {
 if(enable)
 GPIO_PORTB_PUR_R |= pins_mask ; 
 else
 GPIO_PORTB_PUR_R &= ~(pins_mask) ; 
 
 }
 if(port_index==0)
 {
 if(enable)
 GPIO_PORTA_PUR_R |= pins_mask ; 
 else
 GPIO_PORTA_PUR_R &= ~(pins_mask) ; 
 
 }
	

}
