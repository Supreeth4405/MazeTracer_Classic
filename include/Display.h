#ifndef DISPLAY_H
#define DISPLAY_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Solver.h"

class Display {
  public:
    Display();
    void begin(int x, int y);
    void print(const char* message, int x, int y);
    void drawpath(POINT visited[], int VisitedCount);
  private:
    Adafruit_SSD1306 display;
};

#endif