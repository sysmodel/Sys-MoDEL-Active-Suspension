/* 
* Sys-MoDEL Active Suspension BNO08x.h file
*
* Authors: Gregory Stewart, John Estafanos, Andrew Kennah, Patrick Laforest
* Creation Date: Jan 6, 2024
* Last Update: March 6, 2024
*
* Version 1.0
*
* Description: 
*
* Functions & Descriptions: 
* Name: 
* Description: 
*
* Name: 
* Description: 
* References:
*
*/

#ifndef BNO08x_H
#define BNO08x_H

#include <Arduino.h>
#include <Adafruit_BNO08x.h>

// Struct for yaw, pitch, and roll
struct euler_t {
  float _yaw;
  float _pitch;
  float _roll;
};

// Struct for pitch and roll rates and acceleration
struct rates {
  float _pitchRate;
  float _rollRate;
  float _zAcc;
};

class BNO08xIMU
{
  public:
    // Constructor 
    BNO08xIMU();

    // StructureS
    euler_t _ypr;
    rates _rpRates;

    // SH2 Report setting protocol function
    void SetReports();

    // Begin
    void BeginBNO08x();

    // Math
    void QuaternionToEuler(float qr, float qi, float qj, float qk, euler_t* ypr, bool degrees);

    // Math
    void QuaternionToEulerRV(sh2_RotationVectorWAcc_t* rotational_vector, euler_t* ypr, bool degrees);

    // GetAllData
    void GetDataIMU();

  private: 
    // Create object
    Adafruit_BNO08x  *_bno08x;

    // Variables for calibration
    double _sumYaw = 0.0;
    double _sumPitch = 0.0;
    double _sumRoll = 0.0;

    sh2_SensorValue_t _sensorValue;
    long _reportIntervalUs = 5000;
    
};

#endif