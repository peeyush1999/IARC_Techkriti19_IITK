void readline()
{
  val[0] = digitalRead(23);
//  Serial.println();
 // Serial.print(val[0]);
// Serial.print("  ");
if(val[0]==1)
    {
      flag++;
    }
 
  for(int i=1;i<8;i++)
  {
    val[i] = digitalRead(ir[i]);
  // Serial.print(val[i]);
    //Serial.print("  ");
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
{ 
  pid_lfr(); // pid always called
 readline();
      if(flag <=)
      {
        
      }
      else if(flag > 3  && (val[3]==0 || val[4] == 0 ))  // here flags > 3 and center ir on white surface
      { // motorMove(100,100);
            while(1)
            { flag=0;
              readline();
              //=========================True Node==========================
              if(flag == 0)     // checking all zero
              {
                while(1)
                {flag=0;
                 readline();
                 if(flag>3)   //checking end of node
                 {
                  Serial.println("truenode");
                  trueNode++; // incrementing value
                  break; 
                 }
                }
                break;
              }
              else if(flag == 2 && (val[3]==1 && val[4] == 1) )     // false node center sensor will be black
              {
                while(1)
                {
                  flag=0;
                   readline();
                   if(flag>3)   //checking end of node
                   {
                    Serial.println("false node");
                    falseNode++; // incrementing value of falsenode
                    break; 
                   }
                  }
                  break;
              }
            }   //=======while ends here 
      }   //=======if(flag > 3  && (val[3]==0 || val[4] == 0 ))  ends here
      //============================================================
      //=========================junction and circle==========================
      else if(flag > 3 && ( val[3]==1 || val[4] == 1 ) )     // center sensor at junction will be black 
      {
        while(1)
        { flag=0;
         delay(10);
         readline();
         if(flag>4 && val[2] == 1 )   
         {
          Serial.println("circle Detected");
          // circle detected
          motorMove(0,0);
          break; 
         }
         else
         {
          Serial.println("junction detected");
          // junction detected
          while(1)
            {
              Serial.println("junction : moving left");
              readline();
              motorMove(150,0);
              if(val[3]==1)
              { 
                 break;
              }
              
            }
          
         }
        } //===================while ends here==========================
        
      }   //=============else if(flag > 3 && ( val[3]==1 || val[4] == 1 ) )   ends here
      
      else if(flag > 3 && (val[3]==0 || val[4] == 0 ))     // center sensor at junction will be white 
      {
        // 120 detected
        while(1)
        {Serial.println("in loop 120");
          readline();
          motorMove(150,0);
          if(val[3]==1)
          { Serial.println("inside if");
             break;
          }
          
        }
        
      } //==============120 ends here
      //============================================================
    }//==========function ends here

  
