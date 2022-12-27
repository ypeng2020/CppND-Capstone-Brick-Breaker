#ifndef BALL_H
#define BALL_H

#include <vector>
#include "SDL.h"
#include "bar.h"


class Ball {
 public:

  Ball()
      : x_velocity(8),  
        y_velocity(-8),
        head_x(640),
        head_y(1280) {}

  void Update(Bar bar);

  float speed{7.5f};
  bool alive{true};
  float head_x;
  float head_y;
  bool on_bar{true};
  bool hit{false};

  float x_velocity;  // horizontal velocity
  float y_velocity;  // vertical velocity

 private:
  void UpdateBall(Bar bar);

  bool hitBar(Bar bar);

};

#endif