/**
* \file Defs.hpp
* \date 20/04/2022
* \author Ali DARWICH  and Molka SLAMA
*/

#ifndef DRAW_HPP
#define DRAW_HPP


#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cassert>

#include "../headers/Defs.hpp"
#include "../headers/shapes.hpp"




typedef struct
{
  SDL_Texture* texture;
  SDL_Rect rect;
  int width;
  int height;
  int direction;
} SDL_Object;

typedef struct
{
  SDL_Texture* texture;
  SDL_FRect rect;
  float width;
  float height;
  int direction;
  int apper;
} SDL_FObject;

enum Type_Draw{ TEMPEST_TITLE, PLAYER,RATE_URSELF,USE_KEYS,PRESS_ENTER_SELECT,NOVICE,EXPERT,
LEVEL,HOLE,BONUS,TIME, VECT_LEVELS ,VECT_BONUS , WEAPON ,MONSTER ,FIRE, LIFE, SCORE , GAME_OVER,LEVEL_GAME};


/**
 * \class Draw
 * \brief Draw class, plot and stock
 */
class Draw
{
public:


    /*!
    * \brief Constructor of the class Draw
    */
    Draw();



    /*!
    * \brief init draw
    * \param SDL_Renderer renderer
    */
    void init_draw(SDL_Renderer*);


    /*!
    * \brief init Game_over interface
    * \param SDL_Renderer renderer
    */
    void init_game_over(SDL_Renderer* renderer);



    /*!
    * \brief calculate texture of string
    * \param color color
    * \param type size
    * \param SDL_Renderer renderer
    * \return SDL_Object
    */
    SDL_Object calculate_texture(std::string, SDL_Color, int, SDL_Renderer*);



    /*!
    * \brief calculate texture of string
    * \param color color
    * \param type size
    * \param SDL_Renderer renderer
    * \return SDL_FObject
    */
    SDL_FObject fcalculate_texture(std::string text,SDL_Color color,int type, SDL_Renderer* renderer);

    /*!
    * \brief clear level
    */
    void clearlevel();


    /*!
    * \brief move fire and detect collision
    * \param cenx centerx
    * \param ceny centery
    * \param SDL_Renderer renderer
    */
    void actionfire(int cenx ,int ceny,SDL_Renderer *renderer);



    /*!
    * \brief move monsters and detect collision
    * \param cenx centerx
    * \param ceny centery
    * \param SDL_Renderer renderer
    */
    void movemonsters(Shapes s,int cenx ,int ceny);

    /*!
    * \brief draw elment
    * \param type type
    * \param SDL_Renderer renderer
    * \param index index
    */

    void draw_elem(int, SDL_Renderer*,int);


    /*!
    * \brief draw menu
    * \param SDL_Renderer renderer
    * \return type
    */
    int print_menu(SDL_Renderer*);


    /*!
    * \brief draw game, the function take the level and init both shapes and draw the game
    * \param SDL_Renderer renderer
    * \param s Shape
    * \param level level
    * \param weapon weapon shape
    * \pos position near weapon
    */
    void print_game(SDL_Renderer* renderer,Shapes &s, int level, Shapes &weap,std::pair<int, int> pos);


    /*!
    * \brief init menu
    * \param SDL_Renderer renderer
    */
    void init_menu(SDL_Renderer*);


    /*!
    * \brief init game
    * \param SDL_Renderer renderer
    */
    void init_game(SDL_Renderer*);

    /*!
    * \brief init monsters
    * \param SDL_Renderer renderer
    * \param Shape shape
    * \cenx Centerx
    * \ceny Centery
    */
    void initmonsters(SDL_Renderer*,Shapes Shape,int cenx,int ceny);

    /*!
    * \brief derrnier affichage
    * \param SDL_Renderer renderer
    */

    void game_over(SDL_Renderer* renderer);


    void setlevel(int level, SDL_Renderer* renderer );




    void setHeightWidth(int, int);
    void settimer(int time, SDL_Renderer* renderer );
    void setscore(int score, SDL_Renderer* renderer);

    void setweapon(int x , int y);

    void setmonster(SDL_FObject);
    void delmonster(int indice , int type_er);
    int getmonstersize();
    SDL_FObject getmonster(int indice);
    void addfire(SDL_FObject f);
    std::pair<int, int> getweaponinfo();
    void reducetimemonsters();




private:
    /*!< font_menu1 */
    TTF_Font* font_menu1;

    /*!< font_menu2 */
    TTF_Font* font_menu2;

    /*!< font_score */
    TTF_Font* font_score;

    /*!< window_width */
    int window_width;

    /*!< window_height */
    int window_height;

    // menu
    /*!< tempest_title */
    SDL_Object tempest_title;

    /*!< player */
    SDL_Object player;

    /*!< rate_urself */
    SDL_Object rate_urself;

    /*!< use_keys */
    SDL_Object use_keys;

    /*!< select */
    SDL_Object select;

    /*!< level */
    SDL_Object level;

    /*!< hole */
    SDL_Object hole;

    /*!< bonus */
    SDL_Object bonus;

    /*!< novice */
    SDL_Object novice;

    /*!< expert */
    SDL_Object expert;
    // un tab de shapes 5
    // un tab de bonus
    // // // // levels

    /*!< level_game */
    SDL_Object level_game;
    /*!< vect_level */
    std::vector<SDL_Object> vect_level;

    /*!< vect_hole */
    std::vector<Shapes> vect_hole;

    /*!< vect_bonus */
    std::vector<SDL_Object> vect_bonus;

    /*!< timer */
    SDL_Object timer;

    /*!< Game over */
    SDL_Object game_over_var;

    /*!< weapon */
    SDL_Object weapon;

    /*!< monster_centre */
    SDL_FObject monster_centre;

    /*!< monsters */
    std::vector<SDL_FObject>monsters;

    /*!< zmonsters */
    std::vector<double> zmonsters;

    /*!< fires */
    std::vector<SDL_FObject>fire;

    /*!< life */
    SDL_Object life;

    /*!< score */
    SDL_Object score;

    /*!< scoreval */
    int scoreval;

};


#endif
