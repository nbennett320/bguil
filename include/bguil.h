#pragma once

#include <vector>
#include <tuple>
#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define WINDOW_WIDTH 300
#define WINDOW_HEIGHT (9.0/16.0) * WINDOW_WIDTH
#define DEFAULT_FONT_PATH "/usr/share/fonts/truetype/liberation/LiberationSerif-Regular.ttf"

class bguil {
  public:

  bguil(void);

  bguil(int, int);

  ~bguil(void);

  void RenderText(int, int, std::string, SDL_Color);

  void RenderLoop(void);

  private:

  bool running;

  SDL_Event event;
  SDL_Renderer *renderer;
  SDL_Window *window;
  TTF_Font *font;
  std::string font_path;

  // vector of tuples, which contain key, bounding rectangle, and texture
  std::vector<std::tuple<std::string, SDL_Rect, SDL_Texture*>> nodes;

};
