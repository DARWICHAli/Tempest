#ifndef SHAPES_HPP
#define SHAPES_HPP

#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_mixer.h>
#include <vector>
#include <iostream>

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

class Shapes {
private:
    enum Type_Shape type;
    // std::vector<int32_t , int32_t > points;

public:
    std::vector<std::pair<int, int>> points;
    Shapes ();
    ~Shapes ();
    void DrawCircle(SDL_Renderer *, int32_t , int32_t , int32_t );
    void DrawTriangle(SDL_Renderer *, int32_t , int32_t  );
};


#endif
