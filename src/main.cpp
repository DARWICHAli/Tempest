#include <iostream>
#include "../headers/tempest.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

int main()
{
  TTF_Init();
  Tempest tempest;
  std::cout << "Main" << std::endl;

  Mix_Quit();
  SDL_Quit();
  return 0;
}
