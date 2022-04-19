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




//#include "../headers/tempest.hpp"

// enum Type_Draw{SCORE = 0, SCORE_NUM, LEVEL, LEVEL_NUM, LOOSE, BACK_MENU, LEAVE,
// TEMPEST_TITLE, PLAYER, VS_IA, SCORE_GO, SCORE_NUMGO, LEVEL_GO, LEVEL_NUMGO};

enum Type_Draw{ TEMPEST_TITLE, PLAYER,RATE_URSELF,USE_KEYS,PRESS_ENTER_SELECT,NOVICE,EXPERT,
LEVEL,HOLE,BONUS,TIME, VECT_LEVELS ,VECT_BONUS , WEAPON ,MONSTER ,FIRE, LIFE, SCORE};

class Draw
{
public:
    Draw();
    void init_draw(SDL_Renderer*);
    SDL_Object calculate_texture(std::string, SDL_Color, int, SDL_Renderer*);
    SDL_FObject fcalculate_texture(std::string text,SDL_Color color,int type, SDL_Renderer* renderer);
    void clearlevel();
    void actionfire(int cenx ,int ceny,SDL_Renderer *renderer);
    void movemonsters(Shapes s,int cenx ,int ceny, double &z);

    void draw_elem(int, SDL_Renderer*,int);
    int print_menu(SDL_Renderer*);
    void print_game(SDL_Renderer*, Shapes &s,int level);
    void init_menu(SDL_Renderer*);
    void init_game(SDL_Renderer*);
    void initmonsters(SDL_Renderer*,Shapes s,int cenx,int ceny);

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


    SDL_Object weapon;
    SDL_FObject monster_centre;
    std::vector<SDL_FObject>monsters;
    std::vector<SDL_FObject>fire;
    SDL_Object life;
    SDL_Object score;
    int scoreval;

};



#endif
