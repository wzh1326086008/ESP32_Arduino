#include <Arduino.h>
#include "AutoPwm.h"
int light = 0;
int status = 0;//0是变量趋势，1是变暗趋势

void setup() {
  Serial.begin(9600);
  PWM_Init(0, 2);//通道0-15，IO
}

void loop() {
  PWM_Control(0, light);
  if(status == 0){
    light += 100;
    if(light >= 1024){
      light = 1024;
      status = 1;
    }
  }else{
    light -= 100;
    if(light <= 0){
      light = 0;
      status = 0;
    }
  }
  delay(100);
}
