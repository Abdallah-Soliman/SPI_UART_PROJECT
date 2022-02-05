/*
 * SPI_PROGRAM.c
 *
 *  Created on: Jan 25, 2022
 *      Author: abdalah
 */
#include "primitive_data_types.h"
#include "BIT_MATH.h"
#include "SPI_PRIVET.h"
#include "SPI_INTERFACE.h"
#include "DIO_interface.h"



void SPI_U8MasterInit(uint8_t au8_PORT ,uint8_t au_MOSIPIN ,uint8_t au_MISOPIN ,uint8_t au_Clock)
{
	          /*initialization of MOSI DIRECTION*/
	DIO_SetPinDirection(au8_PORT ,au_MOSIPIN ,OUTPUT);
	            /* MISO  direction   */
	DIO_SetPinDirection(au8_PORT ,au_MISOPIN ,INPUT);
                 /*clock output pin*/
	DIO_SetPinDirection(au8_PORT ,au_Clock ,OUTPUT);
	          /*select pre scaler */
	               SPCR&=MASK_VALUE ;

	               SPCR |= SPI_CLOCK;

	              /*Master node*/
	          SET_BIT(SPCR,SPCR_MSTR);

	         /*Enable SPI peripheral */
	          SET_BIT(SPCR,SPCR_SPE);

}

void SPI_U8SlaveInit(uint8_t au8_PORT ,uint8_t au_MOSIPIN ,uint8_t au_MISOPIN,uint8_t au_ss,uint8_t au_Clc)
{
	          /*initialization of MOSI DIRECTION*/
	DIO_SetPinDirection(au8_PORT ,au_MOSIPIN ,INPUT);
	            /* MISO  direction   */
	DIO_SetPinDirection(au8_PORT ,au_MISOPIN ,OUTPUT);
                /*SLAVE SELECT PIN INPUT*/
	DIO_SetPinDirection(au8_PORT ,au_ss ,INPUT);
                  /*Clock as input*/
	DIO_SetPinDirection(au8_PORT ,au_Clc ,INPUT);
	              /*Slave node*/
	             CLR_BIT(SPCR,SPCR_MSTR);

	           /*Enable SPI peripheral */
	             SET_BIT(SPCR,SPCR_SPE);
}


uint8_t SPI_TranSever(uint8_t *ptr)
{

	SPDR =*ptr ;

	/*busy waiting for complete transmission flag*/
	      while((GET_BIT(SPSR,SPSR_SPIF))== LOW);

	     return SPDR ;
}



uint8_t SPI_TranSeverBufferSYN(uint8_t *ptr_Send ,uint8_t size,uint8_t *ptr_Resiver )
{
	uint8_t error_state =0;
	if(ptr_Send!=NULL &&  ptr_Resiver!=NULL )
	{
	for(uint8_t au_Counter =0 ;au_Counter < size ;au_Counter++)
	   {

		*(ptr_Resiver+au_Counter)=SPI_TranSever(&(ptr_Send[au_Counter]));
	   }
	}
	else
	{
		error_state =1;
	}


}




