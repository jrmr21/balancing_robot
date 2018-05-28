#include "utilitaire.h"

int mapping(float x, int in_min, int in_max, int out_min, int out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void croissant(float *tableau )
{
  //  ma taille : sizeof(mesurePoint)/sizeof(int) 
  float BUFFTableau[(sizeof(tableau)/sizeof(int))]={0};     //  buffer au dimension du tableau en parametre

  for( int i=0; i < (sizeof(tableau)/sizeof(int)); i++)   //  lecture du tableau
  {
  int score = 0;                                          //    init lvl case a 0
     for( int s=0; s < (sizeof(tableau)/sizeof(int)); s++)    //  test du lvl de la variable sur toutes les cases
    {
      if(tableau[i] > tableau[s])   //  si case est > a case suivante alors lvl++
      {
        score++; 
      }
    } 
    BUFFTableau[score] = tableau[i];    //  rangement de la case en fonction de son score
  }
  
  tableau = BUFFTableau; // on transfert le buffer dans notre tableau
}


float moyenne(float *tableau )
{
  float resultat=0;
  for(int i=0;i<(sizeof(tableau)/sizeof(int));i++)
  {
    resultat += tableau[i];
  }
  return resultat / (sizeof(tableau)/sizeof(int));    //  return somme tableau / taille tableau
}

void led_init()
{
  DDRB |= (1<< LED);     // led is output
  PORTB &= ~(1<<LED); 
}

void led_power(bool power)
{
  if(power)  PORTB |= (1<<LED);//  allume led sinon eteint
  else  PORTB &= ~(1<<LED);     

}

