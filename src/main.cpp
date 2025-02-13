#include "lib/imu.h"
#include "lib/distance_sensor.h"
#include "lib/motors.h"
#include "lib/pidRotate.h"
#include "lib/pidStraight.h"
#include "../src/pathfinding/API.h"
#include "../src/pathfinding/Flood.h"
#include "../src/pathfinding/simAPI.h"
#include "../src/pathfinding/labyrinth.h"



VL53L1X sensor;
int mazeMode = 21;
int labMode = 20;
int fireMode = 17;

int valOfMazeMode, valOfLabMode, valOfFireMode;


void setup()
{

  imuSetup();
  sensorInit();
  motorSetup();
  delay(500);
//  pinMode(LED_BUILTIN, OUTPUT);
  delay(500);
  // digitalWrite(LED_BUILTIN, HIGH);
  setForwardPWM(50);
  delay(500);
  initialize();
  Serial.println("Hello world");

  valOfMazeMode = digitalRead(mazeMode);
  valOfLabMode = digitalRead(labMode);
  valOfFireMode = digitalRead(fireMode);



  if(valOfMazeMode == 1 && valOfFireMode == 0 && valOfLabMode == 0) {
    runMaze('c');
  } else if(valOfMazeMode == 0 && valOfFireMode == 0 && valOfLabMode == 1) {
    labyrinth();
  } else if(valOfMazeMode == 0 && valOfFireMode == 1 && valOfLabMode == 0) {
    //firefighting();
  } else {
    return;
  }

  

}

void loop()
{
  // delay(500);
  
  // Serial.println(digitalRead(modePin));
  // Serial.println(digitalRead(memory_button));
  // Serial.println(digitalRead(memory_switch));
}