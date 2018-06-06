#include "monPid.h"

    
void getPid(int consigne, float mesure, double &commande, byte tillon) // true == MPU, FALSE == PWM
{
  static unsigned long startTime = 0 ;    //  millis function
  static int somme_erreurs=0, erreur_precedente=0;      //  les variables constantes
  
  int erreur=0, variation_erreur=0;
  double TEMPOcommande=0;

  erreur = consigne - mesure;
  somme_erreurs += erreur;
  
  if( (millis() - startTime) > tillon  )   //  fin d echantillonnage
  {
      startTime = millis();
      variation_erreur = erreur - erreur_precedente;  
      TEMPOcommande = Kp * erreur + Ki * somme_erreurs + Kd * variation_erreur;
     /* Serial.print("pid MPU :  ");
      Serial.println(TEMPOcommande);*/
    
    if(TEMPOcommande < 0)
    {
      TEMPOcommande = mapping(TEMPOcommande, -62.10, 0, MAX * -1, MIN* -1);   //  adaptation du coef de pid en 65-255 PWM
        
      if(TEMPOcommande < (MAX * -1) ) TEMPOcommande = MAX * -1 ;     //  vitesse MAX EN NEGATIF -255
      if(TEMPOcommande > (MIN* -1)) TEMPOcommande = MIN * -1;       //    //    MIN   //    //
    }
    else
    {
      TEMPOcommande = mapping(TEMPOcommande, 0, 95.4, MIN, MAX);   //  adaptation du coef de pid en 65-255 PWM

      if(TEMPOcommande > MAX) TEMPOcommande = MAX;          //    vitesse max
      if(TEMPOcommande < MIN) TEMPOcommande = MIN;          //  vitesse min
    }

      //Serial.print("pid MPU :  ");
      //Serial.println(TEMPOcommande);
      commande = TEMPOcommande;
      somme_erreurs = 0;
      erreur_precedente = erreur;
 
    return ;
  }
  erreur_precedente = erreur ;
  return ;
}


void getPidCorrection(float consigne, float mesure, float &commande, byte tillon)   //  PID full Setpoint
{
  static unsigned long startTime = 0 ;    //  millis function
  static int somme_erreurs=0, erreur_precedente=0;      //  les variables constantes
  
  int erreur=0, variation_erreur=0;
  double TEMPOcommande=0;

  erreur = consigne - mesure;
  somme_erreurs += erreur;
  
  if( (millis() - startTime) > tillon  )   //  fin d echantillonnage
  {
      startTime = millis();
      variation_erreur = erreur - erreur_precedente;  
      TEMPOcommande = Kp_mpu * erreur + Ki_mpu * somme_erreurs + Kd_mpu * variation_erreur;
      
      TEMPOcommande = mapping(TEMPOcommande, -1300, 2040, 105.42, 116.42 );   //  adaptation du coef de pid en angle rechercher
                                                                               //   109.82;          
      commande = TEMPOcommande;

      /*Serial.println("pid MPU :  ");
      Serial.println(TEMPOcommande);*/
      
      somme_erreurs = 0;
      erreur_precedente = erreur;
 
    return ;
  }
  erreur_precedente = erreur ;
  return ;
}

