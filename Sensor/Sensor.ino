int LED = 4;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly: 
  val = analogRead(A1); //0-1123
  Serial.println(val);
/*  if(val<1000)
  digitalWrite(LED,LOW);
  else
  digitalWrite(LED,HIGH);
  delay(10);
*/
}
