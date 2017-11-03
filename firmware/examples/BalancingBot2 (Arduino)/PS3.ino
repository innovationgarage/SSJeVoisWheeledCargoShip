//*********************************************************************************************************************************************************************
//
// SECTION: PS3
//
// DESCRIPTION: Contains all PS3 controller communication control code.
//
//*********************************************************************************************************************************************************************

USB Usb;
BTD Btd(&Usb); 
PS3BT PS3(&Btd);

void PS3Init()
{
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while(1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
}

void taskPS3()
{ 
  Usb.Task();
  
  if(PS3.PS3Connected || PS3.PS3NavigationConnected) {    
    if(PS3.getButtonClick(PS)) {
      Serial.print(F("\r\nPS"));
      PS3.disconnect();
    } 
  }
}

double getSetpoint()
{
  if(PS3.PS3Connected || PS3.PS3NavigationConnected) {    
    double setpoint = PS3.getAnalogHat(LeftHatY)/255.0;
    setpoint = (setpoint*PI - PI/2.0)/30;
    return - setpoint;
  } else return 0;
}
