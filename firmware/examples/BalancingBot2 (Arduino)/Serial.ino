//*********************************************************************************************************************************************************************
//
// SECTION: Serial
//
// DESCRIPTION: Contains all Serial communication code.
//
//*********************************************************************************************************************************************************************

void printAccelData()
{
  int x, y, z;
  getAccel(x, y, z);
  
  Serial.print("X: ");
  Serial.print(x, DEC);
  Serial.print("\t");
  Serial.print("Y: "); 
  Serial.print(y, DEC);
  Serial.print("\t");
  Serial.print("Z: ");
  Serial.print(z, DEC);
  Serial.print("\t");
}

void printAccelAngle()
{
  //Serial.print("accelAngleACOS: ");
  //Serial.print(accelAngleACOS());
  //Serial.print("\t");
  Serial.print("accelAngleATAN: ");
  Serial.print(accelAngleATAN());
  Serial.print("\t");
}

void printGyroData()
{
  Serial.print("Rate: ");
  Serial.print(gyroRate);
  Serial.print("\t");
  Serial.print("Degrees: ");
  Serial.print(getGyroAngle());
  Serial.print("\t");
  Serial.print("Volts: ");
  Serial.print(getGyroVoltage());
  Serial.print("\t");
}

void printLoopTimingData()
{
  Serial.print("Loop time: ");
  Serial.print(loopTime);
  Serial.print("\t");
}

void printKalmanCalculate()
{
  Serial.print("Kalman: ");
  Serial.print(kalmanOutput);
  Serial.print("\t");
}

void sendProcessingData()
{
  int x, y, z;
  getAccel(x, y, z);
  
  Serial3.print(x, DEC);
  Serial3.print(',');
  Serial3.print(y, DEC);
  Serial3.print(',');
  
  Serial3.print(accelAngleATAN(), DEC);
  Serial3.print(',');
  
  Serial3.print(kalmanOutput2, DEC);
  Serial3.print('\n');
}

void printPotData()
{
  Serial.print(getPotMapped(POT1));
}

void printSetpoint()
{
  Serial.print(getSetpoint(), DEC);
  Serial.print("\t");
}

void printPIDTuning()
{
  Serial.print(getPotPID(POT1), DEC);
  Serial.print("\t");
  Serial.print(getPotPID(POT2), DEC);
  Serial.print("\t");
  Serial.print(getPotPID(POT3), DEC);
  Serial.print("\t");
  Serial.print(pidCalculateOutput(STATIC_SETPOINT));
  Serial.print("\t");
}
