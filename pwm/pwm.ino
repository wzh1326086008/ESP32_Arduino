#include <Arduino.h>
#include "AutoPwm.h"
int light = 0;
int status = 0;//0是变量趋势，1是变暗趋势

void setup() {
  Serial.begin(9600);
  PWM_Init(0, 2);//通道0-15，IO
  PWM_Control(0, 500);

  PWM_Init(1, 4);//通道0-15，IO
  PWM_Control(1, 1023-500);
}

void loop() {
}
