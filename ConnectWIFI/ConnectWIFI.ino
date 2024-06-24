#include <WiFi.h>

const char *ssid = "CMCC"; //你的网络名称
const char *password = "12345678h"; //你的网络密码

void setup()
{
  pinMode(2, OUTPUT );   // 开启引脚输出模式（有个别引脚不可以设置输出模式）

  Serial.begin(115200);
  Serial.println();

  WiFi.begin(ssid, password); //连接网络

  while (WiFi.status() != WL_CONNECTED) //等待网络连接成功
  {
    delay(500);
    digitalWrite(2, 1 ^ digitalRead(2)); //翻转 GPIO_2 电平
    Serial.print(".");
  }
  digitalWrite(2,HIGH);  //输出高电平，LOW就是低电平
  Serial.println("WiFi connected!");

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //打印模块IP
}

void loop()
{
}
