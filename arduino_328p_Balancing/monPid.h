#ifndef _monpid_H
#define _monpid_H
#include <arduino.h>
#include "utilitaire.h"

#define Ki 3.5         // Ki pour avoir une réponse exacte en peu de temps       (3)
#define Kd 940        //   Kd qui permet de rendre le système plus stable          (888)
#define Kp 13   //  Kp afin d'améliorer le temps de réponse du système     (12)

#define MAX 240 
#define MIN 73

/*
 source : http://www.ferdinandpiette.com/blog/2011/08/implementer-un-pid-sans-faire-de-calculs/
Tous les x millisecondes, faire :
    erreur = consigne - mesure;
    somme_erreurs += erreur;
    variation_erreur = erreur - erreur_précédente;
    commande = Kp * erreur + Ki * somme_erreurs + Kd * variation_erreur;
    erreur_précédente = erreur

    */

void getPid(int consigne, float mesure, double &commande, byte tillon);     //     PID==true MPU   || pid == false  PWM

//void getPidCorrection(int consigne, int mesure, double &commande, byte tillon);   //  PID full PWM

#endif
