#ifndef TEMPEST_HPP
#define TEMPEST_HPP

#include <algorithm>
#include <random>
#include <ctime>
#include <cmath>
#include "../headers/Draw.hpp"
#include "../headers/Defs.hpp"

class Tempest {
private:
    /* data */
    uint32_t time_game;
    int grid_width = 10;
    int grid_height = 20;
    Draw draw;
    int score;
    int level;
    int screen_width;
    int screen_height;
    SDL_Renderer* renderer;
    SDL_Window* window;

public:
    Tempest ();
    int init_game();
};




#endif
