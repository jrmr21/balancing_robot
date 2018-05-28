#include "spi_slave.h"

void spi_init()
{   
    DDR_SPI &= ~((1<<MOSI)|(1<<MISO)|(1<<SS)|(1<<SCK));
    // Define the following pins as output
    DDR_SPI |= (1<< MISO);

    SPCR = ((1<<SPE)|               // SPI Enable
            (1<<SPIE)|              // SPI Interupt Enable
            (0u<<DORD)|              // Data Order (0:MSB first / 1:LSB first)
            (0<<MSTR)|              // Master/Slave select   
            (0<<SPR1)|(0<<SPR0)|    // SPI Clock Rate
            (0<<CPOL)|              // Clock Polarity (0:SCK low / 1:SCK hi when idle)
            (0<<CPHA));             // Clock Phase (0:leading / 1:trailing edge sampling
            
        //SPI status register
    SPSR  |= 0b00000000;
    sei();      //  run interupt
}

char get_SpiData()
{
  return dataEcho;
}

ISR(SPI_STC_vect)
{      //  interupt fonction type void
  cli();                //  Disables all interrupts by clearing the global interrupt mask

  if(!(PINB & (1<<SS)))   //while SS Low
  {
    SPDR = 0;      //  send value
    while(!(SPSR & (1 << SPIF)));  //wait SPI transfer complete
    
    dataEcho = SPDR;        //    get data du registre SPDR
  }
  sei();                //  Enables interrupts by setting the global interrupt mask
}
