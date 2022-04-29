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
#include <vector>
#include "../headers/shapes.hpp"



/**
* \class Monsters
* \brief Monsters class, represent the Monsters
*/

class Monster {
private:

    /*!< postion of the monster x */
    double x;

    /*!< postion of the monster y */
    double y;

    /*!< Monster direction */
    int direction;

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
    Monster (double x,double y,int direction,int apper,int z);
   // ~ Monster ();
    inline double get_x() const { return x ;}
    inline double get_y() const {return y ;}
    inline int get_direction() const {return direction ;}
    inline int get_apper()const { return apper ;};
    inline void  set_x( const double& new_x){ x=new_x;}
    inline void  set_y(const double& new_y){ y=new_y;}
    inline void  set_apper(const int& new_apper){ apper = new_apper;}
    inline double get_z (){return z;}
   
    void reduce_apper();
    int move(Shapes s,int cenx ,int ceny);


    /*!
    * \brief move monster
    * \param x x
    * \param y y
    */
    //void deplacement_Monster();


    /*!
    * \brief move monster
    * \param x x
    * \param y y
    */
    //void deplacement_Monster1(SDL_Renderer * Renderer ,std::vector<std::pair<int, int>> points,Draw &d1,double &i,double &mx, double &my);

};


#endif
