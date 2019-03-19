#include "functions.h"


extern unsigned long delay_1,num_1,num_2,num_3;
void increment()
{
	delay_1 = 480000 ;
	delay_func(delay_1); //due to switch debouncing 
	if( GPIO_PORTA_DATA_R & (1<<2) ) // BUTTON D0 PRESSED ?
	{
		delay_1 = 16000000 ; 
		if( ( ( GPIO_PORTE_DATA_R & 0x0F ) == 9 ) && ( ( GPIO_PORTB_DATA_R & 0x0F ) != 9 ) && ( ( GPIO_PORTD_DATA_R & 0x0F  )!= 9 )  )	//**9
		{
			delay_func(delay_1) ; // Delay 0.2 seconds 
			num_1 = 0 ; 
			GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ;
			num_2++ ; 
			GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xF0 ) | (num_2 & 0x0F ) ;
		}
		else if( ( ( GPIO_PORTE_DATA_R & 0x0F ) == 9 ) && ( ( GPIO_PORTB_DATA_R & 0x0F ) == 9 ) && ( ( GPIO_PORTD_DATA_R & 0x0F  )!= 9 )  ) //*99
		{
			delay_func(delay_1) ; // Delay 0.2 seconds 
			num_1 = 0 ; 
			GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ;
			num_2 = 0 ; 
			GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xF0 ) | (num_2 & 0x0F ) ;
			num_3++ ;
			GPIO_PORTD_DATA_R = ( GPIO_PORTD_DATA_R & 0xF0 ) | (num_3 & 0x0F ) ;
		}
		else if( ( ( GPIO_PORTE_DATA_R & 0x0F ) == 9 ) && ( ( GPIO_PORTB_DATA_R & 0x0F ) == 9 ) && ( ( GPIO_PORTD_DATA_R & 0x0F  )== 9 )  ) //999
		{
			// do nothing 
		}
		else if( ( ( GPIO_PORTE_DATA_R & 0x0F ) == 9 ) && ( ( GPIO_PORTB_DATA_R & 0x0F ) != 9 ) && ( ( GPIO_PORTD_DATA_R & 0x0F  )== 9 )  ) //9*9
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

void decrement(){
	delay_1 = 480000 ;
	delay_func(delay_1); //due to switch debouncing 
	if(GPIO_PORTA_DATA_R & (1<<3))
	{
		if( ( ( GPIO_PORTE_DATA_R & 0x0F ) == 0 ) && ( ( GPIO_PORTB_DATA_R & 0x0F ) != 0 ) && ( ( GPIO_PORTD_DATA_R & 0x0F  )!= 0 )  ) // **0
		{
			num_1 = 9 ; 
			GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ;
			num_2-- ; 
			GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xF0 ) | (num_2 & 0x0F ) ;
			while(GPIO_PORTA_DATA_R & (1<<3)) ; //do nothing 
		}
		else if( ( ( GPIO_PORTE_DATA_R & 0x0F ) == 0 ) && ( ( GPIO_PORTB_DATA_R & 0x0F ) == 0 ) && ( ( GPIO_PORTD_DATA_R & 0x0F  )!= 0 ) ) // *00
		{
			num_1 = 9 ; 
			GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ;
			num_2 = 9 ; 
			GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xF0 ) | (num_2 & 0x0F ) ;
			num_3-- ;
			GPIO_PORTD_DATA_R = ( GPIO_PORTD_DATA_R & 0xF0 ) | (num_3 & 0x0F ) ;
			while(GPIO_PORTA_DATA_R & (1<<3)) ; //do nothing 

		}
		else if( ( ( GPIO_PORTE_DATA_R & 0x0F ) == 0 ) && ( ( GPIO_PORTB_DATA_R & 0x0F ) == 0 ) && ( ( GPIO_PORTD_DATA_R & 0x0F  )== 0 )  ) //000
		{
			// do nothing 
			while(GPIO_PORTA_DATA_R & (1<<3)) ; //do nothing 
		}
		else if( ( ( GPIO_PORTE_DATA_R & 0x0F ) == 0 ) && ( ( GPIO_PORTB_DATA_R & 0x0F ) != 0 ) && ( ( GPIO_PORTD_DATA_R & 0x0F  )== 0 )  ) //0*0
		{
			num_1 = 9 ; 
			GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ;
			num_2-- ; 
			GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xF0 ) | (num_2 & 0x0F ) ;
			while(GPIO_PORTA_DATA_R & (1<<3)) ; //do nothing 
		}
		else //any number 
		{
			num_1-- ; 
			GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ; 
			while(GPIO_PORTA_DATA_R & (1<<3)) ; //do nothing 
		}
	}
}
void Reset(){
	while(GPIO_PORTA_DATA_R & (1<<4))	;
	num_1 = 0 ; 
	GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ;
	num_2 = 0 ; 
	GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xF0 ) | (num_2 & 0x0F ) ;
	num_3 = 0 ; 
	GPIO_PORTD_DATA_R = ( GPIO_PORTD_DATA_R & 0xF0 ) | (num_3 & 0x0F ) ;
}

 void Port_Init(char port_index  )
 {
	 volatile unsigned long delay;
	 if(port_index==5)
	 {
	  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
		delay = SYSCTL_RCGCGPIO_R;
		GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY; 
	 
	 }
	 
	 else if(port_index==4)
	 {
	  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
		delay = SYSCTL_RCGCGPIO_R;
		GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY; 
		
	 }
	 
	 
	 else if(port_index==3)
	 {
	  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;
		delay = SYSCTL_RCGCGPIO_R;
		GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY; 
		
	 
	 }
	 
	 
	 else if(port_index==2)
	 {
	  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;
		delay = SYSCTL_RCGCGPIO_R;
		GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY; 
		
	 
	 }
	 
	 else if(port_index==1)
	 {
	  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
		delay = SYSCTL_RCGCGPIO_R;
		GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY; 
		
	 
	 }
	 
	 
	 else if(port_index==0)
	 {
	  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
		delay = SYSCTL_RCGCGPIO_R;
		GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY; 
	 }
 }

