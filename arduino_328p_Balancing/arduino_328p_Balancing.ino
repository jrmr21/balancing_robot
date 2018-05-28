#include "mpu6050.h"
#include "moteur.h"
#include "utilitaire.h"
#include "monPid.h"
#include "encoder.h"
#include "rs232RX.h"

#define margeSetPoint 5    //  ecart echantillon filtre médian

float majSetpoint(float pointActuelle,float y,char tillon, float origin);
void runMotors(double PIDOutput);


void setup() 
{ 
  double PIDOutput=0;
  led_init();
  init_moteur();
  init_MPU();
  UART_Init(115200);
  init_encodeur();

  float origin, setPoint = 109.42;         //getY();    //  set point dans la position de demarage du robot
  origin = setPoint;

  while(1)
  {
    loop_MPU(); //  run loop sensor MPU /!\ OBLIGATOIRE a chaque tour de boucle
    float New_Y = getX() ;                  //  recup de la position réel (thx filtre de Kalman) en Y
    New_Y = mapping( New_Y, 37.7, 113.7, 0, 180);
       
    // Serial.println(New_Y);
    //setPoint = majSetpoint(setPoint ,New_Y , 4, origin);       //    MAJ du point d'équillibre toutes les U normalement

 
    switch(get_buffer())
    {
      case '1':
        setPoint = f_avant(origin);
        led_power(true);
        break;
      case '2':
        setPoint = f_gauche(origin);
        led_power(true);
        break;
      case '3':
        setPoint = f_arriere(origin);
        led_power(true);
        break;    
      case '4':
        setPoint = f_droit(origin);
        led_power(true);
        break;
      case '5':
        setPoint = f_arret(origin);
        led_power(false);
        break;  
      default:
        break;     
    }
    
    getPid( setPoint, New_Y, PIDOutput, 0);   //  mpu,  pooint objectif, point actuelle, sortie, periode d echantillonage ms
    runMotors(PIDOutput);    
  }
}
  


void runMotors(double PIDOutput)
{      
      if( PIDOutput < -88 ) // intervalle stop 
    {
      change_vitesse(false, PIDOutput * -1);   //  1 = D, 0 = G
      change_vitesse(true, PIDOutput * -1 ); 
      arriere();
    }
    else if( PIDOutput > 88 )
    { 
      change_vitesse(true, PIDOutput );   //  1 = D, 0 = G
      change_vitesse(false, PIDOutput );  
      avant();                      
    }
    else 
    {
      power_off();
    }    
}


float majSetpoint(float pointActuelle,float y,char tillon, float origin)
{
  static double timer=millis();
  static float echantillons[12]={0};
  static int i=0;
    if( millis() - timer > tillon )   //  15ms                                  10    50    120
  {
    timer = millis();
    echantillons[i] = y;       //  /!\ WARNING I is dangerous
    i++;
    if(i>12)
    {
      croissant( echantillons );  //  on trie nos echantillons 
            
      if( ( echantillons[6]  < origin + margeSetPoint ) && ( echantillons[6]  > origin - margeSetPoint ) )
      {
        pointActuelle = echantillons[6];    //    on recup la val du millieu
      }

      echantillons[12]={0};                //  on nettoie nos echantillons
      i=0;
      return pointActuelle;               //  on return le nv Setpoint (point d'équilibre)
    }
  }  
  return pointActuelle;       //  on a pas finis l'échantillonage on return le setpoin de base
}

