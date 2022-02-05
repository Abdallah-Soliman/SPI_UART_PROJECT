/*
 * APP.c
 *
 *  Created on: Feb 5, 2022
 *      Author: abdalah
 */


#include "primitive_data_types.h"
#include "DIO_interface.h"
#include "SPI_INTERFACE.h"
void main()
{
	DIO_SetPinDirection(PORTA,PIN0,OUTPUT);
	DIO_SetPinValue(PORTA,PIN0,HIGH);
	USART_VoidInit(PORTD,PIN1,PIN0);
	SPI_U8MasterInit(PORTB,PIN5,PIN6,PIN7);
	uint8_t send_data[9]="";
	uint8_t receiving[9]="";
	UART_U8ReciveBufferSyn(send_data,8);



	while(1)
	{
		SPI_TranSeverBufferSYN(send_data ,8,receiving);
	}


}
