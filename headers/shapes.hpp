#ifndef SHAPES_HPP
#define SHAPES_HPP

#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_mixer.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include "../headers/constant.hpp"


// 1. Circle
// 2. Square
// 3. Plus symbol
// 4. Bow-tie
// 5. Stylized Cross
// 6. Triangle
// 7. Clover
// 8. V
// 9. Steps
// 10. U
// 11. Completely Flat
// 12. Heart
// 13. Star
// 14. W
// 15. Fan
// 16. Infinity Symbol (figure 8 on its side)


enum Type_Shape{CERCLE , SQUARE ,PLUS ,BOW , STYLIZEDCROSS, TRIANGLE ,CLOVER,V ,
STEPS, U ,COMP_FLAT,HEART,STAR, W ,FAN , INF, WEOPON};
//
// enum Color{RED,BLUE,YELLOW,CYAN,BLACK,GREEN};


class Shapes {
private:
    enum Type_Shape type;
    int r,b,g; //couleur tunnel

    // std::vector<int32_t , int32_t > points;

public:
    std::vector<std::pair<int, int>> points;
    std::vector<std::pair<int, int>> points_centre;
    Shapes ();
    ~Shapes ();
    void center_reduce(int , int );
    void center(int window_width,int window_height);
    void Display(SDL_Renderer * Renderer, int color, int cycl);

    void Drawshape(SDL_Renderer *, int32_t , int32_t , int32_t );
    void DrawCircle(SDL_Renderer *, int32_t , int32_t , int32_t );
    void DrawTriangle(SDL_Renderer *, int32_t , int32_t  );
    void DrawRectangle(SDL_Renderer *, int32_t , int32_t  );
    void DrawPlus(SDL_Renderer *, int32_t , int32_t  );
    void DrawBowtie(SDL_Renderer *, int32_t , int32_t  );
    void DrawStylizedCross(SDL_Renderer *, int32_t , int32_t  );
    void DrawClover(SDL_Renderer *, int32_t , int32_t  );
    void DrawV(SDL_Renderer *, int32_t , int32_t  );
    void DrawSteps(SDL_Renderer *, int32_t , int32_t  );
    void DrawU(SDL_Renderer *, int32_t , int32_t  );
    void DrawCompFlat(SDL_Renderer *, int32_t , int32_t  );
    void DrawHeart(SDL_Renderer *, int32_t , int32_t  );
    void DrawStar(SDL_Renderer *, int32_t , int32_t  );
    void DrawW(SDL_Renderer *, int32_t , int32_t  );
    void DrawFan(SDL_Renderer *, int32_t , int32_t  );
    void DrawInfSym(SDL_Renderer *, int32_t , int32_t  );
    std::pair<int, int> getcoordcentre();



};


#endif
