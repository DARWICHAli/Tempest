// #include <iostream>
// #include "../headers/tempest.hpp"
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_mixer.h>
// #include <SDL2/SDL_ttf.h>

#include <SDL.h>
#include <assert.h>
#include <iostream>
#include "../headers/Draw.hpp"


int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    	{
    		std::cerr<<"Pb init SDL"<< std::endl;
    		return 0;
    	}
        Draw d;
    	SDL_Quit();


    return 0;
}
