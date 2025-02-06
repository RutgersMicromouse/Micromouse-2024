#pragma once
#include<Arduino.h>
// #include<cstdint>
const uint8_t lsensor = 21, rsensor = 23;
extern int16_t lreading, rreading, center_reading;
extern double angle;
extern int64_t left_encoder, right_encoder;

struct pid{
    double p;
    double i;
    double d;
};
const uint32_t interrupt_interval = 10000;
void get_readings();