#ifndef RGB_H_INCLUDED
#define RGB_H_INCLUDED

#include <Wire.h>
#include <Arduino.h>
#include "utilitaire.h"

#define APDS9960_ADR  0x39
#define APDS9960_ID   0xAB

static String        SERIAL_STRING;
static unsigned char DATA_U,DATA_D,DATA_L,DATA_R;
static unsigned char OLD_U,OLD_D,OLD_L,OLD_R;
static unsigned char work;
static unsigned char U_PEAK_END_FLAG,D_PEAK_END_FLAG,L_PEAK_END_FLAG,R_PEAK_END_FLAG;
static unsigned char STATUS_UD,STATUS_LR;
static unsigned char OLD_STATUS_UD,OLD_STATUS_LR;
static unsigned char DISP_FLAG;
static unsigned char NOISE_LEVEL = 2;
static unsigned char DECIDE_FLAG;
static unsigned int  PHASE_COUNTER;
static unsigned int  U_PEAK,D_PEAK,L_PEAK,R_PEAK;
static int distance=0;

static void I2C_WRITE(unsigned char REG_ADR, unsigned char DATA);
static unsigned char I2C_READ(unsigned char REG_ADR);
static void RESET_VARIABLE(void);
static String DISP_DIR(void);
static void DATA_SYORI(void);

extern void start_rgb();        //void setup
extern String continued_rgb();      //  void loop
extern int get_Distance();        //void setup
#endif
