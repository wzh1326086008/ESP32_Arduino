#include <Arduino.h>

// Potentiometer is connected to GPIO 34 (Analog ADC1_CH6)
// Potentiometer is connected to GPIO 35 (Analog ADC1_CH7)  
const int adc_potPin1 = 34;
const int adc_potPin2 = 35;
 
// variable for storing the potentiometer value
int potValue1 = 0;
int potValue2 = 0;
 
void setup() {
    Serial.begin(115200);
    delay(1000);
}
 
void loop() {
    // Reading potentiometer value
    potValue1 = analogRead(adc_potPin1);
    Serial.println("ADC1_CH6");
    Serial.println(potValue1);

    potValue2 = analogRead(adc_potPin2);
    Serial.println("ADC1_CH7");
    Serial.println(potValue2);
    delay(500);
}
