void readline()
{
  val[0] = digitalRead(23);
 Serial.println();
  Serial.print(val[0]);
 Serial.print("  ");
if(val[0]==1)
    {
      flag++;
    }
 
  for(int i=1;i<8;i++)
  {
    val[i] = digitalRead(ir[i]);
   Serial.print(val[i]);
   Serial.print("  ");
    if(val[i]==1)
    {
      flag++;
    }
   
   
  }
 


 
}



long getLine()
{
 long distance = 0;
 
  distance = analogRead(analogPin);
  //Serial.print(distance);
  //Serial.print("---------->");
  distance = ((float)(distance)/921)*70;;
 // Serial.print(distance);
// Serial.println();
  
  return distance;
  
}


void getNode()
{ flag=0;
  int jxn=0;
  int circle=0;
  int onetwenty=0;
  int noline=0;
  int left =0;
  int right = 0;
  int node =0;
 readline();
// pid_lfr(); // pid always called
      if(val[3] + val[4] <=1 && val[2] + val[1] >= 1 && val[5]  + val[6] >=1  && val[0] == val[7])
      {
        node++;
      }
     if(flag==0)
            {
              motorMove(80,80);
              noline++;
            }
      if(flag > 5 && ( val[3]==1 && val[4] == 1 ) )     // center sensor at junction will be black 
      { 
        int temp=0;
        int i=0;
        flag = 0;
        readline();
        while(flag>2)
        {
          flag=0;
          readline();
          if(val[0]==1&&val[3]==0&&val[4]==0&&val[7]==1)
            {
              onetwenty++;
            }
          else if(flag>6)
            {
              motorMove(60,60);
              readline();
              flag=0;
              readline();
              if(flag>7)
              {
                circle++;
                Serial.println("circle");
              }
              else
              {
                jxn++;
                Serial.println("jxn");
              }
              
            }

          else if(flag>2&&val[1]==1)
            {
              left++;
            }
          else if(flag>2&&val[6]==1)
            {
              right++;
            }
         //motorMove(0,0);
         delay(20);
        }

      }
      if (node!=0)
      {
        motorMove(100,100);
      }
      if(noline>0)
        {
          rotateCW(20,20);
            while(val[4]!=1)
              {
                readline();
                rotateCW(51,51);
              }
              Serial.println("nl");
        }
         
        if(jxn>onetwenty&&jxn>circle)
          { 
            
            rotateCW( 20 , 20 );
            while(val[4]!=1)
              {
                readline();
                rotateCW(60,60);
              }
              Serial.println("jxn");
          }
          if(onetwenty>jxn&&onetwenty>circle)
            {
              rotateCW(20,20);
            while(val[4]!=1)
              {
                readline();
                rotateCW(60,60);
              }
              Serial.println("120");
              
            }
           if(circle>onetwenty&&circle>jxn)
            {
              motorMove(0,0);
              //delay(10000);
              zone++;
            }
           if(left>right&&left>jxn&&left>onetwenty)
            {
              
            rotateACW(20,20);
            while(val[4]!=1)
              {
                readline();
                rotateACW(60,60);
              }
              
            }
            if(right>left)
              {
                
            rotateCW(20,20);
            while(val[4]!=1)
              {
                readline();
                rotateCW(60,60);
              }
              }
          }
         


  
