#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "Coordinate.h"
#include <map>
#include <utility>

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void RenderCity(std::map<Coordinate, int> colorPerCoordinate);
  void Render(Snake const snake, SDL_Point const &food);
  void Render();
  void UpdateWindowTitle(int score, int fps);
  void poll();

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif