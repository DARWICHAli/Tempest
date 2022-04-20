/**
* \file Defs.hpp
* \brief Class Shapes
* \date 20/04/2022
* \author Ali DARWICH  and Molka SLAMA
*/


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


/*!< type of the Shape */
enum Type_Shape{CERCLE , SQUARE ,PLUS ,BOW , STYLIZEDCROSS, TRIANGLE ,CLOVER,V ,
STEPS, U ,COMP_FLAT,HEART,STAR, W ,FAN , INF, WEOPON};
//
// enum Color{RED,BLUE,YELLOW,CYAN,BLACK,GREEN};

/**
* \class Shapes
* \brief Shapes class handels all complexe objects
*/
class Shapes {
private:

    /*!< shape type  */
    enum Type_Shape type;

    /*!< shape color */
    int r,b,g; //couleur tunnel

    // std::vector<int32_t , int32_t > points;

public:

    /*!< exterior points */
    std::vector<std::pair<int, int>> points;

    /*!< interior points */
    std::vector<std::pair<int, int>> points_centre;
    Shapes ();
    ~Shapes ();

    /*!
    * \brief scale and shift points "ie shape" to a specific point
    * \param  x
    * \param   y
    */
    void center_reduce(int , int );
    /*!
    * \brief shift points "ie shape" to a specific point
    * \param window_width x
    * \param window_height y
    */
    void center(int window_width,int window_height);

    /*!
    * \brief plot shape by connecting points
    * \param Renderer Renderer
    * \param color color
    * \param cycl Cyclic or acyclic
    */
    void Display(SDL_Renderer * Renderer, int color, int cycl);

    /*!
    * \brief erase data from shape points
    */
    void clearlevelShape();

    /*!
    * \brief plot weapon
    * \param Renderer Renderer
    * \param level level
    * \param weapon coord of weapon
    */
    void drawweapon(SDL_Renderer * renderer,int level,std::pair<int, int> weapon);

    /*!
    * \brief general function calls Draw*
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    * \param level level
    */
    void Drawshape(SDL_Renderer *renderer, int32_t window_width,int32_t window_height, int32_t level);


    /*!
    * \brief Draw circle
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawCircle(SDL_Renderer *, int32_t , int32_t , int32_t );
    /*!
    * \brief Draw Triangle
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawTriangle(SDL_Renderer *, int32_t , int32_t  );
    /*!
    * \brief DrawRectangle
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawRectangle(SDL_Renderer *, int32_t , int32_t  );
    /*!
    * \brief DrawPlus
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawPlus(SDL_Renderer *, int32_t , int32_t  );
    /*!
    * \brief DrawBowtie
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawBowtie(SDL_Renderer *, int32_t , int32_t  );
    /*!
    * \brief DrawStylizedCross
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawStylizedCross(SDL_Renderer *, int32_t , int32_t  );
    /*!
    * \brief DrawClover
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawClover(SDL_Renderer *, int32_t , int32_t  );
    /*!
    * \brief DrawV
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawV(SDL_Renderer *, int32_t , int32_t  );
    /*!
    * \brief DrawSteps
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawSteps(SDL_Renderer *, int32_t , int32_t  );
    /*!
    * \brief DrawU
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawU(SDL_Renderer *, int32_t , int32_t  );
    /*!
    * \brief DrawCompFlat
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawCompFlat(SDL_Renderer *, int32_t , int32_t  );
    /*!
    * \brief DrawHeart
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawHeart(SDL_Renderer *, int32_t , int32_t  );
    /*!
    * \brief DrawStar
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawStar(SDL_Renderer *, int32_t , int32_t  );
    /*!
    * \brief DrawW
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawW(SDL_Renderer *, int32_t , int32_t  );
    /*!
    * \brief DrawFan
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawFan(SDL_Renderer *, int32_t , int32_t  );
    /*!
    * \brief DrawInfSym
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawInfSym(SDL_Renderer *, int32_t , int32_t  );
    /*!
    * \brief get attribute
    * \return the center of the shape
    */
    std::pair<int, int> getcoordcentre();

};


#endif
