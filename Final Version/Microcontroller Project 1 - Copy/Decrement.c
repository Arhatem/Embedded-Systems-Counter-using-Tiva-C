#include "Decrement.h"

void delay_func( unsigned long  time);
  unsigned long delay_1;
 unsigned long num_1 , num_2 , num_3 ;
 void Decrement(void){
 
 
 	
delay_1 = 320000 ;
delay_func(delay_1); //due to switch debouncing 
if(DIO_ReadPort(0,0x08))
{
if( ( DIO_ReadPort(4,0x0F) == 0 ) && (  DIO_ReadPort(1,0x0F)  != 0 ) && (DIO_ReadPort(3,0x0F)!= 0 )  ) // **0
{
	
num_1 = 9 ; 
GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ;
num_2-- ; 
GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xF0 ) | (num_2 & 0x0F ) ;
while(DIO_ReadPort(0,0x08)) ; //do nothing 
	
}
 else if( ( DIO_ReadPort(4,0x0F) == 0 ) && ( DIO_ReadPort(1,0x0F) == 0 ) && ( DIO_ReadPort(3,0x0F)!= 0 ) ) // *00
{
	
num_1 = 9 ; 
GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ;
num_2 = 9 ; 
GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xF0 ) | (num_2 & 0x0F ) ;
num_3-- ;
GPIO_PORTD_DATA_R = ( GPIO_PORTD_DATA_R & 0xF0 ) | (num_3 & 0x0F ) ;
while(GPIO_PORTA_DATA_R & (1<<3)) ; //do nothing 

}

else if( ( DIO_ReadPort(4,0x0F) == 0 ) && ( DIO_ReadPort(1,0x0F) == 0 ) && ( DIO_ReadPort(3,0x0F)== 0 )  ) //000
{
// do nothing 
while(GPIO_PORTA_DATA_R & (1<<3)) ; //do nothing 
}
else if( ( DIO_ReadPort(4,0x0F) == 0 ) && ( DIO_ReadPort(1,0x0F) == 0 != 0 ) && ( DIO_ReadPort(3,0x0F)== 0 )  ) //0*0
{

num_1 = 9 ; 
GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ;
num_2-- ; 
GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xF0 ) | (num_2 & 0x0F ) ;
while(DIO_ReadPort(0,0x08)) ; //do nothing 
}
else //any number for ex : 576 
{
	
num_1-- ; 
GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ; 
while(DIO_ReadPort(0,0x08)) ; //do nothing 
}



}


 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 }
