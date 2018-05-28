#ifndef ENCODER_H
#define ENCODER_H

#include <arduino.h>
#include "moteur.h"


#define interruptPinG 2
#define interruptPinD 3


static int vitessD=0;
static int vitessG=0;
  
void init_encodeur();

static void encoderD();
static void encoderG();

void getVitess(int &moteurD, int &moteurG);
int comparaisonMoteur();

#endif
