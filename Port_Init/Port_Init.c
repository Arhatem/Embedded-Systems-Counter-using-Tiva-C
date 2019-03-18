#include "tm4c123gh6pm.h"
#define GPIO_SETALLPINS_M				0xFFU 
#define GPIO_PCTL_M									0x00000000U



//input: the index of the port that neede to be intiated   output: void

 void Port_Init(uint8 port_index  )
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
