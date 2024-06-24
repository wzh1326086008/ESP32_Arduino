#include <WiFi.h>
 
#define LED1 19
#define LED2 22
#define LED1_OFF   digitalWrite(LED1, HIGH)//关灯1
#define LED1_ON    digitalWrite(LED1, LOW)//开灯1
#define LED1_PWM   digitalWrite(LED1, !digitalRead(LED1))//灯1闪烁
#define LED2_OFF   digitalWrite(LED2, HIGH)//关灯2
#define LED2_ON    digitalWrite(LED2, LOW)//开灯2
#define LED2_PWM   digitalWrite(LED2, !digitalRead(LED2))//灯2闪烁
 
int freq1 = 2000;    // 频率
int channel1 = 0;    // 通道0，共16个通道，0~15
int resolution1 = 10;   // 分辨率，取值0~20，duty最大取值为2^resolution-1
 
int freq2 = 2000;    // 频率
int channel2 = 1;    // 通道1，共16个通道，0~15
int resolution2 = 10;   // 分辨率，取值0~20，duty最大取值为2^resolution-1
 
void setup()
{
  ledcSetup(channel1, freq1, resolution1); // 设置通道0
  ledcSetup(channel2, freq2, resolution2); // 设置通道1
  ledcAttachPin(LED1, channel1);  // 将通道0与引脚19连接
  ledcAttachPin(LED2, channel2);  // 将通道1与引脚22连接
}
 
void loop()
{
  // 逐渐变亮
  for (int dutyCycle = 0; dutyCycle <= 1023; dutyCycle = dutyCycle + 5)
  {
    ledcWrite(channel1, dutyCycle);  // 输出PWM
    ledcWrite(channel2, 1023 - dutyCycle);  // 输出PWM
    delay(5);
  }
 
  // 逐渐变暗
  for (int dutyCycle = 1023; dutyCycle >= 0; dutyCycle = dutyCycle - 5)
  {
    ledcWrite(channel1, dutyCycle);  // 输出PWM
    ledcWrite(channel2, 1023 - dutyCycle);  // 输出PWM
    delay(5);
  }
}
