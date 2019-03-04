void getDistance()
{
  front_Distance = frontDistance();
  right_Distance = rightDistance();
  left_Distance = leftDistance();
//Serial.print( String(left_Distance) + "     " + String(front_Distance) + "     " + String(right_Distance) + "     "  );
//Serial.println();
}

long frontDistance()
{
  return measure(trigf,echof);
}
long rightDistance()
{
  return measure(trigr,echor);
}

long leftDistance()
{
  return measure(trigl,echol);
}


int measure(int TRIGGER , int ECHO )
{
  long duration = 0;
  
  // Measure: Put up Trigger...
  digitalWrite(TRIGGER, HIGH);
  // ... wait for 11 µs ...
  delayMicroseconds(11);
  // ... put the trigger down ...
  digitalWrite(TRIGGER, LOW);
  // ... and wait for the echo ...
  duration = pulseIn(ECHO, HIGH);
 // return (long) (((float) duration / USONIC_DIV) * 10.0);
   return (int) (duration / 29 / 2);
}


void pid_wfr(int distance)
{
    double error=0,lastError=0;
    double kp=9.5,kd=450,ki=0.0003;//kp=10.5,kd=31.5,ki=0 with base 100  === kp=10.5,kd=31.5,ki=0 ===kp=10.5,kd=32.5,ki=0
    int baseSpeed = 100;
    int leftSpeed=0;
    int rightSpeed=0;
    double I=0;

   
  error = setDistance - rightDistance();
  if(error > 10)
  {
    error = 10;
  }
  if(error < -10)
  {
    error = -10;
  }
  Serial.println("Error :    " + String(error));
  //error = map(error,-35,35,-10,10);

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
  lastError = error;

  
  
}
void right_follow()
{
  pid_wfr(right_Distance);
   
      if(front_Distance<setDistance+5)  // front blocked 
      {
        if(right_Distance < setDistance + 5 ) // front  + right blocked   === rotate left
        {
          while(front_Distance > setDistance)
          {
             motorMove(0,200);
          }
        }
        
      } //==========================end of front blocked
      else
      {
        if(right_Distance > setDistance + 5 ) // front + right free   === rotate right
        {
          while(right_Distance > setDistance)
          {
             motorMove(200,0);
          }
        }
        
      }

}
    
   

void left_follow()
{
  pid_wfr(left_Distance);
   
      if(front_Distance<setDistance+5)  // front blocked 
      {
        if(left_Distance < setDistance + 5 ) // front  + right blocked   === rotate left
        {
          while(left_Distance > setDistance)
          {
             motorMove(0,200);
          }
        }
        
      } //==========================end of front blocked
      else
      {
        if(left_Distance > setDistance + 5 ) // front + right free   === rotate right
        {
          while(left_Distance > setDistance)
          {
             motorMove(200,0);
          }
        }
        
      }
}
