// KasBot V2  -  Kalman filter module

    double Q_angle  =  0.001; 
    double Q_gyro   =  0.003;  
    double R_angle  =  0.03;  

    double x_angle = 0;
    double x_bias = 0;
    double P_00 = 0, P_01 = 0, P_10 = 0, P_11 = 0;	
    double dt, y, S;
    double K_0, K_1;

  double kalmanCalculate(double newAngle, double newRate,int looptime) {
    dt = double(looptime)/1000;                                    // XXXXXXX arevoir
    x_angle += dt * (newRate - x_bias);
    P_00 +=  - dt * (P_10 + P_01) + Q_angle * dt;
    P_01 +=  - dt * P_11;
    P_10 +=  - dt * P_11;
    P_11 +=  + Q_gyro * dt;
    
    y = newAngle - x_angle;
    S = P_00 + R_angle;
    K_0 = P_00 / S;
    K_1 = P_10 / S;
    
    x_angle +=  K_0 * y;
    x_bias  +=  K_1 * y;
    P_00 -= K_0 * P_00;
    P_01 -= K_0 * P_01;
    P_10 -= K_1 * P_00;
    P_11 -= K_1 * P_01;
    
    return x_angle;
  }
  
  double Q_angle2  =  0.001; 
  double Q_gyro2   =  0.003;  
  double R_angle2  =  0.03;  

  double x_angle2 = 0;
  double x_bias2 = 0;
  double P_002 = 0, P_012 = 0, P_102 = 0, P_112 = 0;	
  double dt2, y2, S2;
  double K_02, K_12;
  
  double kalmanCalculate2(double newAngle2, double newRate2,int looptime2) {
    dt2 = double(looptime2)/1000;                                    // XXXXXXX arevoir
    x_angle2 += dt2 * (newRate2 - x_bias2);
    P_002 +=  - dt2 * (P_102 + P_012) + Q_angle2 * dt2;
    P_012 +=  - dt2 * P_112;
    P_102 +=  - dt2 * P_112;
    P_112 +=  + Q_gyro2 * dt2;
    
    y2 = newAngle2 - x_angle2;
    S2 = P_002 + R_angle2;
    K_02 = P_002 / S2;
    K_12 = P_102 / S2;
    
    x_angle2 +=  K_02 * y2;
    x_bias2  +=  K_12 * y2;
    P_002 -= K_02 * P_002;
    P_012 -= K_02 * P_012;
    P_102 -= K_12 * P_002;
    P_112 -= K_12 * P_012;
    
    return x_angle2;
  }
  
  double updateKalman()
  {
    kalmanOutput = kalmanCalculate(accelAngleATAN(), gyroRate, loopTime);
    kalmanOutput2 = kalmanCalculate2(kalmanOutput, gyroRate, loopTime);
  }
