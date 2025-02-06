#include "../lib/int_handlers.h"
#include "../lib/sensors_i2c.h"
#include "../lib/motors.h"
#include "../lib/maze_algo.h"
IntervalTimer myTimer;
static char curr_dir = 'n';
static bool start = true;
void setup() {
    Serial.begin(115200);  // Start serial communication
    init_tof();
    init_imu();
    motorSetup();
    myTimer.begin(get_readings, interrupt_interval);  // Set up timer to trigger every 1,000,000 microseconds (1 second)
}

void loop()
{      

}
