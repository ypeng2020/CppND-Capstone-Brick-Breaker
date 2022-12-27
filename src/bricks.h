#ifndef BRICKS_H
#define BRICKS_H

#include <vector>
#include "SDL.h"
#include "ball.h"
#include <string>

class Bricks {
 public:

  Bricks()
      : vertical_spacing(20),
        horizontal_spacing(10) {}

  ~Bricks()
        {}

  void InitBricks();
  void Update(Ball &ball);

  bool alive{true};
  static const int brick_row = 5;
  static const int brick_col = 10;
  int count = brick_col * brick_row; 
  std::vector<std::vector<int>> bricks_vector;
  bool collide{false};
  std::string re_bound{"N"};

 private:

  void UpdateBricks(Ball &ball);

  bool CheckCollsion(int ball_x, int ball_y, std::vector<int> vrick_vector);

  int vertical_spacing ; 
  int horizontal_spacing ;

  int brick_width = 80;
  int brick_height = 32;
};

#endif