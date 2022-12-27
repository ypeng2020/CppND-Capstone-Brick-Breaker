#ifndef BAR_H
#define BAR_H

#include <vector>
#include "SDL.h"

class Bar {
 public:

  enum class Direction { kLeft, kRight, kRelease };

  Bar(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(640),
        head_y(1280) {}

  void Update();

  bool ReachLeft(int x); //check if the bar hit the wall 
  bool ReachRight(int x); //check if the bar hit the wall 

  Direction direction = Direction::kRelease;

  float speed{15.0f};
  bool alive{true};
  float head_x;
  float head_y;
  bool wall{false};
  int dir{0}; // static 

 private:
  void UpdateBar();
  int grid_width;
  int grid_height;
};

#endif