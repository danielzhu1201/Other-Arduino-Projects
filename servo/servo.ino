#include <Servo.h>
// Servo 红色 - 5V 褐色 - GND 黄色 - 0-13 
Servo dz;
//定义舵机 - 可以精准的移动到某一个位置
void setup() {
//  dz.attach(9);
  //连接端口号
  Serial.begin(9600);
}

void loop() {
//  print 
//  for(int i=0;i<=180;i++)
//  {dz.write(i);
//  delay(10);}
//  for(int i=180;i>=0;i--)
//  {dz.write(i);
//  delay(10);}

sValue = analogRead(A0);
 dz.write(map(sValue,0,1023,0,180));

}
