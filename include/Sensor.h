#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include <NewPing.h>

class Sensor {
  public:
    Sensor(int Trig, int Echo, int MaxDistance);
    int GetDistance();
  private:
    NewPing sonar;
};

#endif