#include "game.h"
#include <iostream>
#include "SDL.h"
#include "renderer.h"
#include <vector>


Game::Game(std::size_t grid_width, std::size_t grid_height)
    : bar(grid_width, grid_height),
      ball(),
      bricks()
      {
  bricks.InitBricks();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, bar);
    Update();
    renderer.Render(bar, ball, bricks.bricks_vector);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      // renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}


void Game::Update() {
  if (!bar.alive) return;

  bar.Update();
  bricks.Update(ball);
  ball.Update(bar);

  int new_x = static_cast<int>(bar.head_x);
  int new_y = static_cast<int>(bar.head_y);
}
