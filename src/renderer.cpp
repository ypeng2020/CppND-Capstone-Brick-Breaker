#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width,
                   const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Brick Breaker", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}


/*
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void Renderer::logSDLError(std::ostream &os, const std::string &msg){
	os << msg << " error: " << SDL_GetError() << std::endl;
}

/*
* Loads a BMP image into a texture on the rendering device
* @param file The BMP image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
// SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren){
SDL_Texture* Renderer::loadTexture(const char *image_path, SDL_Renderer *ren){
	//Initialize to nullptr to avoid dangling pointer issues
	SDL_Texture *texture = nullptr;
	//Load the image
	// SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	SDL_Surface *loadedImage = SDL_LoadBMP(image_path);
	//If the loading went ok, convert to texture and return the texture
	if (loadedImage != nullptr){
		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Make sure converting went ok too
		if (texture == nullptr){
			logSDLError(std::cout, "CreateTextureFromSurface");
		}
	}
	else {
		logSDLError(std::cout, "LoadBMP");
	}
	return texture;
}
//

/*
* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
* the texture's width and height
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
*/
void Renderer::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y){
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Query the texture to get its width and height to use
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

void Renderer::Render(Bar const bar, Ball const ball, std::vector<std::vector<int>> &bricks_vector) {
  SDL_Rect block;
  block.w = 8 * screen_width / grid_width; //  40
  block.h = screen_height / grid_height; // 40
  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  const char *ball_image_path = "../assets/ball.bmp";
  sdl_ball = loadTexture(ball_image_path, sdl_renderer);
  if (sdl_ball == nullptr ){
    SDL_Quit();
    exit(EXIT_FAILURE);
  }

// drawing ball
  int bW {32}, bH{32};
  SDL_QueryTexture(sdl_ball, NULL, NULL, &bW, &bH);
  int bX = ball.head_x;
  int bY = ball.head_y - 2* bH;
  renderTexture(sdl_ball, sdl_renderer, bX, bY);

  // Render bar
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = bar.head_x;
  block.y = screen_height - grid_height; // 1248
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render bricks
  SDL_SetRenderDrawColor(sdl_renderer, 160, 160, 160, 100);
  for (auto brick: bricks_vector) {
    // if collide found (ball collide with brick (brick[2] == 1), set block.w = 0 and block.h = 0 so that the brick will not display )
    if (brick[2] == 1) {
      block.w = 0;
      block.h = 0;
    } else {
      block.w = 90;
      block.h = 40;
    }
    block.x = brick[0];
    block.y = brick[1];
    SDL_RenderFillRect(sdl_renderer, &block);
  }


  // Update Screen
  if (ball.alive) {
    SDL_RenderPresent(sdl_renderer);
  }

}
