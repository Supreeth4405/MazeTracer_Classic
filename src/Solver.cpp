#include "Solver.h"

POINT Visited[100];
int VisitedCount = 0;

void logsteps(int newX, int newY) {
  for (int i = 0; i < VisitedCount; i++) {
    if (Visited[i].x == newX && Visited[i].y == newY) {
      VisitedCount = i + 1;
      return;
    }
  }
  if (VisitedCount < 100) {
    Visited[VisitedCount].x = newX;
    Visited[VisitedCount].y = newY;
    VisitedCount++;
  }
}

void coordinates(Direction dir, int &x, int &y) {
  if (dir == NORTH) {
    y++;
  } else if (dir == EAST) {
    x++;
  } else if (dir == SOUTH) {
    y--;
  } else if (dir == WEST) {
    x--;
  }
}

void solve(Direction &dir, int &x, int &y, int left, int center, int right) {
  if (left>10){
    dir = Direction((dir + 3) % 4); // Turn left
  } else if (right>10) {
    dir = Direction((dir + 1) % 4); // Turn right
  } else if (center>10) {
    // Move forward
  } else {
    dir = Direction((dir + 2) % 4); // Turn around
  }

  coordinates(dir, x, y);
  logsteps(x, y);
}