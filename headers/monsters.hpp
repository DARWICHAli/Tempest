/**
* \file monsters.hpp
* \date 20/04/2022
* \author Ali DARWICH  and Molka SLAMA
*/
#ifndef SMONSTERS_HPP
#define MONSTERS_HPP

#include "SDL_ttf.h"
#include "SDL.h"
#include <SDL_mixer.h>
#include "../headers/Draw.hpp"
#include <vector>



/**
* \class Monsters
* \brief Monsters class, represent the Monsters
*/

class Monsters {
public:

    /*!< postion of the monster x */
    double x;

    /*!< postion of the monster y */
    double y;

    /*!< Missile depth */
    int d;

    /*!< Quadratic coefficient for the velocity */
    double z;

    /*!< apper */
    int apper;

public:
    /*!
    * \brief Constructor of the class Monsters
    * \param x x
    * \param y y
    */
    Monsters (double x, double y);
    ~Monsters ();

    /*!
    * \brief move monster
    * \param x x
    * \param y y
    */
    void deplacement_Monster(SDL_Renderer *,std::vector<std::pair<int, int>> points,Draw&, double &i);


    /*!
    * \brief move monster
    * \param x x
    * \param y y
    */
    void deplacement_Monster1(SDL_Renderer * Renderer ,std::vector<std::pair<int, int>> points,Draw &d1,double &i,double &mx, double &my);

};


#endif
