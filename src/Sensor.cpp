#include "Sensor.h"

Sensor::Sensor(int trigPin, int echoPin, int maxDistance) : sonar(trigPin, echoPin, maxDistance) {
}

int Sensor::GetDistance() {
  return sonar.ping_cm();
}