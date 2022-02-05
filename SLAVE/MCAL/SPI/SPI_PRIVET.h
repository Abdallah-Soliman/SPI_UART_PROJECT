/*
 * SPI_PRIVET.h
 *
 *  Created on: Jan 25, 2022
 *      Author: abdalah
 */

#ifndef SPI_PRIVET_H_
#define SPI_PRIVET_H_

#define   fosc_4      0

#define   fosc_16     1

#define   fosc_64     2

#define   fosc_128    3

#define SPDR *((volatile uint8_t*)0x2f)

#define SPSR *((volatile uint8_t*)0x2e)
#define SPSR_SPIF		7				/*SPI Interrupt Flag*/
#define SPSR_SPI2X		0				/*Double SPI Speed*/

#define SPCR *((volatile uint8_t*)0x2d)
#define SPCR_SPIE		7				/*SPI Interrupt Enable*/
#define SPCR_SPE		6				/*SPI Enable*/
#define SPCR_DORD		5				/*Data Order Enable*/
#define SPCR_MSTR		4				/*Master Slave Select*/
#define SPCR_CPOL		3				/*Clock Polarity*/
#define SPCR_CPHA		2				/*Clock Phase*/
#define SPCR_SPR1		1				/*SPI Clock Rate select 1*/
#define SPCR_SPR0		0				/*SPI Clock Rate select 0*/


#define LOW  0

#define  HIGH 1

#define  MASK_VALUE    0xfc

#define    NULL   (void*)0
#endif /* SPI_PRIVET_H_ */
