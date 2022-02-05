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
    LCD_VoidInit4b();
    USART_VoidInit(PORTD,PIN1,PIN0);

	SPI_U8SlaveInit(PORTB,PIN5,PIN6,PIN4,PIN7);

	uint8_t send_data[9]="ABDULLAH";
	uint8_t receiving[9]="";

	SPI_TranSeverBufferSYN(send_data ,8,receiving);
	UART_U8SendBufferSyn(receiving,8);
	LCD_VoidWriteStringfor4bits(receiving);
	while(1)
	{

	}


}
