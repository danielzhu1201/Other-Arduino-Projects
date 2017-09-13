const int RED= 11;
const int GREEN= 10;
const int BLUE= 9;
//三个可以用PVM的端口

int r=0;
int g=0;
int b=0;

void setup() {
  Serial.begin(9600);
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
}

void loop() {
  while(Serial.available()>0)
  {
    r=Serial.parseInt();
    g=Serial.parseInt();
    b=Serial.parseInt();

    analogWrite(RED,r);
    analogWrite(GREEN,g);
    analogWrite(BLUE,b);
  }
  
}
