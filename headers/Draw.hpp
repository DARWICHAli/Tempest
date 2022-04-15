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
} SDL_Object;





//#include "../headers/tempest.hpp"

// enum Type_Draw{SCORE = 0, SCORE_NUM, LEVEL, LEVEL_NUM, LOOSE, BACK_MENU, LEAVE,
// TEMPEST_TITLE, PLAYER, VS_IA, SCORE_GO, SCORE_NUMGO, LEVEL_GO, LEVEL_NUMGO};

enum Type_Draw{ TEMPEST_TITLE, PLAYER,RATE_URSELF,USE_KEYS,PRESS_ENTER_SELECT,NOVICE,EXPERT,
LEVEL,HOLE,BONUS,TIME, VECT_LEVELS ,VECT_BONUS , WEAPON ,MONSTER , LIFE, SCORE};

class Draw
{
public:
    Draw();
    void init_draw(SDL_Renderer*);
    SDL_Object calculate_texture(std::string, SDL_Color, int, SDL_Renderer*);

    // void create_grid(std::array<std::array<int, 20>, 10>, SDL_Renderer*, int);
    void draw_elem(int, SDL_Renderer*,int);
    int print_menu(SDL_Renderer*);
    void print_game(SDL_Renderer*, Shapes &s);
    // int print_GameOver(SDL_Renderer*);
    // void init_score(SDL_Renderer*);

    // void init_score_num(int, int, SDL_Renderer*);
    // void init_score_numGO(int, int, SDL_Renderer*);
    void init_menu(SDL_Renderer*);
    void init_game(SDL_Renderer*);
    // void init_Game_over(SDL_Renderer*);
    void setHeightWidth(int, int);
    void settimer(int time, SDL_Renderer* renderer );
    void setweapon(int x , int y);
    void setmonster(double x , double y,int );

private:
    TTF_Font* font_menu1;
    TTF_Font* font_menu2;
    TTF_Font* font_score;
    int window_width;
    int window_height;

    // menu
    SDL_Object tempest_title;
    SDL_Object player;
    SDL_Object rate_urself;
    SDL_Object use_keys;
    SDL_Object select;
    SDL_Object level;
    SDL_Object hole;
    SDL_Object bonus;
    SDL_Object novice;
    SDL_Object expert;
    // un tab de shapes 5
    // un tab de bonus
    // // // // levels
    std::vector<SDL_Object> vect_level;
    std::vector<Shapes> vect_hole;
    std::vector<SDL_Object> vect_bonus;
    SDL_Object timer;

    std::vector<SDL_Object>monsters;
    SDL_Object weapon;
    SDL_Object monster_centre;
    SDL_Object monster;
    SDL_Object life;
    SDL_Object score;

};

#endif
