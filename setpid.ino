int f=0;
void setpid()
{ 
  if(Serial.available()>0)
    {
      while(Serial.available())
      { //If some thing is received by bluetooth
    received=Serial1.read();  //Read the serial buffer
    
    str = str + received;
    Serial.println(received + "1");//Print it on the serial monitor of arduino
    //Serial1.println(received);//Print it on the serial monitor of arduino
    }
    if( str.indexOf("s") >= 0)
    {
      Serial.println("stopping");
      while(!f)
      {
      motorMove(0,0);
      setpid();
      }
      
    }
    if( str.indexOf("r") >= 0)
    {
      f=1;
    }
    str ="";
    
}

}
