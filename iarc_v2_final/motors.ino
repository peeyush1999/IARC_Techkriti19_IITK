void motorMove(int left_speed,int right_speed)
{
 
               analogWrite(in[1],left_speed);  //left motors
               analogWrite(in[2],0);
                
               analogWrite(in[3],right_speed);
               analogWrite(in[4],0);
}
void rotateCW(int left_speed,int right_speed)
{
 
               analogWrite(in[1],left_speed);  //left motors
               analogWrite(in[2],0);
                
               analogWrite(in[3],0);
               analogWrite(in[4],right_speed);
}
void rotateACW(int left_speed,int right_speed)
{
 
               analogWrite(in[1],0);  //left motors
               analogWrite(in[2],left_speed);
                
               analogWrite(in[3],right_speed);
               analogWrite(in[4],0);
}
