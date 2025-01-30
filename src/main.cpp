#include <Arduino.h>

IntervalTimer myTimer;  // Create an IntervalTimer object

void timerISR() {
    Serial.printf("Hello %d\n",micros());  // Print Hello every time the interrupt triggers
}

void setup() {
    Serial.begin(115200);  // Start serial communication
    while (!Serial) {
        ;  // Wait for serial monitor to open (Teensy-specific)
    }
    myTimer.begin(timerISR, 1000);  // Set up timer to trigger every 1,000,000 microseconds (1 second)
}

void loop() {
    // Nothing needed here, as the timer interrupt handles printing
}
