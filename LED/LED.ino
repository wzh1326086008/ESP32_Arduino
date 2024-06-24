#include <WiFi.h>

void setup()
{
  pinMode(2, OUTPUT );   // 开启引脚输出模式（有个别引脚不可以设置输出模式）
}

void loop()
{
  digitalWrite(2,HIGH);  //输出高电平，LOW就是低电平
  delay(1000);
  digitalWrite(2,LOW);  //输出高电平，LOW就是低电平
  delay(1000);

  //digitalWrite(2, 1 ^ digitalRead(2)); //翻转 GPIO_2 电平
}
