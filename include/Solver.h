#ifndef SOLVER_H
#define SOLVER_H

#include <Arduino.h>
#include "Motor.h"
#include "Display.h"

struct POINT {
  int x;
  int y;
};

extern POINT Visited[100];
extern int VisitedCount;

enum Direction {
  NORTH,
  EAST,
  SOUTH,
  WEST
};

void logsteps(int newX, int newY);
void coordinates(Direction dir, int &x, int &y);
void solve(Direction &dir, int &x, int &y, int left, int center, int right);


#endif

