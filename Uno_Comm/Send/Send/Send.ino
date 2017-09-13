char ss;
int i=10;
void setup()
{
Serial.begin(9600); //设置串口速度
pinMode(13,OUTPUT);//一般13口上都有一个已经接好的LED，所以用这个口子，少接些元件
}
void loop()
{
 if(i>0)//启动时的开关信号，这样可以避免主程序陷入死循环
  {Serial.print('a');//先向从机发一个‘a’，
    i=0;}
 ss=Serial.read();//再读串口，接受从机的字符‘b’
  if(ss=='b')
  {
  digitalWrite(13, HIGH);
  delay(300);
  digitalWrite(13, LOW);
  delay(300);//让13脚的LED闪烁
  ss=0;
  i=10;//让i重新赋值
  }
} 
