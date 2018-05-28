#ifndef _moteur_H
#define _moteur_H

#include <arduino.h>
#include "pins_arduino.h"
#include "wiringprivate.h"  // to use cbi and sbi #reference

#ifdef __cplusplus
extern "C" {
#endif


void init_moteur();    //  declaration des entre sorties moteurs
void avant();           //  fonctions de stabilisation du robot
void arriere();
void power_off();

float f_droit(float origin);       //  fonctions de déplacement du robot
float f_gauche(float origin);      // peut modifier le % de puissance 
float f_avant(float origin);       // et le setPoint ( point d equilibre)
float f_arriere(float origin);
float f_arret(float origin);

static char commandeD = 0;   //  % de vitesse de direction propre au fichier source
static char commandeG = 0;   //  % de vitesse de direction propre au fichier source

static char vitesseD = 80;   //  vitesse par defaut propre au fichier source
static char vitesseG = 80;   //  vitesse par defaut propre au fichier source

void change_vitesse(bool motor, char vite);    //  1 = D, 0 = G

// https://playground.arduino.cc/Main/TimerPWMCheatsheet  source des TIMER et des pins PWM
void monPWM(uint8_t pin, int val);

void moteurD(byte sense);  // 1 = avant;  0 = arriere
void moteurG(byte sense);  // 1 = avant;  0 = arriere


#ifdef __cplusplus
}
#endif

#endif
