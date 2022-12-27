#include "ball.h"
#include <cmath>
#include <iostream>

void Ball::Update(Bar bar) {
  SDL_Point prev_cell{
      // We first capture the head's cell before updating.
      static_cast<int>(head_x),
      static_cast<int>(head_y)};

  UpdateBall(bar);

  SDL_Point current_cell{
      // Capture the head's cell after updating.
      static_cast<int>(head_x),
      static_cast<int>(head_y)};
}

bool Ball::hitBar(Bar bar) {
    // Check ball hit the bar

    // std::cout << bar.head_x << " " << bar.head_y << std::endl;
    if (head_x + 32 >= bar.head_x && head_x <= bar.head_x + 320 &&
        head_y + 32 >= bar.head_y && head_y <= bar.head_y + 32) {
            return true;
        } 
    return false;
}

void Ball::UpdateBall(Bar bar) {
    if (! alive) 
        return;

    // if the ball is on the bar, make it move in sync with the bar
    if (on_bar)
    {
        head_x += x_velocity;
        head_y += y_velocity;
    }

    // if the ball goes off the left side of the screen
    if (head_x < 0 )
    {
        head_x = 0;
        x_velocity = -x_velocity;
    }

    // if the ball goes off the right side of the screen
    if (head_x > 1248 )
    {
        head_x = 1248;
        x_velocity = -x_velocity;
    }
    // if the ball goes off the top of the screen
    if (head_y < 64 )
    {
        head_y = 64;
        y_velocity = -y_velocity;
    }
    // if the ball goes off the bottom of the screen
    if (head_y > 1296 )
    {
        // check if hit the bar
        bool hit_bar = hitBar(bar);
        if (hit_bar) {
            head_y = 1296;
            // the bar speed will affect the ball speed
            y_velocity = -1 * (0.1 + y_velocity);
            x_velocity += 0.2 * bar.dir;
        } else {
            alive = false;
        }
    }

}



