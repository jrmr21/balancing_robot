#ifndef _utilitaire_H
#define _utilitaire_H

#ifdef __cplusplus
extern "C" {        //  pour coder en C dans un langage C++ (prore a arduino j imagine)
#endif

#define LED DDB1    //  pin 9 led to debug
#include <stdbool.h>
#include <avr/io.h>

void led_init();
void led_power(bool power);
    
int mapping(float x, int in_min, int in_max, int out_min, int out_max); //  value X, entre min, entre max, sortie min, sortie max
void croissant(float *tableau );
float moyenne(float *tableau );

#ifdef __cplusplus
}
#endif

#endif
