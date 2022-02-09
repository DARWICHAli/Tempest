#ifndef DRAW_HPP
#define DRAW_HPP


#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <cstring>
#include <string>
#include "../headers/Defs.hpp"
#include "../headers/tempest.hpp"

// enum Type_Draw{SCORE = 0, SCORE_NUM, LEVEL, LEVEL_NUM, LOOSE, BACK_MENU, LEAVE,
// TETRIS_TITLE, SOLO_MODE, VS_IA, SCORE_GO, SCORE_NUMGO, LEVEL_GO, LEVEL_NUMGO};
//
// typedef struct
// {
//   SDL_Texture* texture;
//   SDL_Rect rect;
//   int width;
//   int height;
// } SDL_Object;

class Draw
{
public:
    Draw();
    void draw(int last_x,int last_y);
  // void create_grid(std::array<std::array<int, 20>, 10>, SDL_Renderer*, int);
  // void draw_elem(int, SDL_Renderer*);
  // int print_menu(SDL_Renderer*);
  // int print_GameOver(SDL_Renderer*);
  // void init_score(SDL_Renderer*);
  // void init_draw(SDL_Renderer*);
  // void init_score_num(int, int, SDL_Renderer*);
  // void init_score_numGO(int, int, SDL_Renderer*);
  // void init_menu(SDL_Renderer*);
  // SDL_Object calculate_texture(std::string, SDL_Color, int, SDL_Renderer*);
  // void init_Game_over(SDL_Renderer*);
  // void setHeightWidth(int, int, int, int);

private:


    int last_x;
    int last_y;

  // TTF_Font* font_menu;
  // TTF_Font* font_score;
  // SDL_Object score;
  // SDL_Object score_GO;
  // SDL_Object score_numGO;
  // SDL_Object level_GO;
  // SDL_Object level_numGO;
  // SDL_Object score_num;
  // SDL_Object level;
  // SDL_Object level_num;
  // SDL_Object game_over;
  // SDL_Object back_menu;
  // SDL_Object leave;
  // SDL_Object tetris_title;
  // SDL_Object solo_mode;
  // SDL_Object vs_IA;
  // int window_width;
  // int window_height;
  // int cell_width;
  // int cell_height;
};

#endif
