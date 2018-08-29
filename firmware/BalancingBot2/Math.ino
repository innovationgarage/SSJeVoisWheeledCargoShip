double accelAngleACOS()
{
  int x, y, z;
  getAccel(x, y, z);
  
  double h, uX, uY;
  h = sqrt(square(x) + square(y));
  uX = x/h;
  uY = y/h;
  
  double theta;
  theta = acos(uX);
  
  return theta;
}

double accelAngleATAN()
{
  int x, y, z;
  getAccel(x, y, z);
  
  double theta = atan2(y,x);
  return theta;
  
}
