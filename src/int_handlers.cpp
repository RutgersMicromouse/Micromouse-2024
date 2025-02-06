#include "../lib/int_handlers.h"
#include "../lib/sensors_i2c.h"
#include "../lib/motors.h"
extern VL53L1X front_sensor;
extern Adafruit_BNO055 bno;
//int16_t lreading = 0, rreading = 0, center_reading;
int16_t lreading = 0, rreading = 0, center_reading = 0;
static sensors_event_t orientationData;

int64_t left_encoder = 0, right_encoder = 0;
double angle;


static pid angle_pid = {
    .p = 10.0,
    .i = 0.0,
    .d = 20.0,
};

static double prev_angle = 0; 
void get_readings() {
    lreading = pulseIn(21,HIGH);
    rreading = pulseIn(23,HIGH);
    center_reading = front_sensor.read();
    
    bno.getEvent(&orientationData, Adafruit_BNO055::VECTOR_EULER);
    angle = orientationData.orientation.x;
    if(angle >= 180.0) angle -= 360;
    left_encoder = encLeft.read();
    right_encoder = encRight.read();
// Serial.printf("%lf\n",angle);
    double p = 0.0 - angle;
    double d = (p - prev_angle)/10000;
    prev_angle = p;
    double speed = p * angle_pid.p + d * angle_pid.d;
    setRightPWM(speed);
    setLeftPWM(speed);
    // setr

}
