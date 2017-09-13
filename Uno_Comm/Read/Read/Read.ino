char ss;
void setup()
{
Serial.begin(9600);
pinMode(13,OUTPUT);
}
void loop()
{
  ss=Serial.read();
  if(ss=='a')
  {
  digitalWrite(13, HIGH);
  ss=0;
  delay(300);
  digitalWrite(13, LOW);
  delay(300);
  }
   Serial.print('b');//收到‘a'后向主机发一个’b'
 } 

