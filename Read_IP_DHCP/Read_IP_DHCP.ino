#include <SPI.h>
 #include <Ethernet.h>

// 设置MAC地址 
#if defined(WIZ550io_WITH_MACADDRESS) // Use assigned MAC address of WIZ550io
 ;
 #else
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
 #endif  

void setup() 
 {  
   Serial.begin(9600);
   if (Ethernet.begin(mac) == 0) 
   {
       Serial.println("Failed to configure Ethernet using DHCP");
       // 连接失败，便进入一个死循环（相当于结束程序运行）
      for(;;);
   }

   // 输出你的本地IP地址
  Serial.print("My IP address: ");
   for (byte thisByte = 0; thisByte < 4; thisByte++) 
   {
     // 将四个字节的IP地址逐字节输出
    Serial.print(Ethernet.localIP()[thisByte], DEC);
     Serial.print("."); 
   }

   Serial.println();
 }

void loop() 
 {
 }
