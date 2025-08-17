#include "Motor.h"

Motor::Motor(int _ena, int _in1, int _in2, int _enb, int _in3, int _in4) {
  ena = _ena;
  in1 = _in1;
  in2 = _in2;
  enb = _enb;
  in3 = _in3;
  in4 = _in4;
}

void Motor::begin() {
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void Motor::forward(int speedright, int speedleft)  {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(ena, speedright);
  analogWrite(enb, speedleft);
}

void Motor::backward(int speedright, int speedleft) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(ena, speedright);
  analogWrite(enb, speedleft);
  delay(1100);
  analogWrite(ena, 0);
  analogWrite(enb, 0);
}

void Motor::turnright(int speed) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(ena, speed);
  analogWrite(enb, speed);
}

void Motor::turnleft(int speed) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(ena, speed);
  analogWrite(enb, speed);
}

void Motor::stop() {
  analogWrite(ena, 0);
  analogWrite(enb, 0);
}