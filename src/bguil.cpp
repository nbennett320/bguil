#include "bguil.h"
#include<iostream>

bguil::bguil() {
  SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE, &this->window, &this->renderer);
  SDL_SetWindowSize(window, WINDOW_WIDTH, WINDOW_HEIGHT);
  TTF_Init();

  this->font_path = std::string(DEFAULT_FONT_PATH);
  this->font = TTF_OpenFont(this->font_path.c_str(), 12);
  if(!font) {
    exit(1);
  }

  this->running = 1;
}

bguil::bguil(int size_x, int size_y) {
  SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(size_x, size_y, SDL_WINDOW_RESIZABLE, &this->window, &this->renderer);
  SDL_SetWindowSize(window, WINDOW_WIDTH, WINDOW_HEIGHT);
  TTF_Init();

  this->font_path = std::string(DEFAULT_FONT_PATH);
  this->font = TTF_OpenFont(this->font_path.c_str(), 12);
  if(!font) {
    exit(1);
  }

  this->running = 1;
}

bguil::~bguil() {
  for(auto &node : this->nodes) {
    SDL_Texture *texture = std::get<2>(node);
    SDL_DestroyTexture(texture);
  }

  TTF_Quit();

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void bguil::RenderText(int x, int y, std::string text, SDL_Color color) {
  SDL_Rect rect;
  SDL_Texture **texture;
  std::string key = std::string(text);
  int font_width;
  int font_height;
  SDL_Surface *surface;

  surface = TTF_RenderText_Solid(font, text.c_str(), color);
  *texture = SDL_CreateTextureFromSurface(this->renderer, surface);
  font_width = surface->w;
  font_height = surface->h;
  SDL_FreeSurface(surface);
  rect.x = x;
  rect.y = y;
  rect.w = font_width;
  rect.h = font_height;

  std::tuple<std::string, SDL_Rect, SDL_Texture*> node = 
    std::tuple<std::string, SDL_Rect, SDL_Texture*>(key, rect, *texture);
  
  this->nodes.push_back(node);
  std::cout<<"added node"<<std::endl;
}

void bguil::RenderLoop() {
  while (this->running) {
    while(SDL_PollEvent(&this->event) == 1) {
      std::cout<<"runin"<<std::endl;
      if(event.type == SDL_QUIT) {
        running = 0;
      }
    }

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
    SDL_RenderClear(this->renderer);

    for(auto &node : this->nodes) {
      std::string key = std::get<0>(node);
      SDL_Rect rect = std::get<1>(node);
      SDL_Texture *texture = std::get<2>(node);
      SDL_RenderCopy(renderer, texture, NULL, &rect);
    }

    SDL_RenderPresent(renderer);
  }
}
