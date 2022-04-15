#ifndef SMONSTERS_HPP
#define MONSTERS_HPP

#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_mixer.h>
#include "../headers/Draw.hpp"
#include <vector>




class Monsters {
public:
    double x;
    double y;
    int d;
    double z;

public:
    Monsters (double x, double y);
    ~Monsters ();
    void deplacement_Monster(SDL_Renderer *,std::vector<std::pair<int, int>> points,Draw&, double &i);
    void deplacement_Monster1(SDL_Renderer * Renderer ,std::vector<std::pair<int, int>> points,Draw &d1,double &i,double &mx, double &my);

};


#endif
