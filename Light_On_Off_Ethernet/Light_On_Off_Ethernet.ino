#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,120);
EthernetServer server(80);
EthernetClient client;
String readString; 

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  server.begin();
  for( int i=2; i<=9; i++ )
          pinMode(i,OUTPUT);
  Serial.print("Server is at ");
  Serial.println(Ethernet.localIP());
}

void loop() { 
  int switchButton;
  client = server.available();// 监听连入的客户端
  if (client) 
  {
    Serial.println("new client"); // 一次http请求结束都带有一个空行   
    boolean currentLineIsBlank = true;
    while (client.connected()) 
        {
      if (client.available())
          {
        char c = client.read();        
        readString += c; //将收到的信息都保存在readString函数中
        if (c == '\n' && currentLineIsBlank)
                {
                 Serial.print(c);
                 Serial.println("going to print readString");
          Serial.println(readString);         
          SendHTML(); // 发送HTML文本
          break;
                }                
        if (c == '\n') // 检测是否有换行符
          currentLineIsBlank = true;
        else if (c != '\r') // 检测是否有回车符                        
                          currentLineIsBlank = false;
 
          }
    }   
        delay(1); // 等待浏览器接收数据   
    client.stop(); //关闭连接
        Serial.println("client disonnected");
        Serial.println(readString);
        if( readString.charAt(6)=='T' )
                digitalWrite((readString.charAt(5)-'0'), HIGH);
        if( readString.charAt(6)=='F' )
                digitalWrite((readString.charAt(5)-'0'), LOW); 


         Serial.println();
         Serial.println();
         Serial.println();
         Serial.println(readString);

    readString="";
  }
}

// 用于输出HTML文本的函数
void SendHTML()
{
// 发送标准的HTTP响应
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head><title>Turn ON/OFF Lights</title></head>");

// 每十秒刷新一次
  client.println("<body>");
  
  client.println("<div style=\"font-size: 30px;\">");  
  client.println("<br />"); 
  
  // 2 on按钮
  client.println("<a href=\"/2T\" target=\"inlineframe\"><button>2 on</button></a>");
  // 2 off按钮
  client.println("<a href=\"/2F\" target=\"inlineframe\"><button>2 off</button></a>");

  // 3 on按钮
  client.println("<a href=\"/3T\" target=\"inlineframe\"><button>3 on</button></a>");
  // 3 off按钮
  client.println("<a href=\"/3F\" target=\"inlineframe\"><button>3 off</button></a>");

  // 4 on按钮
  client.println("<a href=\"/4T\" target=\"inlineframe\"><button>4 on</button></a>");
  // 4 off按钮
  client.println("<a href=\"/4F\" target=\"inlineframe\"><button>4 off</button></a>");

  // 5 on按钮
  client.println("<a href=\"/5T\" target=\"inlineframe\"><button>5 on</button></a>");
  // 5 off按钮
  client.println("<a href=\"/5F\" target=\"inlineframe\"><button>5 off</button></a>");

  // 6 on按钮
  client.println("<a href=\"/6T\" target=\"inlineframe\"><button>6 on</button></a>");
  // 6 off按钮
  client.println("<a href=\"/6F\" target=\"inlineframe\"><button>6 off</button></a>");

  // 7 on按钮
  client.println("<a href=\"/7T\" target=\"inlineframe\"><button>7 on</button></a>");
  // 7 off按钮
  client.println("<a href=\"/7F\" target=\"inlineframe\"><button>7 off</button></a>");

  // 8 on按钮
  client.println("<a href=\"/8T\" target=\"inlineframe\"><button>8 on</button></a>");
  // 8 off按钮
  client.println("<a href=\"/8F\" target=\"inlineframe\"><button>8 off</button></a>");  

  // 9 on按钮
  client.println("<a href=\"/9T\" target=\"inlineframe\"><button>9 on</button></a>");
  // 9 off按钮
  client.println("<a href=\"/9F\" target=\"inlineframe\"><button>9 off</button></a>");

  client.println("<IFRAME name=inlineframe style=\"display:none\" >");          
  client.println("</IFRAME>");
  client.println("<br /> ");
  
  client.println("</body>");
  client.println("</html>");  
}
