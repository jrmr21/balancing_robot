#include "encoder.h"

void init_encodeur()
{
  pinMode(interruptPinG, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPinG), encoderG, HIGH);

  pinMode(interruptPinD, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPinD), encoderD, HIGH);
  sei();
}

static void encoderD()
{
  static volatile byte state = LOW;
  static int compteurD = 0;
  static byte passe = state;
  static double timer = micros();
  state =! passe;
  
    if(state != passe)
  {
    passe = state;
    compteurD++;
  }
  
  if( micros() - timer > 20000 )   //  20ms
  {
    //Serial.println("tour en 20ms  D: ");
    //Serial.println(compteurD);
    timer = micros();
    vitessD = compteurD;
    compteurD = 0;
  }  
}

static void encoderG()        //  /!\ IMPOSSIBLE TO DISPLAY VALUE TX is working....
{
  static volatile byte state = LOW;
  static int compteurG = 0;
  static byte passe = state;
  static double timer = micros();
  state =! passe;
  
    if(state != passe)
  {
    passe = state;
    compteurG++;
  }
  
  if( micros() - timer > 20000 )   //  20ms
  {
    timer = micros();
    vitessG = compteurG;
    compteurG = 0;
  }
}

int comparaisonMoteur()
{
 /* 
  Serial.println("VD :   |   VG :   |   dif: "); 
  Serial.print(vitessD);
  Serial.print("     |     ");
  Serial.print(vitessG);
  Serial.print("     |    " );
  Serial.println(vitessD - vitessG );
  */
  return (vitessD - vitessG );
}

void getVitess(int &moteurD, int &moteurG)
{
  moteurD = vitessD;
  moteurG = vitessG;
}


