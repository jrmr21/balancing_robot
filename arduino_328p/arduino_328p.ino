#include "rgb.h"
#include "rs232TX.h"
#include "spi_slave.h"
#include "bluetooth.h"

String t = "bluetooth";   //  default configuration (spi other mode)

void setup() 
{
  UART_Init(115200);
  led_init();     //  help to debug
  start_rgb();
  
  if (t == "spi") spi_init();
  else bluetooth_init();
   
  char commande = '5', pastCommande = ' ';
  led_power(false);
  while(1)
  {
    continued_rgb();                      //  capteur de distance
    
    if ( (t == "spi") && (get_Distance() > 4) ) 
    {
      commande = get_SpiData();                //  send data ESP
      led_power(false);
    }
    else if((t == "bluetooth") && (get_Distance() > 4) )
    {
      commande = bluetooth_loop();                //  send data bluetooth
      led_power(false);
    }
    else if(get_Distance() < 4)
    {
      commande = '3';
      led_power(false);
    }
    else
    {
      commande = '5';
      led_power(false);
    }

    if(commande != pastCommande)
    {
      pastCommande = commande;
      uart_transmit(commande);
      led_power(true);
    }  
  }
}
