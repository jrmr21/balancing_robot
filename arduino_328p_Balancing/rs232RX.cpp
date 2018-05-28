#include "rs232RX.h"


void UART_Init(long USART_BAUDRATE)
{
  // USART initialization
  UCSR0A= 0x00;                 // Clear the UASRT status register
  UARTB |= ( (1<<RXEN) | (1<<TXEN) | (1<<RXCIE0)  );     // Enable Receiver and Transmitter  REGISTER B (one wire )  
  UARTC |= ( (0<<UMSEL0)|(0<<UMSEL1) | (0<<UCSZ_2) | (1<<UCSZ_1) | (1<<UCSZ_0));      
                                                /*   UMSEL0.. asynchronous (00), synchronous (01) and master SPI (11).8-bit data 
                                                     UCSZ20 UCSZ01 and UCSZ00 control the data size. Possible sizes are 5-bit (000)
                                                    6-bit (001), 7-bit (010), 8-bit (011) and 9-bit (111)*/
  BAUD = BAUD_PRESCALE;        /* Load lower 8-bits of the baud rate */
  BAUD2 = (BAUD_PRESCALE >> 8);   /* Load upper 8-bits*/
  sei();
}

// function to send data
void uart_transmit (char data)
{
    while(!(UARTA & (1<<UartIsEmpty)));                // wait while register is free
    UartRegister = data;   // here 10 means decimaldata;                                   // load data in the register
}

// function to receive data
unsigned char uart_recieve (void)
{
    while(!(UARTA) & (1<<enableUartRX));                   // wait while data is being received
    return UartRegister;                                   // return 8-bit data
}

char get_buffer()
{
  return buffeur;
}
// #define USART0_RX_vect     _VECTOR(20)  /* USART Rx Complete */ 
ISR( USART_RX_vect ) 
{
  cli();
    led_power(true);
    buffeur = uart_recieve ();
  sei();
}
