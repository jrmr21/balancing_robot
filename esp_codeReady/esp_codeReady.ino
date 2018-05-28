#include "wifi.h"
#include <SPI.h>
#define CS 15 //define chip select line for manual control

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("coucou tua ");
  wifi_connection();                                          // lance le serveur

  pinMode(CS, OUTPUT);                                       //configure the line as output
  digitalWrite(CS, HIGH);                                    //Initialize the CS line to HIGH
  SPI.begin();                                               //Initialize the SPI module--> configures the MOSI, MISO and CLOCK lines

    /*Configure the SPI bus as follows
1. SPI bus speed = 1 MHz
2. Data Out = From MSB bit ---> To LSB bit
3. Data Mode = SPI MODE0*/
   SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
}


void loop()
{
    //Serial.println(get_wifi_message());
    digitalWrite(CS, LOW);                                     //Pull CS Line Low
    SPI.transfer(get_wifi_messageChar());                                        //Send a byte (0x02) to the slave i.e. Arduino UNO
    delayMicroseconds(10);                                     //Give some time for the slave to process/do something with the recived data
    digitalWrite(CS, HIGH);                                    //Pull CS Line High
}
