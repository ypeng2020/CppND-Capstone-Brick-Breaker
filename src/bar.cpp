#include "bar.h"
#include <cmath>
#include <iostream>

void Bar::Update() {
  UpdateBar();
}

void Bar::UpdateBar() {
  switch (direction) {

    case Direction::kLeft:
      if (! ReachLeft(head_x))
        head_x -= speed;
        dir = -1;
      break;

    case Direction::kRight:
      if (! ReachRight(head_x))
        head_x += speed;
        dir = 1;
      break;

    default:
      dir = 0;
      head_x += 0;
  }
}

bool Bar::ReachLeft(int x) {
  if (x <= 0 ) return true;
  return false;
}

bool Bar::ReachRight(int x) {
  if (x >= 960) return true;
  return false;
}