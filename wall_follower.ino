void getDistance()
{
  front_Distance = sonar[1].ping_cm();
  right_Distance = sonar[2].ping_cm();
  left_Distance = sonar[0].ping_cm();
Serial.print( String(left_Distance) + "     " + String(front_Distance) + "     " + String(right_Distance) + "     "  );
Serial.println();
   delay(20);
}


void pid_wfr(double distance)
{
    double error=0,lastError=0;
    double kp=6.5,kd=20.5,ki=0.0003;//kp=10.5,kd=31.5,ki=0 with base 100  === kp=10.5,kd=31.5,ki=0 ===kp=10.5,kd=32.5,ki=0
    int baseSpeed = 100;
    int leftSpeed=0;
    int rightSpeed=0;
    double I=0;

   
  error = setDistance - distance;
  error = (lastError + error)/2;
  Serial.println("Error : " + String(error));
  if(error > 10)
  {
    error = 10;
  }
  if(error < -10)
  {
    error = -10;
  }
 // Serial.println("Error :    " + String(error));
  //error = map(error,-35,35,-10,10);

  double diff;
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
  if(leftSpeed >200)
    leftSpeed = 200;
  if(rightSpeed < 0)
    rightSpeed =25;
  if(rightSpeed >200)
    rightSpeed = 200;

      Serial.println(String(rightSpeed)  + "       " + String(leftSpeed));
    
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
        if(right_Distance < setDistance + 30 ) // front  + right blocked   === rotate left
        { Serial.println("front  + right blocked   === rotate left");
          while(front_Distance > setDistance)
          {
            Serial.println("ACW");
            getDistance();
             rotateACW(100,100);
             
          }
        }
        
      } //==========================end of front blocked
      else
      {
        if(right_Distance > setDistance + 30 ) // front + right free   === rotate right
        { Serial.println("front + right free   === rotate right");
          while(right_Distance > setDistance)
          {
            getDistance();
            Serial.println("CW");
            rotateCW(100,100);
            
             //motorMove(0,0);
          }
        }
        
      }

}
    
   

void left_follow()
{
   pid_wfr(left_Distance);
   
      if(front_Distance<setDistance+5)  // front blocked 
      {
        if(left_Distance < setDistance + 30 ) // front  + right blocked   === rotate left
        { Serial.println("front  + left blocked   === rotate left");
          while(front_Distance > setDistance)
          {
            Serial.println("CW");
            getDistance();
             rotateCW(100,100);
             
          }
        }
        
      } //==========================end of front blocked
      else
      {
        if(left_Distance > setDistance + 30 ) // front + right free   === rotate right
        { Serial.println("front + right free   === rotate right");
          while(left_Distance > setDistance)
          {
            getDistance();
            Serial.println("ACW");
            rotateACW(100,100);
            
             //motorMove(0,0);
          }
        }
        
      }
}
