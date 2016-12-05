#include "TCA9546.h"
bool TCA9546::setAddress(int a0, int a1, int a2){
    if(!Wire.isEnabled()){
        Wire.begin();
    }
    if(a0 == 1){
        address = address | 1;
    }
    if(a1 == 1){
        address = address | 2;
    }
    if(a2 == 1){
        address = address | 4;
    }
    Wire.beginTransmission(address);
    byte status = Wire.endTransmission();
    if(status == 0){
        return true;
    }else{
        return false;
    }
}

bool TCA9546::setPort(int port){
    switch(port){
        case 1:
            port = 1;
            break;
        case 2:
            port = 2;
            break;
        case 3:
            port = 4;
            break;
        case 4:
            port = 8;
    }
    Wire.beginTransmission(address);
    Wire.write(port);
    byte status = Wire.endTransmission();
    if(status == 0){
        return true;
    }else{
        return false;
    }
}

void TCA9546::scanPort(){
    bool devices = false;
    for(int i = 0; i < 128; i++){
        Wire.beginTransmission(i);
        byte status = Wire.endTransmission();
        if(status == 0){
            if(i != address){
                devices = true;
                Serial.printf("Device at address: %i \n",i);
            }
        }
    }
    if(!devices){
        Serial.println("No Devices on Port.");
    }
}

