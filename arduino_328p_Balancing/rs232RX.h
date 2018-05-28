#ifndef RS232RX_H_INCLUDED
#define RS232RX_H_INCLUDED

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "arduino.h"
#include "utilitaire.h"     //  led debug reception

/*************************** REGISTRE UART ATMEGA328p ****************************/
#define UARTB UCSR0B 
#define UARTC UCSR0C
#define UARTA UCSR0A
#define BAUD UBRR0L 
#define BAUD2 UBRR0H
#define TXEN TXEN0
#define RXEN RXEN0

#define enableUartRX RXC0
#define UartIsEmpty UDRE0
#define UartRegister UDR0

#define UMSEL0 UMSEL00
#define UMSEL1 UMSEL01
#define UCSZ_0 UCSZ00
#define UCSZ_1 UCSZ01
#define UCSZ_2 UCSZ02
/*************************** REGISTRE UART ATMEGA328p ****************************/

/*************************** REGISTRE UART ATMEGA32U4 ****************************
#define UARTB UCSR1B
#define UARTC UCSR1C
#define UARTA UCSR1A
#define BAUD UBRR1L 
#define BAUD2 UBRR1H
#define TXEN TXEN1
#define RXEN RXEN1

#define enableUartRX RXC1            
#define UartIsEmpty UDRE1             
#define UartRegister UDR1

#define UMSEL0 UMSEL10
#define UMSEL1 UMSEL11
#define UCSZ_0 UCSZ10
#define UCSZ_1 UCSZ11
#define UCSZ_2 UCSZ12
/*************************** REGISTRE UART ATMEGA32U4 ****************************/

#define F_CPU 16000000UL    
//#define BAUD_PRESCALE  ((F_CPU)/(BAUD*16UL)-1)     //  ARDUINO all 
#define BAUD_PRESCALE ((((F_CPU + (USART_BAUDRATE * 8UL)) / (USART_BAUDRATE * 16UL))) - 1)  //  ARDUINO micro pro



unsigned char uart_recieve (void);
void uart_transmit (char data);
void UART_Init(long USART_BAUDRATE);
char get_buffer();
static char buffeur;
/*
    registre UART A
    -Bit 7 – RXC: USART Receive Complete
    -Bit 6 – TXC: USART Transmit Complete
    -Bit 5 – UDRE: USART Data Register Empty
    -UDRE0  USART Data Register Empty. Set when the UDR0 register is
            empty and new data can be transmitted

     registre UART B
    -Bit 7 – RXCIE: RX Complete Interrupt Enable
    -Bit 6 – TXCIE: TX Complete Interrupt Enable
    -Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable
    -Bit 4 – RXEN: Receiver Enable
    -Bit 3 – TXEN: Transmitter Enable

    registre UART C
    - USART Mode Select 1 and 0. UMSEL01 and UMSEL00
    - UCSZ01,UCSZ00,USART Character Size 1 and 0. Used together with with
      UCSZ20 to set data frame size
 */
#endif
