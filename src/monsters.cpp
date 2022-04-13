#include "../headers/monsters.hpp"
#include "../headers/Draw.hpp"
#include <math.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>


Monsters::Monsters (double x,double y):
    x{x},y{y}
{
    
}
Monsters::~Monsters (){}


void Monsters::deplacement_Monster(SDL_Renderer * Renderer ,std::vector<std::pair<int, int>> points,Draw &d,double &i)
{
    // on va commencé la partie
    /* double d = sqrt(pow((points[0].first-points[1].first),2) + (pow((points[0].second-points[1].second),2)));
    
    double Ux=s.points[1].first-s.points[0].first;
    std::cout << "ok"<<std::endl;
    double Uy=s.points[1].second-s.points[0].second;
    double x_prim= (Ux*monster.rect.x)-(Uy*monster.rect.y);
    double y_prim= (Uy*monster.rect.x)+(Ux*monster.rect.y);
    double k=s.points[0].first+s.points[0].second;*/
    
    //double h;

    
        y = y*(1+i);
        d.setmonster(x,y);
        
        //SDL_RenderCopy(renderer, monster.texture, NULL, &monster.rect);
        //SDL_RenderPresent(renderer);
        //SDL_RenderClear(renderer);
}

void Monsters::deplacement_Monster1(SDL_Renderer * Renderer ,std::vector<std::pair<int, int>> points,Draw &d,double &i)
{
    // on va commencé la partie
    /* double d = sqrt(pow((points[0].first-points[1].first),2) + (pow((points[0].second-points[1].second),2)));
    
    double Ux=s.points[1].first-s.points[0].first;
    std::cout << "ok"<<std::endl;
    double Uy=s.points[1].second-s.points[0].second;
    double x_prim= (Ux*monster.rect.x)-(Uy*monster.rect.y);
    double y_prim= (Uy*monster.rect.x)+(Ux*monster.rect.y);
    double k=s.points[0].first+s.points[0].second;*/
    
    //double h;

        x = x*(1+i);
        y = y*(1-i);
        d.setmonster(x,y);
        
        //SDL_RenderCopy(renderer, monster.texture, NULL, &monster.rect);
        //SDL_RenderPresent(renderer);
        //SDL_RenderClear(renderer);
}