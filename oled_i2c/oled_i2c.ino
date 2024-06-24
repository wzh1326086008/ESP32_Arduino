#include <Wire.h>
#include "SSD1306.h" 

//GPIO21-->SDA
//GPIO22-->SCL

SSD1306  display(0x3c, 21, 22);
 
void setup() {
 
  display.init();
  //display.drawString(x, y, "Hello World");
  display.drawString(0, 10, "Hello World");
  display.display();
}

void loop() {}
