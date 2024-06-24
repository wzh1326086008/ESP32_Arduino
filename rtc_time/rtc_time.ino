#include "Arduino.h"
#include "ztf_esp32_time.h"

ZtfEsp32Time m_time;
void setup()
{
  Serial.begin(115200);
  m_time.update_sys_time(1635148850);//更新系统时间
}
void loop()
{
  Serial.println(m_time.get_sys_stamp());//获取当前时间戳
  ztfTimeInfo m_timeInfo;//获取日期信息
  m_time.get_time_info(&m_timeInfo);
  String date = "Current Time: ";
  date = date + m_timeInfo.year + " Years " + m_timeInfo.mon + " Mon " + m_timeInfo.mday + " Day " + m_timeInfo.hour + " : " + m_timeInfo.min + " : " + m_timeInfo.sec + " Sec  Week " + m_timeInfo.wday;
  Serial.println(date);
  delay(1000);
}
