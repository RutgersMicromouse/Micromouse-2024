#include "../lib/sensors_i2c.h"

#define TOF_PIN 22

VL53L1X front_sensor;
Adafruit_BNO055 bno;

void init_imu(){
    bno = Adafruit_BNO055(55, 0x28);
    if (!bno.begin()){
         Serial.print("No BNO055 detected");
         while(1);
    }
}
void init_tof(){
    Wire.begin();
    Wire.setClock(400000);
    pinMode(TOF_PIN, OUTPUT);
    digitalWrite(TOF_PIN, LOW);
    delay(10);
    pinMode(TOF_PIN,INPUT);
    front_sensor.setTimeout(500);
    if (!front_sensor.init())
    {
        Serial.print("Failed to detect and initialize sensor ");
        while (1);
    }
    front_sensor.setAddress(0x2A);
    front_sensor.startContinuous(50);
}