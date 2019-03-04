
static int count=0;

void readIR()
{
  int rsign,lsign ;
  lsign = digitalRead(rpin);
  Serial.print(lsign);
  Serial.print("        ");
  rsign = digitalRead(rpin);
  Serial.println(rsign);
    if(rsign == 1)
    {
      count++;
      distance = distance + count*1.83;
    }
    Serial.println(String(distance) + " cm   ");
  
  delay(200);
}
