#include "bluetooth.h"

void bluetooth_init()
{
  HC06.begin(9600);  
}

char bluetooth_loop()
{
  static char c = 5; // default = stop
  if(HC06.available())
    {
      c = HC06.read();
    }
    return c;
}
