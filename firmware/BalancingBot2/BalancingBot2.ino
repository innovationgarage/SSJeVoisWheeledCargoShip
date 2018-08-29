#include <ADXL345.h>
#include <ADW22307_noDelay.h>
#include <PID_v1.h>
#include <Wire.h>
#include <Servo.h>
#include <PS3BT.h>

long loopStartTime = 0;
long loopTime = 0;

double gyroRate = 0;
double gyroRateFiltered = 0;
double kalmanOutput = 0;
double kalmanOutput2 = 0;

void setup()
{
  Serial.begin(115200);
  Serial3.begin(115200);
  accelInit();
  servoInit();
  potInit();
  pidInit();
  PS3Init();
}

void loop()
{
  loopStartTime = millis();
  
  //*********************************************************************************************************************************************************************
  //
  //Write all code within these DOUBLE lines. Code outside these lines is for timing purposes ONLY.
  //
  //*********************************************************************************************************************************************************************
  //*********************************************************************************************************************************************************************
  
  taskPS3();
  updateGyro();
  updateKalman();
  updateServos2(getSetpoint());
  //writeServos(0);
  
  
  //printAccelData();
  //printGyroData();
  //Serial.print("\t");
  //printAccelAngle();
  //printKalmanCalculate();
  //Serial.print("\t");
  printPIDTuning();
  printSetpoint();
  setPIDSettings();
  //Serial.print("\t");
  //printPotData();
  //printSetpoint();
  //Serial.print("\t");
  //printLoopTimingData();
  
  
  sendProcessingData();
  Serial.print("\n");
  
  
  //writeServos(getPotMapped());
  //zeroServos();
  //delay(10);
  
  
  
  
  
  //*********************************************************************************************************************************************************************
  //*********************************************************************************************************************************************************************
  
  loopTime = millis() - loopStartTime;
 
}
