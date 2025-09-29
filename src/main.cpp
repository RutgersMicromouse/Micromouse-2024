#include <Wire.h>
#include <Arduino.h>
#include "../lib/IMU/imu.h"
#include "../lib/distanceSensor/distance_sensor.h"
#include "../lib/Motors/motors.h"
#include "../lib/pidRotate/pidRotate.h"
#include "../lib/pidStraight/pidStraight.h"
#include "../pathfinding/API/API.h"
#include "../pathfinding/Flood/Flood.h"
#include "../pathfinding/simAPI/simAPI.h"
#include "../pathfinding/Labyrinth/labyrinth.h"


VL53L1X sensor;

int PIN = 13;

void setup()
{

//   imuSetup();
//   sensorInit();
//   motorSetup();
//   delay(500);
// //  pinMode(LED_BUILTIN, OUTPUT);
//   delay(500);
//   // digitalWrite(LED_BUILTIN, HIGH);
//   setForwardPWM(50);
//   delay(500);
//   initialize();
//   Serial.println("Hello world");

//   valOfMazeMode = digitalRead(mazeMode);
//   valOfLabMode = digitalRead(labMode);
//   valOfFireMode = digitalRead(fireMode);


Serial.begin(115200);
Serial.println("howdy");
pinMode(PIN, OUTPUT);


//   if(valOfMazeMode == 1 && valOfFireMode == 0 && valOfLabMode == 0) {
//     runMaze('c');
//   } else if(valOfMazeMode == 0 && valOfFireMode == 0 && valOfLabMode == 1) {
//     labyrinth();
//   } else if(valOfMazeMode == 0 && valOfFireMode == 1 && valOfLabMode == 0) {
//     //firefighting();
//   } else {
//     return;
//   }

  

}

void loop()
{

  digitalWrite(PIN, HIGH);
  delay(1500);
  digitalWrite(PIN, LOW);
  delay(1500);
  Serial.println("GAY");


}