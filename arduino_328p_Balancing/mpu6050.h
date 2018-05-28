#ifndef _mpu6050_H
#define _mpu6050_H
#include <arduino.h>

#include "Kalman.h" // Source: https://github.com/TKJElectronics/KalmanFilter
#include "I2C.h"

#define RESTRICT_PITCH // Comment out to restrict roll to ±90deg instead - please read: http://www.freescale.com/files/sensors/doc/app_note/AN3461.pdf

static Kalman kalmanX; // Create the Kalman instances
static Kalman kalmanY;

  /* IMU Data */
static double accX, accY, accZ;
static double gyroX, gyroY, gyroZ;
static int16_t tempRaw;

static double gyroXangle, gyroYangle; // Angle calculate using the gyro only
static double compAngleX, compAngleY; // Calculated angle using a complementary filter
static double kalAngleX, kalAngleY; // Calculated angle using a Kalman filter

static uint32_t timer;
static uint8_t i2cData[14]; // Buffer for I2C data

// TODO: Make calibration routine

void init_MPU();
void loop_MPU();

double getY();
double getX();
double get_accX();
double get_accY();
//  ***************************** POLAIRE FUNCTION ****************************************

float polaire_getR(float x, float y);    // pour eviter le decalage de valeur pendant la lecture de x et y
float polaire_getTeta();


#endif
