#ifndef SPI_H_INCLUDED
#define SPI_H_INCLUDED

#include <avr/io.h>
#include <avr/interrupt.h>


/********************************* atmega 328p *********************************/
#define SS DDB2
#define MISO DDB4      // atmega 328p
#define MOSI DDB3
#define SCK DDB5
/********************************* atmega 32u4 *********************************/

/********************************* atmega 32u4 *********************************
#define SS DDB6       //  why not...
#define MISO DDB3       //atmega 32u4
#define MOSI DDB2
#define SCK DDB1
/********************************* atmega 32u4 *********************************/
#define DDR_SPI DDRB

static char dataEcho = 5;  
void spi_init();
char get_SpiData();


#endif
