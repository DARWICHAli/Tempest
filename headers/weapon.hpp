#ifndef WEAPON_HPP
#define WEAPON_HPP

//#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"
//#include <SDL2/SDL_mixer.h>
#include <vector>
#include <iostream>
#include "../headers/Draw.hpp"
#include <algorithm>

class Weapon {
private:
    /* data */

    // force
    // type
    // couleur
    // position
    // sound  !
    int32_t x;
    int32_t y;
public:
    Weapon ();
    ~Weapon ();
    void MoveWeapon(SDL_Renderer *, int32_t ,int32_t,int32_t,int32_t,std::vector<std::pair<int, int>> points,Draw&);

};



#endif
