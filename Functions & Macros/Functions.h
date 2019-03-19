#pragma once
#include "tm4c123gh6pm.h"
#include "macros.h"
#define GPIO_PCTL_M									0x00000000U
#define GPIO_SETALLPINS_M				    0xFFU

typedef enum { PORT_PIN_IN , PORT_PIN_OUT}Port_PinDirectionType ;
void Port_SetPinPullUp(  unsigned char port_index , unsigned char pins_mask , unsigned char enable  );
void Port_SetPinPullDown(  unsigned char port_index , unsigned char pins_mask , unsigned char enable  );
void Port_Init(char port_index  );
void Port_SetPinDirection(char port_index ,char pins_mask, Port_PinDirectionType pins_direction );
void delay_func( unsigned long delay);
void increment();
void Reset();
void decrement();
