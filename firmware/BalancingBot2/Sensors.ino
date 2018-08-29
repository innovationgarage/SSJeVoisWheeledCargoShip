//*********************************************************************************************************************************************************************
//
// SECTION: Gyroscope
//
// DESCRIPTION: Contains gyro instantiation and gyro access functinos.
//
//*********************************************************************************************************************************************************************

ADW22307 gyro(GYRO_PIN, GYRO_OPERATING_VOLTAGE, GYRO_ZERO_VOLTAGE, GYRO_SENSITIVITY, ROTATION_THRESHOLD);

void updateGyro()
{
  gyroRate = getGyroRate();
  gyroRateFiltered = getGyroRateFiltered();
}

double getGyroRate()
{
  return gyro.getRateRad();
}

double getGyroRateFiltered()
{
  return constrain(gyroRate, LOWER_GYRO_LIMIT, UPPER_GYRO_LIMIT);
}


int getGyroAngle()
{
  return gyro.getTotalAngle();
}


double getGyroVoltage()
{
  return gyro.getVoltage();
}

//*********************************************************************************************************************************************************************
//
// SECTION: Accelerometer
//
// DESCRIPTION: Contains accelerometer instantiation and accelerometer access functions.
//
//*********************************************************************************************************************************************************************

ADXL345 Acc;


void accelInit()
{
  Acc.setPOWER_CTL(POWER_CTL);                                                  //set registers on the ADXL345 to the defined values in Def (see datasheet for tuning and explanations)
  Acc.setDATA_FORMAT(DATA_FORMAT);
  Acc.setOFSX(OFSX);
  Acc.setOFSY(OFSY);
  Acc.setOFSZ(OFSZ);
  Acc.setINT_ENABLE(INT_ENABLE);
}


void getAccel(int& pX, int& pY, int& pZ)
{
  byte X0, X1, Y0, Y1, Z0, Z1;
  
  Acc.readDATAX(&X0, &X1);                                                     //use readDATA functions (see library)
  pX = - (X0 + (X1 << 8));                                                     //X axis is inverted to be consistent with diagram on ADXL345
  
  Acc.readDATAY(&Y0, &Y1);
  pY = (Y0 + (Y1 << 8));                                                       //Y axis is inverted to be consistent with diagram on ADXL345
  
  Acc.readDATAZ(&Z0, &Z1);
  pZ = (Z0 + (Z1 << 8));
}

//*********************************************************************************************************************************************************************
//
// SECTION: Potentiometer
//
// DESCRIPTION: Contains potentiometer setup and access functions.
//
//*********************************************************************************************************************************************************************

void potInit()
{
  pinMode(POT1_HIGH_PIN, OUTPUT);
  digitalWrite(POT1_HIGH_PIN, HIGH);
  pinMode(POT1_LOW_PIN, OUTPUT);
  digitalWrite(POT1_LOW_PIN, LOW);
  
  pinMode(POT2_HIGH_PIN, OUTPUT);
  digitalWrite(POT2_HIGH_PIN, HIGH);
  pinMode(POT2_LOW_PIN, OUTPUT);
  digitalWrite(POT2_LOW_PIN, LOW);
  
  pinMode(POT3_HIGH_PIN, OUTPUT);
  digitalWrite(POT3_HIGH_PIN, HIGH);
  pinMode(POT3_LOW_PIN, OUTPUT);
  digitalWrite(POT3_LOW_PIN, LOW);
}

int getPotRaw(int pPot)
{
  if(pPot == POT1) return analogRead(POT1_SIG_PIN);
  else if(pPot == POT2) return analogRead(POT2_SIG_PIN);
  else if(pPot == POT3) return analogRead(POT3_SIG_PIN);
}

int getPotMapped(int pPot)
{
  if(pPot == POT1) return map(analogRead(POT1_SIG_PIN), 1, 1020, SERVO_LOWER_LIMIT, SERVO_UPPER_LIMIT);
  else if(pPot == POT2) return map(analogRead(POT2_SIG_PIN), 1, 1020, SERVO_LOWER_LIMIT, SERVO_UPPER_LIMIT);
  else if(pPot == POT3) return map(analogRead(POT3_SIG_PIN), 1, 1020, SERVO_LOWER_LIMIT, SERVO_UPPER_LIMIT);
}

double getPotPID(int pPot)
{
  if(pPot == POT1) return (double) map(analogRead(POT1_SIG_PIN), 1, 1020, 0, 1000);
  else if(pPot == POT2)  return (double) map(analogRead(POT2_SIG_PIN), 2, 1020, 0, 1200);
  else if(pPot == POT3)  return (double) map(analogRead(POT3_SIG_PIN), 1, 1020, 0, 100);
}
