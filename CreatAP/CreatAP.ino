#include <WiFi.h>
uint64_t chipid;  

const char *ssid = "LG_ESP32_AP_TEST";
const char *password = "12345678h";

void setup() {
  WiFi.softAP(ssid, password);
  Serial.begin(115200);

  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP()); // 打印IP地址

  WiFi.softAPsetHostname("myHostName"); //设置主机名
  Serial.print("HostName: ");
  Serial.println(WiFi.softAPgetHostname()); //打印主机名

  Serial.print("mac Address: ");
  Serial.println(WiFi.softAPmacAddress()); //打印mac地址
}

void loop() {
  chipid=ESP.getEfuseMac();//The chip ID is essentially its MAC address(length: 6 bytes).
  Serial.printf("ESP32 Chip ID = %04X",(uint16_t)(chipid>>32));//print High 2 bytes
  Serial.printf("%08X\n",(uint32_t)chipid);//print Low 4bytes.

  Serial.print("Service connection num: ");
  Serial.println(WiFi.softAPgetStationNum()); //打印客户端连接数

  delay(3000);

}
