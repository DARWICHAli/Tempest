// #include <iostream>
// #include "../headers/tempest.hpp"
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_mixer.h>
// #include <SDL2/SDL_ttf.h>

#include <SDL.h>
#include <assert.h>
#include <iostream>
#include "../headers/Draw.hpp"
#include "../headers/tempest.hpp"


int main()
{
    TTF_Init();
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    	{
    		std::cerr<<"Pb init SDL"<< std::endl;
    		return 0;
    	}
        Tempest t;
        t.init_game();

    	SDL_Quit();


    return 0;
}
