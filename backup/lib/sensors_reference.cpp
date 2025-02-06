#include <Arduino.h>

// IntervalTimer myTimer;
const uint8_t lsensor = 21, rsensor = 23;
int16_t lreading = 0, rreading = 0;

// void timerISR() {
//     lsensor = pulseIn(21,HIGH);
//     rsensor = pulseIn(23,HIGH);
// }

void setup() {
    Serial.begin(115200);  // Start serial communication
    while (!Serial) {
        ;  // Wait for serial monitor to open (Teensy-specific)
    }
    // myTimer.begin(timerISR, 1000);  // Set up timer to trigger every 1,000,000 microseconds (1 second)
}

void loop()
{

  lreading= pulseIn(lsensor, HIGH);
  if (lreading == 0)
  {
    // pulseIn() did not detect the start of a pulse within 1 second.
    Serial.println("timeout");
  }
  else if (lreading > 1850)
  {
    // No detection.
    Serial.println(-1);
  }
  else
  {
    // Valid pulse width reading. Convert pulse width in microseconds to distance in millimeters.
    // int16_t d = (lsensor - 1000) * 3 / 4;
 
    // // Limit minimum distance to 0.
    // // if (d < 0) { d = 0; } 
  
    Serial.printf("%d %ld\n",lreading,time);
  }
}
