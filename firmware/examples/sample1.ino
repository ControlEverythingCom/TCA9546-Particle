// This #include statement was automatically added by the Particle IDE.
#include "TCA9546.h"

TCA9546 i2cmux;

void setup() {
    i2cmux.setAddress(1,0,0);
}

void loop() {
    for(int i = 1; i < 5; i++){
        i2cmux.setPort(i);
        Serial.printf("Port %i: \n", i);
        i2cmux.scanPort();
        delay(3000);
    }
}