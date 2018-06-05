#include "wifi.h"

extern String wifi_connection()
{
    IPAddress apIP(192, 168, 0, 177); 

    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0)); 
    //  https://42bots.com/tutorials/esp8266-example-wi-fi-access-point-web-server-static-ip-remote-control/
    WiFi.softAP(ssid, password);
    
    UDPTestServer.begin(UDPPort);  //  run UDP port 
     
     return "connecté";  
}

extern String get_wifi_message()
{
    String myData="";         //  buffer recerve data ( reception des données )
    int hours=0,minutes=0;    
    int cb = UDPTestServer.parsePacket();     //  on check la reception des données
    if (cb)                                   //  si c est vrai
    {
      UDPTestServer.read(packetBuffer, packetSize);     //  reception des data dans packet buffer
      for(int i = 0; i < packetSize; i++) 
      {
        myData += (char)packetBuffer[i];            // on met packetBuffer dans le string "myData"

        }
      }
      return myData;     //  renvoie les data recus
}


extern byte get_wifi_messageChar()
{
    static byte myData = 5;         //  default 5 == stop 
    int cb = UDPTestServer.parsePacket();     //  on check la reception des données
    if (cb)                                   //  si c est vrai
    {
      UDPTestServer.read(packetBuffer, packetSize);     //  reception des data dans packet buffer

      myData = packetBuffer[0] - 48;            // on met packetBuffer dans le string "myData"
    }
    return myData ;     //  renvoie les data recus
}
