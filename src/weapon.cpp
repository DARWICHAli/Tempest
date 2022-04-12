#include "../headers/weapon.hpp"


int sensitivity = 10;

Weapon::Weapon ():
    x{0},y{0}
{}
Weapon::~Weapon (){}


void Weapon::MoveWeapon(SDL_Renderer * Renderer, int32_t centreX, int32_t centreY, int32_t key , int32_t  type ,std::vector<std::pair<int, int>> points,Draw &d)
{
    // on va commencé la partie
    if(!x && !y)
    {
        std::cout << "one time"<< '\n';
        x = points.at(0).first;
        y = points.at(0).second;
        d.setweapon(x , y);

    }
    // clavier
    if(type == 0 )
    {
        if(key) // 1 ou 2
        {
            if(key == 1 )
            {
                x-=sensitivity;
                d.setweapon(x , y );
            }
            else if(key == 2)
            {
                x+=sensitivity;
                d.setweapon(x , y );
            }

        }

        SDL_RenderPresent(Renderer);
    }
    else
    {
        std::cout << "lol" << '\n';
    }







    // couleurs changes avec le niveau
    // rect pour le moment
    //
    // SDL_SetRenderDrawColor(Renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    // SDL_RenderDrawLine(Renderer, centreX-25 ,centreY-25 , centreX-25, centreY+25 );
    // SDL_RenderDrawLine(Renderer, centreX-25, centreY+25 , centreX+25 ,centreY+25);
    // SDL_RenderDrawLine(Renderer, centreX+25 ,centreY+25 , centreX+25 ,centreY-25 );
    // SDL_RenderDrawLine(Renderer, centreX+25 ,centreY-25 , centreX-25 ,centreY-25 );
    //SDL_RenderClear(Renderer);



    // SDL_RenderPresent(Renderer);
    // //SDL_RenderPresent(renderer);
    // SDL_RenderClear(Renderer);


}
