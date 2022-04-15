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
    x{x},y{y},z{1},d{1}
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

void Monsters::deplacement_Monster1(SDL_Renderer * Renderer ,std::vector<std::pair<int, int>> points,Draw &d1,double &i,double &mx, double &my)
{
    

    int center_shift = 720;


    int cx=(points[1].first+points[2].first)/2;
    int cy=(points[1].second+points[2].second)/2;
    
    
    int Ux =points[1].first-points[0].first;
    int Vy = points[1].second-points[0].second;
    double norm = sqrt(Ux * Ux + Vy * Vy);
    double ux = Ux / norm;
    double uy = Vy / norm;
    double x_prim;
    double y_prim;
    int sensitivity=100;

    int direction1 = (cx - x )/sqrt(pow(cx - x , 2) +pow( cy - y, 2) * 1.0);
    int direction2 = (cy - y )/sqrt(pow(cx - x , 2) +pow( cy - y , 2) * 1.0);

    std::cout << "avant" << x << std::endl;
    x +=  direction1 * sensitivity;
    y +=  direction2 * sensitivity;
    
    d1.setmonster(x,y);
    std::cout << "apre" <<x << std::endl;
    //x_prim = (ux * mx - uy * my-mx)*d+mx;
    //y_prim = (ux * mx + uy * my-my)*d+my;
    //x=x_prim;
    //y=y_prim;

    //x=(mx-cx)*i+cx;

   // y=(my-cy)*i+cy;
    //std::cout << x << std::endl;

    

    // on va commencé la partie
    /*double  d1 = sqrt(pow((points[0].first-points[1].first),2) + (pow((points[0].second-points[1].second),2)));
    double x1,y1;
    double Ux=points[1].first-points[0].first;
    std::cout << "ok"<<std::endl;
    double Uy=points[1].second-points[0].second;
    double x_prim= (Ux*x)-(Uy*y);
    double y_prim= (Uy*x)+(Ux*y);
    double k=points[0].first+points[0].second;*/
    
    //double h;
       /* x_prim=x_prim*(1+i);
        y_prim=y_prim*(1-i);
        x1 = (x_prim+y_prim)/k;
        y1 = (y_prim-x_prim)/k;*/
        
       
        
        //SDL_RenderCopy(renderer, monster.texture, NULL, &monster.rect);
        //SDL_RenderPresent(renderer);
        //SDL_RenderClear(renderer);
}