#ifndef WEAPON_HPP
#define WEAPON_HPP

//#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"
//#include <SDL2/SDL_mixer.h>
#include <vector>
#include <iostream>
#include "../headers/Draw.hpp"
#include <algorithm>
#include "../headers/shapes.hpp"

class Weapon {
private:
    /* data */

    // force
    // type
    int couleur;
    // position
    // sound  !
    int32_t x;
    int32_t y;
public:
    Weapon ();
    ~Weapon ();
    void MoveWeapon( int32_t ,int32_t,int32_t,int32_t,std::vector<std::pair<int, int>> points,Draw&);
    void FireWeapon(int32_t,Draw &d,SDL_Renderer* renderer);
    //void MoveMissile(Shapes&s,Draw &d);
};


#endif
