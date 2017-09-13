const int LED =9;//常量用const
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    char data = Serial.read();
    Serial.print(data);
    if(data == '1')
    {digitalWrite(LED,HIGH);
    Serial.println("LED ON");}
    if(data == '2')
    {digitalWrite(LED,LOW);
    Serial.println("LED OFF");
    }
    if(data == '3')
    {
      Serial.println("CHANGE LIGHT");
       for(int p=0;p<=255;p++)
   {
    analogWrite(LED,p);
    delay(10);
    }
    for(int p=255;p>=0;p--)
   {
    analogWrite(LED,p);
    delay(10);
    }
    }
    }
  }

