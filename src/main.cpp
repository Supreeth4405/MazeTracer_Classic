#include <Arduino.h>
#include "Motor.h"
#include "Sensor.h"
#include "Solver.h"
#include "Display.h"

Motor Wheels(5, A0, A1, 6, A2, A3);

Sensor sonarleft(3, 4, 200);
Sensor sonarcenter(8, 9, 200);
Sensor sonarright(10, 11, 200);

Display display;

#define TOUCH 7

int x = 0;
int y = 0;
Direction dir = NORTH;
bool solved = false;
bool entered = false;

void setup() {
  Serial.begin(9600);

  Wheels.begin();
  display.begin(32, 28);

  pinMode(TOUCH, INPUT);
}

void loop() {
  if (digitalRead(TOUCH) == HIGH){
    delay(500);
    if (digitalRead(TOUCH) == HIGH){
      while(!solved) {
        if (!entered) {
          display.print("ENTERING MAZE", 32, 28);
          Wheels.forward(100, 100);
          delay(1000);
          Wheels.stop();
          entered = true;
        }
        if (sonarleft.GetDistance() > 50 && sonarcenter.GetDistance() > 50 && sonarright.GetDistance() > 50) {
          display.print("MAZE SOLVED", 32, 28);
          Wheels.stop();
          solved = true;
          display.drawpath(Visited, VisitedCount);
        } else {
          solve(dir, x, y, sonarleft.GetDistance(), sonarcenter.GetDistance(), sonarright.GetDistance());
        }
      }
    }
  }
}