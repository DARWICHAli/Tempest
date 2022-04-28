/**
* \file Defs.hpp
* \date 20/04/2022
* \author Ali DARWICH  and Molka SLAMA
*/
#ifndef WEAPON_HPP
#define WEAPON_HPP

//#include "SDL2/SDL_ttf.h"
#include "SDL.h"
//#include <SDL2/SDL_mixer.h>
#include <vector>
#include <iostream>
#include "../headers/Draw.hpp"
#include <algorithm>
#include "../headers/shapes.hpp"

class Weapon {
private:
    /* data */
    /*!< force */
    // force
    /*!< type of weapon */
    // type
    /*!< couleur */
    int couleur;
    /*!< position */
    int32_t x;
    int32_t y;

    /*!< sound */
    // sound  !

public:
    /*!
    * \brief Constructor of the weapon class
    */
    Weapon ();
    ~Weapon ();
    /*!
    * \brief move weapon
    * \param centreX centreX
    * \param centreY centreY
    * \param key right or left in case of keyboard
    * \param type keyboard or mouse
    * \param points points of the shape
    * \param Draw Draw
    * \return first index of point.
    */
    std::pair<int, int> MoveWeapon( int32_t centreX, int32_t centreY, int32_t key , int32_t  type ,std::vector<std::pair<int, int>> points,Draw &d);
    /*!
    * \brief Fire weapon
    * \param type type of fire
    * \param renderer SDL_Renderer
    * \param points points
    */
    void FireWeapon(int32_t type, Draw&d,std::shared_ptr<SDL_Renderer> renderer,std::vector<std::pair<int, int>> points );


    int getdirection(std::vector<std::pair<int, int>> points , Draw&d);

};


#endif
