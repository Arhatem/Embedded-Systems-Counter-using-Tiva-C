//Definitions
typedef unsigned char uint8 ; 


//PORT Driver 

//Type Definitions 
enum Port_PinDirectionType 
{
	PORT_PIN_IN = 0 , PORT_PIN_OUT = 1 	
};
//Function Definitions 
void Port_Init( uint8 port_index ) ; 
void Port_SetPinDirection( uint8 port_index ) ; 
void Port_SetPinPullUp ( uint8 port_index ) ; 
void Port_SetPinPullDown ( uint8 port_index ) ; 



//DIO Driver
enum Dio_LevelType 
{
	STD_LOW = 0 ,  STD_HIGH = 1  
}; 
//Function Definitions 
uint8 DIO_ReadPort ( uint8 port_index ,uint8 pins_mask ) ; 
uint8 DIO_WritePort  ( uint8 port_index ,uint8 pins_mask , enum Dio_LevelType pins_level ) ;
uint8 DIO_ReadPort ( uint8 port_index ,uint8 pins_mask ) ; 
uint8 DIO_FlipPort ( uint8 port_index ,uint8 pins_mask ) ;  