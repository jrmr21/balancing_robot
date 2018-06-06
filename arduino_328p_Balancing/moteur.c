#include "moteur.h"

void init_moteur()
{
  pinMode(5,OUTPUT);    //  on declare toutes nos entrées sorties
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);

  power_off();  //  on met tt les port a 0
}


void avant()    //  2 moteurs sens de rotation avant
{
    moteurD(1);   
    moteurG(1);  
}
void arriere()    //  2 moteurs sens de rotation arriere
{
    moteurD(0);   
    moteurG(0);
}

void power_off()
{
  monPWM(5,0);
  monPWM(6,0);
  monPWM(10,0);
  monPWM(9,0);
}

float f_droit(float origin)
{
  commandeD = 1;   //  vitesse de direction gauche élevé
  commandeG = 0.82;
  return origin;  
}

float f_gauche(float origin)
{
  commandeD = 0.8;   //  vitesse de direction gauche élevé
  commandeG = 1;
  return origin;
}

float f_avant(float origin)
{
  commandeD = 1;   //  vitesse de direction gauche élevé
  commandeG = 1;
  return origin + 6;
}

float f_arriere(float origin)
{
  commandeD = 1;   //  vitesse de direction gauche élevé
  commandeG = 1;
  return origin - 4 ;
}


float f_arret(float origin)   //  fonction casi inutile....
{
  commandeD = 1;   //  vitesse de direction gauche élevé
  commandeG = 1;
  return origin;
}


void change_vitesse(bool motor, char vite)
{
  if(motor) vitesseD = vite * commandeD;              //  1 = D, 0 = G
  else vitesseG = vite * commandeG;
}

void moteurD(byte sense)
{
  if(sense == 1)          //  avant 
  {
    monPWM(5,vitesseD);
    monPWM(6,0);
  }
  else                            //  arriere
  {
    monPWM(5,0);
    monPWM(6,vitesseD);    
  }
}

void moteurG(byte sense)
{
  if(sense == 1)          //  avant 
  {
    monPWM(10,vitesseG );
    monPWM(9,0);
  }
  else                            //  arriere
  {
    monPWM(10,0);
    monPWM(9,vitesseG);
  }
}


void monPWM(uint8_t pin, int val)
{
  // We need to make sure the PWM output is enabled for those pins
  // that support it, as we turn it off when digitally reading or
  // writing with them.  Also, make sure the pin is in output mode
  // for consistenty with Wiring, which doesn't require a pinMode
  // call for the analog output pins.

  if (val == 0)
  {
    digitalWrite(pin, LOW);
  }
  else if (val == 255)
  {
    digitalWrite(pin, HIGH);
  }
  else
  {
    switch(digitalPinToTimer(pin))
    {
      #if defined(TCCR0) && defined(COM00) && !defined(__AVR_ATmega8__)
      case TIMER0A:
        // connect pwm to pin on timer 0
        sbi(TCCR0, COM00);
        OCR0 = val; // set pwm duty
        break;
      #endif

      #if defined(TCCR0A) && defined(COM0A1)
      case TIMER0A:
        // connect pwm to pin on timer 0, channel A
        sbi(TCCR0A, COM0A1);
        OCR0A = val; // set pwm duty
        break;
      #endif

      #if defined(TCCR0A) && defined(COM0B1)
      case TIMER0B:
        // connect pwm to pin on timer 0, channel B
        sbi(TCCR0A, COM0B1);
        OCR0B = val; // set pwm duty
        break;
      #endif

      #if defined(TCCR1A) && defined(COM1A1)
      case TIMER1A:
        // connect pwm to pin on timer 1, channel A   555555555555555
        sbi(TCCR1A, COM1A1);
        OCR1A = val; // set pwm duty
        break;
      #endif

      #if defined(TCCR1A) && defined(COM1B1)
      case TIMER1B:
        // connect pwm to pin on timer 1, channel B
        sbi(TCCR1A, COM1B1);
        OCR1B = val; // set pwm duty
        break;
      #endif

      #if defined(TCCR1A) && defined(COM1C1)
      case TIMER1C:
        // connect pwm to pin on timer 1, channel B
        sbi(TCCR1A, COM1C1);
        OCR1C = val; // set pwm duty
        break;
      #endif

      #if defined(TCCR2A) && defined(COM2B1)
      case TIMER2B:
        // connect pwm to pin on timer 2, channel B
        sbi(TCCR2A, COM2B1);
        OCR2B = val; // set pwm duty
        break;
      #endif

      #if defined(TCCR3A) && defined(COM3A1)
      case TIMER3A:
        // connect pwm to pin on timer 3, channel A
        sbi(TCCR3A, COM3A1);
        OCR3A = val; // set pwm duty
        break;
      #endif

      #if defined(TCCR3A) && defined(COM3B1)
      case TIMER3B:
        // connect pwm to pin on timer 3, channel B
        sbi(TCCR3A, COM3B1);
        OCR3B = val; // set pwm duty
        break;
      #endif

      #if defined(TCCR4A) && defined(COM4B1)
      case TIMER4B:
        // connect pwm to pin on timer 4, channel B
        sbi(TCCR4A, COM4B1);
        OCR4B = val; // set pwm duty
        break;
      #endif

      #if defined(TCCR4C) && defined(COM4D1)
      case TIMER4D:       
        // connect pwm to pin on timer 4, channel D
        sbi(TCCR4C, COM4D1);
        #if defined(COM4D0)   // only used on 32U4
        cbi(TCCR4C, COM4D0);
        #endif
        OCR4D = val;  // set pwm duty
        break;
      #endif
 
      case NOT_ON_TIMER:
      default:
        break;
    }
  }
}

