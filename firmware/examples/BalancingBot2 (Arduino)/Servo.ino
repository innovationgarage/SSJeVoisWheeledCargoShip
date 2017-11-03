//*********************************************************************************************************************************************************************
//
// SECTION: Servo
//
// DESCRIPTION: Contains all Servo code.
//
//*********************************************************************************************************************************************************************

Servo servoR;
Servo servoL;

void servoInit()
{
  servoR.attach(SERVO_R);
  servoL.attach(SERVO_L);
}

void zeroServos()
{
  servoR.writeMicroseconds(1500);
  servoL.writeMicroseconds(1500);
}

void writeServos(int mcs)
{
  if(mcs > 500) mcs = 500;
  else if (mcs < -500) mcs = -500;
  servoR.writeMicroseconds(1500 + mcs);
  servoL.writeMicroseconds(1500 - mcs);
}

void updateServos(double pSetpoint)
{  
  if(kalmanOutput > PI/6.0 || kalmanOutput < -PI/6.0) writeServos(0);
  else writeServos(pidCalculateOutput(pSetpoint));
}

void updateServos2(double pSetpoint)
{  
  if(kalmanOutput2 > PI/6.0 || kalmanOutput2 < -PI/6.0) writeServos(0);
  else writeServos(pidCalculateOutput2(pSetpoint));
}



