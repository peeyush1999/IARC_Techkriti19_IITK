double error=0,lastError=0;
double kp=9.5,kd=450,ki=0.0003;//kp=10.5,kd=31.5,ki=0 with base 100  === kp=10.5,kd=31.5,ki=0 ===kp=10.5,kd=32.5,ki=0
int baseSpeed = 100;
int leftSpeed=0;
int rightSpeed=0;
double I=0;

/*========================*/




void pid_lfr()
{



  
  error = 35 - getLine();
  error = map(error,-35,35,-10,10);

  int diff;
  double pwm;
  double P = kp*error;
  double D = kd*(error-lastError);
  I = I + error;
 
  pwm = P+(I*ki)+ D;

  diff = (int)pwm;


  leftSpeed = baseSpeed + pwm;   
  rightSpeed = baseSpeed - pwm;

  if(leftSpeed < 0)
    leftSpeed =25;
  if(leftSpeed >255)
    leftSpeed = 255;
  if(rightSpeed < 0)
    rightSpeed =25;
  if(rightSpeed >255)
    rightSpeed = 255;
    
  /*  Serial.print("Left : ");
    Serial.print(leftSpeed);
    Serial.print("right  : ");
    Serial.println(rightSpeed);
    */
    motorMove( leftSpeed , rightSpeed );
  
 // Serial.println(pwm);
  
  lastError = error;
 // Serial.print("    PWM   : ");
 // Serial.print(pwm);
 // Serial.println();
  
}
