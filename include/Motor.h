#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
  private:
    int ena, in1, in2;
    int enb, in3, in4;

  public:
    Motor(int _ena, int _in1, int _in2, int _enb, int _in3, int _in4);

    void begin();
    void forward(int speedright, int speedleft);
    void backward(int speedright, int speedleft);
    void stop();
    void turnleft(int speed);
    void turnright(int speed);
};

#endif
