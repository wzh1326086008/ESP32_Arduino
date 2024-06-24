
#include "Arduino.h"
#include <WiFi.h>
#include "time.h"
#include "ztf_time.h"


const char* ssid       = "CMCC";
const char* password   = "12345678h";
 
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 28800;
const int   daylightOffset_sec = 0;
 
void printLocalTime()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %Y-%m-%d %H:%M:%S");

}
 
void setup()
{
  Serial.begin(115200);

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");
  

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();


  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  
}
 
void loop()
{
  printLocalTime();
  delay(1000);
}
