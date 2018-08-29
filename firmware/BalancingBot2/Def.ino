//*********************************************************************************************************************************************************************
//
// SECTION: Accelerometer
//
// DESCRIPTION: Contains settings definitions.
//
//*********************************************************************************************************************************************************************

#define THRESH_TAP 0x40                                                          //Tap threshold value
#define OFSX 0                                                                   //X-axis offset value  
#define OFSY 0                                                                   //Y-axis offset valuevalue
#define OFSZ 0                                                                   //Z-axis offset value
#define DUR 0x30                                                                 //Tap duration value
#define LATENT 0x40                                                              //Tap Latency value
#define WINDOW 0xFF                                                              //Tap window value
#define THRESH_ACT 0                                                             //Activity threshold value
#define THRESH_INACT 0                                                           //Inactivity threshold value
#define TIME_INACT 0                                                             //Inactivity time value
#define ACT_INACT_CTL 0                                                          //Axis enable control for activity and inactivity detection value
#define THRESH_FF 0                                                              //Free-fall threshold value
#define TIME_FF 0                                                                //Free-fall time value
#define TAP_AXES B00000111                                                       //Axis control for single tap/double tap value 
#define BW_RATE 0                                                                //Data rate and power mode control value
#define POWER_CTL B00001000                                                      //Power-saving features control value
#define INT_ENABLE B00000000                                                     //Interrupt enable control value
#define INT_MAP B00100000                                                        //Interrupt mapping control value
#define DATA_FORMAT B00001010                                                    //Data format control value
#define FIFO_CTL 0                                                               //FIFO control value

//*********************************************************************************************************************************************************************
//
// SECTION: Gyroscope
//
// DESCRIPTION: Contains gyro calibration and configuration information.
//
//*********************************************************************************************************************************************************************

#define GYRO_PIN  0                                                              //Gyro is connected to analog pin 0
#define GYRO_OPERATING_VOLTAGE 5                                                 //Gyro is running at 5V
#define GYRO_ZERO_VOLTAGE 2.54                                                  //Gyro is zeroed at 2.5V
#define GYRO_SENSITIVITY 0.007                                                   //Our example gyro is 7mV/deg/sec
#define ROTATION_THRESHOLD 0.7                                                   //Minimum deg/sec to keep track of - helps with gyro drifting

#define UPPER_GYRO_LIMIT PI
#define LOWER_GYRO_LIMIT -PI

//*********************************************************************************************************************************************************************
//
// SECTION: PID
//
// DESCRIPTION: Contains PID settings
//
//*********************************************************************************************************************************************************************

#define KP 451.0
#define KI 1200.0
#define KD 0.0
#define PID_SAMPLE_TIME 50
#define STATIC_SETPOINT 0.0

//*********************************************************************************************************************************************************************
//
// SECTION: Servo
//
// DESCRIPTION: Contains all Servo definitions.
//
//*********************************************************************************************************************************************************************

#define SERVO_R 6
#define SERVO_L 7
#define SERVO_UPPER_LIMIT 200
#define SERVO_LOWER_LIMIT -200

//*********************************************************************************************************************************************************************
//
// SECTION: Potentiometer
//
// DESCRIPTION: Contains all potentiometer definitions.
//
//*********************************************************************************************************************************************************************

#define POT1_HIGH_PIN 22
#define POT1_LOW_PIN 23
#define POT1_SIG_PIN 1

#define POT2_HIGH_PIN 24
#define POT2_LOW_PIN 25
#define POT2_SIG_PIN 2

#define POT3_HIGH_PIN 26
#define POT3_LOW_PIN 27
#define POT3_SIG_PIN 3

#define POT1 0
#define POT2 1
#define POT3 2
