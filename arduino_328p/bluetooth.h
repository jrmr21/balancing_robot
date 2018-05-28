#ifndef BLUETOOTH_H_INCLUDED
#define BLUETOOTH_H_INCLUDED

#include <SoftwareSerial.h>
static SoftwareSerial HC06(11,12);// (RX, TX) (pin Rx BT, pin Tx BT)

void bluetooth_init();
char bluetooth_loop();

#endif
