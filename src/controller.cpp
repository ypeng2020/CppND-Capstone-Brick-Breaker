#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "bar.h"

void Controller::CheckDirection(Bar &bar, Bar::Direction input) const {
  bar.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Bar &bar) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {

        case SDLK_LEFT:
          CheckDirection(bar, Bar::Direction::kLeft);
          break;

        case SDLK_RIGHT:
          CheckDirection(bar, Bar::Direction::kRight);
          break;

        default:
          CheckDirection(bar, Bar::Direction::kRelease);
      }
    }
  }
}