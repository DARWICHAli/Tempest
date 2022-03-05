#ifndef WEAPON_HPP
#define WEAPON_HPP

//#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"
//#include <SDL2/SDL_mixer.h>
class Weapon {
private:
    /* data */
    // force
    // type
    // couleur
    // position
    // sound  !

public:
    Weapon ();
    ~Weapon ();
    void MoveWeapon(SDL_Renderer *, int32_t , int32_t);

};



#endif
