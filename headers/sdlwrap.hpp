/**
* \file sdlwrap.hpp
* \date 20/04/2022
* \author Ali DARWICH  and Molka SLAMA
*/

#ifndef SDL_WRAP
#define SDL_WRAP


#include <memory> // shared_ptr
#include <SDL2/SDL.h>

static void SDL_DelRes(SDL_Window   *r) { SDL_DestroyWindow(r);   }
static void SDL_DelRes(SDL_Renderer *r) { SDL_DestroyRenderer(r); }
static void SDL_DelRes(SDL_Texture  *r) { SDL_DestroyTexture(r);  }
static void SDL_DelRes(SDL_Surface  *r) { SDL_FreeSurface(r);     }

template <typename T>
std::shared_ptr<T> sdl_shared(T *t) {
    return std::shared_ptr<T>(t, [](T *t) { SDL_DelRes(t); });
}


#endif
