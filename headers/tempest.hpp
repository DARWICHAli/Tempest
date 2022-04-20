/**
* \file tempest.hpp
* \date 20/04/2022
* \author Ali DARWICH  and Molka SLAMA
*/
#ifndef TEMPEST_HPP
#define TEMPEST_HPP

#include <algorithm>
#include <random>
#include <ctime>
#include <cmath>
#include "../headers/Draw.hpp"
#include "../headers/Defs.hpp"
#include "../headers/weapon.hpp"
#include "../headers/monsters.hpp"

/**
 * \class Tempest
 * \brief Tempest class, represent the game
 */

class Tempest {
private:
    /* data */
    /*!< time_game */
    uint32_t time_game;
    /*!< draw */
    Draw draw;
    /*!< score */
    int score;
    /*!< level */
    int level;
    /*!< screen_width */
    int screen_width;
    /*!< screen_height */
    int screen_height;
    /*!< SDL renderer */
    SDL_Renderer* renderer;
    /*!< window */
    SDL_Window* window;

public:
    /*!
    * \brief Constructor of the Tempest class
    */
    Tempest ();
    /*!
     * \brief begin game
     */
    int game(Weapon w, Draw &draw);
    /*!
     * \brief init game
     */
    int init_game();
};




#endif
