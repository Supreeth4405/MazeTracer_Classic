#include <Arduino.h>
#include <NewPing.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define TRIG_LEFT 3
#define ECHO_LEFT 4
#define TRIG_CENTER 8
#define ECHO_CENTER 9
#define TRIG_RIGHT 10
#define ECHO_RIGHT 11

NewPing sonarleft(TRIG_LEFT, ECHO_LEFT, 200);
NewPing sonarcenter(TRIG_CENTER, ECHO_CENTER, 200);
NewPing sonarright(TRIG_RIGHT, ECHO_RIGHT, 200);

#define IN1 A0
#define IN2 A1
#define IN3 A2
#define IN4 A3
#define ENA 5
#define ENB 6

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define TOUCH 7

bool solved = false;
bool entered = false;

void forward();
void turnleft();
void turnright();
void backward();
void stop();
void solve();

int leftdistance();
int centerdistance();
int rightdistance();

void setup() {
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0X3C);
  display.clearDisplay();
  display.setCursor(32, 28);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.print("MAZE SOLVER");
  display.display();

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(TOUCH, INPUT);
}

void loop() {
  if (digitalRead(TOUCH) == HIGH) {
    delay(500);

    if (digitalRead(TOUCH) == HIGH) {
      stop();

      display.clearDisplay();
      display.setCursor(32, 28);
      display.print("SOLVING MAZE...");
      display.display();

      while (!solved) {

        if (!entered) {
          display.clearDisplay();
          display.setCursor(32, 28);
          display.print("ENTERING MAZE");
          display.display();

          forward();
          delay(1000);
          stop();
          delay(1000);

          entered = true;
        }

        if (leftdistance() > 50 && centerdistance() > 50 && rightdistance() > 50) {
          display.clearDisplay();
          display.setCursor(32, 28);
          display.print("MAZE SOLVED");
          display.display();

          stop();
          solved = true;
        } else {
          solve();
        }
      }
    }
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
}

void turnright() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
}

void turnleft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
}

void backward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  delay(1100);
  stop();
}

void stop() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void rightshake() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  delay(1000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void leftshake() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  delay(1000);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

int leftdistance() {
  return sonarleft.ping_cm();
}

int centerdistance() {
  return sonarcenter.ping_cm();
}

int rightdistance() {
  return sonarright.ping_cm();
}

void solve() {
  delay(500);
  stop();
  delay(1000);

  if (leftdistance() > 10) {
    turnleft();
    display.clearDisplay();
    display.setCursor(32, 28);
    display.print("TURNING LEFT");
    display.display();
    rightshake();
  }
  else if (centerdistance() > 10) {
    forward();
    display.clearDisplay();
    display.setCursor(32, 28);
    display.print("MOVING FORWARD");
    display.display();
  }
  else if (rightdistance() > 10) {
    turnright();
    display.clearDisplay();
    display.setCursor(32, 28);
    display.print("TURNING RIGHT");
    display.display();
    leftshake();
  }
  else if (leftdistance() < 10 && centerdistance() < 10 && leftdistance() < 10) {
    backward();
    display.clearDisplay();
    display.setCursor(32, 28);
    display.print("TURNING BACK");
    display.display();
  }

  delay(1000);
}