#ifndef _utilitaire_H
#define _utilitaire_H

#ifdef __cplusplus
extern "C" {        //  pour coder en C dans un langage C++ (prore a arduino j imagine)
#endif

#define LED DDB3    //  pin 16 led to debug
#include <stdbool.h>
#include <avr/io.h>

void led_init();
void led_power(bool power);

    //  value X, entre min, entre max, sortie min, sortie max
float mapping(float x, int in_min, float in_max, float out_min, float out_max);

void croissant(float *tableau );

float moyenne(float *tableau );

#ifdef __cplusplus
}
#endif

#endif
