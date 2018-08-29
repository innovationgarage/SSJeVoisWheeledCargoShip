double Output = 0, Input = 0, Setpoint = 0;

PID pid(&Input, &Output, &Setpoint, KP, KI, KD, DIRECT);

void updatePID(double pSetpoint)
{
  Input = kalmanOutput;
  Setpoint = pSetpoint;
  pid.Compute();
}

void updatePID2(double pSetpoint)
{
  Input = kalmanOutput2;
  Setpoint = pSetpoint;
  pid.Compute();
}

void pidInit()
{
  pid.SetOutputLimits(SERVO_LOWER_LIMIT, SERVO_UPPER_LIMIT);
  pid.SetSampleTime(PID_SAMPLE_TIME);
  pid.SetMode(AUTOMATIC);
}

int pidCalculateOutput(double pSetpoint)
{
  updatePID(pSetpoint);
  return Output;
}

int pidCalculateOutput2(double pSetpoint)
{
  updatePID2(pSetpoint);
  return Output;
}

void setPIDSettings()
{
  pid.SetTunings(getPotPID(POT1), getPotPID(POT2), getPotPID(POT3));
}


