/**
* \file Defs.hpp
* \brief Class Shapes
* \date 20/04/2022
* \author Ali DARWICH  and Molka SLAMA
*/


#ifndef SHAPES_HPP
#define SHAPES_HPP

#include "SDL_ttf.h"
#include "SDL.h"
#include <SDL_mixer.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>
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
    * \brief color the col linking the shapes
    * \param SDL_Renderer renderer
    * \cenx index
    * \ceny color
    */
    void colorcol(std::shared_ptr<SDL_Renderer>,std::pair<int , int > index,int color );



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
    void Display(std::shared_ptr<SDL_Renderer> Renderer, int color, int cycl);

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
    void drawweapon(std::shared_ptr<SDL_Renderer> renderer,int level,std::pair<int, int> weapon);

    /*!
    * \brief general function calls Draw*
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    * \param level level
    */
    void Drawshape(std::shared_ptr<SDL_Renderer>renderer, int32_t window_width,int32_t window_height, int32_t level);


    /*!
    * \brief Draw circle
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawCircle(std::shared_ptr<SDL_Renderer>, int32_t , int32_t ,int color);
    /*!
    * \brief Draw Triangle
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawTriangle(std::shared_ptr<SDL_Renderer>, int32_t , int32_t ,int color );
    /*!
    * \brief DrawRectangle
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawRectangle(std::shared_ptr<SDL_Renderer>, int32_t , int32_t,int color  );
    /*!
    * \brief DrawPlus
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawPlus(std::shared_ptr<SDL_Renderer>, int32_t , int32_t ,int color );
    /*!
    * \brief DrawBowtie
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawBowtie(std::shared_ptr<SDL_Renderer>, int32_t , int32_t  ,int color);
    /*!
    * \brief DrawStylizedCross
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawStylizedCross(std::shared_ptr<SDL_Renderer>, int32_t , int32_t ,int color );
    /*!
    * \brief DrawClover
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawClover(std::shared_ptr<SDL_Renderer>, int32_t , int32_t  ,int color);
    /*!
    * \brief DrawV
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawV(std::shared_ptr<SDL_Renderer>, int32_t , int32_t ,int color );
    /*!
    * \brief DrawSteps
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawSteps(std::shared_ptr<SDL_Renderer>, int32_t , int32_t ,int color );
    /*!
    * \brief DrawU
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawU(std::shared_ptr<SDL_Renderer>, int32_t , int32_t ,int color );
    /*!
    * \brief DrawCompFlat
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawCompFlat(std::shared_ptr<SDL_Renderer>, int32_t , int32_t  ,int color);
    /*!
    * \brief DrawHeart
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawHeart(std::shared_ptr<SDL_Renderer>, int32_t , int32_t  ,int color);
    /*!
    * \brief DrawStar
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawStar(std::shared_ptr<SDL_Renderer>, int32_t , int32_t ,int color );
    /*!
    * \brief DrawW
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawW(std::shared_ptr<SDL_Renderer>, int32_t , int32_t ,int color );
    /*!
    * \brief DrawFan
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawFan(std::shared_ptr<SDL_Renderer>, int32_t , int32_t ,int color );
    /*!
    * \brief DrawInfSym
    * \param Renderer Renderer
    * \param window_width window_width
    * \param window_height window_height
    */
    void DrawInfSym(std::shared_ptr<SDL_Renderer>, int32_t , int32_t ,int color );
    /*!
    * \brief get attribute
    * \return the center of the shape
    */
    std::pair<int, int> getcoordcentre();

};


#endif
