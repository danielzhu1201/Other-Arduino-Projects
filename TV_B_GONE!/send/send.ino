#include <IRremote.h>
 
IRsend irsend;
unsigned int buf[25]=
    {2400,600,1150,600,600,600,1150,600,600,600,1150,600,600,600,550,600,1200,550,600,600,600,600,600,550,600};
void setup()
{
  
}

 
void loop() {
  irsend.sendRaw(buf,25,38);
  delay(100);
}