void Port_SetPinDirection(char port_index ,char pins_mask, Port_PinDirectionType pins_direction )
 {
	 volatile unsigned long delay;
	 if(port_index==5)
	 {
	  Port_Init(5) ;
		GPIO_PORTF_CR_R |= pins_mask; 
		GPIO_PORTF_AMSEL_R &= ~pins_mask;
		GPIO_PORTF_PCTL_R = GPIO_PCTL_M	;
		GPIO_PORTF_AFSEL_R &= ~pins_mask;
		GPIO_PORTF_DEN_R |= pins_mask;
	 if(pins_direction)
		 GPIO_PORTF_DIR_R |= pins_mask; 
		  else 
		 GPIO_PORTF_DIR_R &= ~pins_mask; 
	 }
	 
	 else if(port_index==4)
	 {
	 Port_Init(4) ;
		GPIO_PORTE_CR_R |= pins_mask; 
		GPIO_PORTE_AMSEL_R &= ~pins_mask;
		GPIO_PORTE_PCTL_R = GPIO_PCTL_M	;
		GPIO_PORTE_AFSEL_R &= ~pins_mask;
		GPIO_PORTE_DEN_R |= pins_mask;
		if(pins_direction)
		 GPIO_PORTE_DIR_R |= pins_mask; 
		else 
		 GPIO_PORTE_DIR_R &= ~pins_mask; 
	 
	 }
	 else if(port_index==3)
	 {
		Port_Init(3) ; 
		GPIO_PORTD_CR_R |= pins_mask; 
		GPIO_PORTD_AMSEL_R &= ~pins_mask;
		GPIO_PORTD_PCTL_R = pins_mask	;
		GPIO_PORTD_AFSEL_R &= ~pins_mask;
		GPIO_PORTD_DEN_R |= pins_mask;
		if(pins_direction)
		 GPIO_PORTD_DIR_R |= pins_mask; 
		else 
		 GPIO_PORTD_DIR_R &= ~pins_mask;  
	 }
	 else if(port_index==2)
	 {
	  Port_Init(2) ; 
		GPIO_PORTC_CR_R |= pins_mask; 
		GPIO_PORTC_AMSEL_R &= ~pins_mask;
		GPIO_PORTC_PCTL_R = GPIO_PCTL_M	;
		GPIO_PORTC_AFSEL_R &= ~pins_mask;
		GPIO_PORTC_DEN_R |= pins_mask;
		if(pins_direction)
		 GPIO_PORTC_DIR_R |= pins_mask; 
		else 
		 GPIO_PORTC_DIR_R &= ~pins_mask; 
	 }
	 else if(port_index==1)
	 {
	  Port_Init(1) ;
		GPIO_PORTB_CR_R |= pins_mask; 
		GPIO_PORTB_AMSEL_R &= ~pins_mask;
		GPIO_PORTB_PCTL_R = GPIO_PCTL_M	;
		GPIO_PORTB_AFSEL_R &= ~pins_mask;
		GPIO_PORTB_DEN_R |= pins_mask;
		if(pins_direction)
		 GPIO_PORTB_DIR_R |= pins_mask; 
		else 
		 GPIO_PORTB_DIR_R &= ~pins_mask; 
	 
	 }
	 else if(port_index==0)
	 {
	  Port_Init(0) ; 
		GPIO_PORTA_CR_R |= pins_mask; 
		GPIO_PORTA_AMSEL_R &= ~pins_mask;
		GPIO_PORTA_PCTL_R = GPIO_PCTL_M	;
		GPIO_PORTA_AFSEL_R &= ~pins_mask;
		GPIO_PORTA_DEN_R |= pins_mask;
		if(pins_direction)
		 GPIO_PORTA_DIR_R |= pins_mask; 
		else 
		 GPIO_PORTA_DIR_R &= ~pins_mask; 
	 }
 }
 
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
 
void Port_SetPinPullDown(  unsigned char port_index , unsigned char pins_mask , unsigned char enable  )
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

void delay_func( unsigned long delay)
{
	unsigned long i ; 
	for( i=0 ; i<delay ; i++ ) ; 
}
