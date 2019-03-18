#include "tm4c123gh6pm.h"
#define GPIO_PCTL_PE3210_M  (GPIO_PCTL_PE3_M | GPIO_PCTL_PE2_M | GPIO_PCTL_PE1_M |  GPIO_PCTL_PE0_M) 
#define GPIO_PCTL_PB3210_M  (GPIO_PCTL_PB3_M | GPIO_PCTL_PB2_M | GPIO_PCTL_PB1_M |  GPIO_PCTL_PB0_M) 
#define GPIO_PCTL_PD3210_M  (GPIO_PCTL_PD3_M | GPIO_PCTL_PD2_M | GPIO_PCTL_PD1_M |  GPIO_PCTL_PD0_M) 
#define GPIO_PCTL_PA432_M  (GPIO_PCTL_PA4_M | GPIO_PCTL_PA3_M | GPIO_PCTL_PA2_M) 

unsigned long delay_1;
unsigned char num_1=0 , num_2=0 , num_3=0 ;


void SystemInit()
{

	volatile unsigned long delay;

SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4; //PortE clock enable 
delay = SYSCTL_RCGCGPIO_R ; //delay 
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1; //PortB clock enable
delay = SYSCTL_RCGCGPIO_R ; //delay 
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3; //PortD clock enable 
delay = SYSCTL_RCGCGPIO_R ; //delay 
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0; //PortA clock enable 
delay = SYSCTL_RCGCGPIO_R ; //delay 

	
GPIO_PORTE_LOCK_R = 0x4C4F434B ;	//Unlock PortE Commit register
GPIO_PORTB_LOCK_R = 0x4C4F434B ;  //Unlock PortB Commit register
GPIO_PORTD_LOCK_R = 0x4C4F434B ;  //Unlock PortD Commit register
GPIO_PORTA_LOCK_R = 0x4C4F434B ;  //Unlock PortA Commit register
	
//Allow changes to PORT E , B , D , A  
GPIO_PORTE_CR_R |= 0x0F; 
GPIO_PORTB_CR_R |= 0x0F; 
GPIO_PORTD_CR_R |= 0x0F; 
GPIO_PORTA_CR_R |= 0x1C; 

GPIO_PORTE_AMSEL_R &= ~(0x0F); 
GPIO_PORTB_AMSEL_R &= ~(0x0F); 
GPIO_PORTD_AMSEL_R &= ~(0x0F); 
GPIO_PORTA_AMSEL_R &= ~(0x1C); 

GPIO_PORTE_PCTL_R &= ~(GPIO_PCTL_PE3210_M);
GPIO_PORTB_PCTL_R &= ~(GPIO_PCTL_PB3210_M);
GPIO_PORTD_PCTL_R &= ~( GPIO_PCTL_PD3210_M );
GPIO_PORTA_PCTL_R &= ~(GPIO_PCTL_PA432_M);

GPIO_PORTE_AFSEL_R &= ~(0x0F);
GPIO_PORTB_AFSEL_R &= ~(0x0F);
GPIO_PORTD_AFSEL_R &= ~(0x0F);
GPIO_PORTA_AFSEL_R &= ~(0x1C);

GPIO_PORTE_DIR_R |= 0x0F; 
GPIO_PORTB_DIR_R |= 0x0F;
GPIO_PORTD_DIR_R |= 0x0F;
GPIO_PORTA_DIR_R &= ~(0x1C);

GPIO_PORTA_PDR_R |= 0x1C; 

GPIO_PORTE_DEN_R |= 0x0F;
GPIO_PORTB_DEN_R |= 0x0F;
GPIO_PORTD_DEN_R |= 0x0F;
GPIO_PORTA_DEN_R |= 0x1C;

GPIO_PORTE_DATA_R &= ~(0x0F) ; 
GPIO_PORTB_DATA_R &= ~(0x0F) ; 
GPIO_PORTD_DATA_R &= ~(0x0F) ; 

num_1 = 0 ; 
GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xFFFFFFF0 ) | (num_1 & 0x0F ) ;
num_2 = 0 ; 
GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xFFFFFFF0 ) | (num_2 & 0x0F ) ;
num_3 = 0 ; 
GPIO_PORTD_DATA_R = ( GPIO_PORTD_DATA_R & 0xFFFFFFF0 ) | (num_3 & 0x0F ) ;


}
void delay_func(unsigned long delay);
int main(void)
{
	
	
	while(1)
{ 
// Increment section 
if( GPIO_PORTA_DATA_R & (1<<2) )
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
else if ( GPIO_PORTA_DATA_R & (1<<3) ) // Decrement section
{
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
else //any number for ex : 576 
{
	
num_1-- ; 
GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ; 
while(GPIO_PORTA_DATA_R & (1<<3)) ; //do nothing 
}



}


}
else if(GPIO_PORTA_DATA_R & (1<<4)) //Reset section
{
while(GPIO_PORTA_DATA_R & (1<<4))	;
num_1 = 0 ; 
GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ;
num_2 = 0 ; 
GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xF0 ) | (num_2 & 0x0F ) ;
num_3 = 0 ; 
GPIO_PORTD_DATA_R = ( GPIO_PORTD_DATA_R & 0xF0 ) | (num_3 & 0x0F ) ;
	
}
	
	
	
	
}








}



void delay_func( unsigned long delay)
{
unsigned long i ; 
for( i=0 ; i<delay ; i++ ) ; 
}	
