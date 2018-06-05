#ifndef WIFI_H
#define WIFI_H
#include <arduino.h>

#include "ESP8266WiFi.h"
#include <WiFiUdp.h>

#include <WiFiClient.h>         
#include <ESP8266WebServer.h>     

static const char* ssid     = "SosoMobile";   //          id et mdp de connection
static const char* password = "mainbot123";   // 


static WiFiUDP UDPTestServer;             //  objet UDP
static unsigned int UDPPort = 7979;     //  port de com
static const int packetSize = 1;       //  taille des messages   ( on peut le remplacer par un define )
static byte packetBuffer[packetSize];  //   tableau de reception des data



extern String wifi_connection();
extern String get_wifi_message(); // get wifi msg
extern byte get_wifi_messageChar();
#endif
