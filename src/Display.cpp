#include "Display.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64


Display::Display() : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1) {}

void Display::begin(int x, int y) {
  display.begin(SSD1306_SWITCHCAPVCC , 0X3C);
  display.clearDisplay();
  display.setCursor(x, y);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.print("MAZETRACER");
  display.display();
}

void Display::print(const char* message, int x, int y) {
  display.clearDisplay();
  display.setCursor(x, y);
  display.print(message);
  display.display();
}

void Display::drawpath(POINT visited[], int VisitedCount) {
  display.clearDisplay();
  for (int i = 0; i < VisitedCount; i++) {
    int px = visited[i].x * 8;
    int py = visited[i].y * 8;
    display.drawRect(px, py, 6, 6, WHITE);
  }
  display.display();
}