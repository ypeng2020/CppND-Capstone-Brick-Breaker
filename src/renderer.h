#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <string>
#include <iostream>
#include "SDL.h"
#include "bar.h"
#include "ball.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void logSDLError(std::ostream &os, const std::string &msg);
  void Render(Bar const bar, Ball const ball, std::vector<std::vector<int>> &bricks_vector);
  SDL_Texture* loadTexture(const char *image_path, SDL_Renderer *ren);
  void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);

 private:
  SDL_Texture *sdl_ball; 
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif