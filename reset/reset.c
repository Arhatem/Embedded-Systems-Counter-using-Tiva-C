void Reset(){
	while(GPIO_PORTA_DATA_R & (1<<4))	;
	num_1 = 0 ; 
	GPIO_PORTE_DATA_R = ( GPIO_PORTE_DATA_R & 0xF0 ) | (num_1 & 0x0F ) ;
	num_2 = 0 ; 
	GPIO_PORTB_DATA_R = ( GPIO_PORTB_DATA_R & 0xF0 ) | (num_2 & 0x0F ) ;
	num_3 = 0 ; 
	GPIO_PORTD_DATA_R = ( GPIO_PORTD_DATA_R & 0xF0 ) | (num_3 & 0x0F ) ;
}
