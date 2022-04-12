#include "../headers/weapon.hpp"


float sensitivity = 3;

Weapon::Weapon ():
    x{0},y{0}
{}
Weapon::~Weapon (){}



float distance(std::pair<int, int> p1,std::pair<int, int> p2)
{
    return sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
}


void Weapon::MoveWeapon(SDL_Renderer * Renderer, int32_t centreX, int32_t centreY, int32_t key , int32_t  type ,std::vector<std::pair<int, int>> points,Draw &d)
{
    float direction1;
    float direction2;
    std::pair<int, int> p1;
    std::pair<int, int> p2 ;
    std::size_t indice;
    std::size_t indice2;

    // on va commencé la partie
    if(!x && !y)
    {
        x = points.at(0).first;
        y = points.at(0).second;
        d.setweapon(x , y);
    }
    // clavier
    if(type == 0 )
    {
        if(key) // 1 ou 2
        {
            // on veux les 2 points les plus proches
            p1 = points.at(0);
            indice = 0;
            float min = sqrt(pow(x - points.at(0).first, 2) +pow(y - points.at(0).second, 2) * 1.0);
            for (std::size_t it = 1; it < points.size(); ++it) {
                if(min > sqrt(pow(x - points.at(it).first, 2) +pow(y - points.at(it).second, 2) * 1.0))
                {
                    // point plus proche
                    p1 =  points.at(it);
                    indice  = it;
                }
            }

            //changement de direction
            if(abs(p1.first -x) < 20 &&  abs(p1.second - y) < 20 )
            {
                //fixing
                d.setweapon(p1.first , p1.second  );

                // aller a droite
                if(key == 1 )
                {
                    indice2 = (indice+1)%points.size();
                    p2 = points.at(indice2);
                }
                // left
                else if(key == 2)
                {
                    indice2 = !indice? points.size()-1: indice-1;
                    p2 = points.at(indice2);
                }

                direction1 = (p2.first - p1.first )/sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
                direction2 = (p2.second - p1.second )/sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
                x +=  direction1 * sensitivity ;
                y +=  direction2 * sensitivity;
                d.setweapon(x , y );

            }
            else
            {
                if(distance(points.at(!indice? points.size()-1:indice-1), points.at(indice)) < distance(points.at((indice+1)%points.size()), points.at(indice)))
                {
                    indice2 = !indice? points.size()-1: indice-1;
                    p2 = points.at(indice2);

                }
                else
                {
                    indice2 = (indice+1)%points.size();
                    p2 = points.at(indice2);
                }

                //DROITE
                if(key == 1)
                {
                    direction1 = (p2.first - p1.first )/sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
                    direction2 = (p2.second - p1.second )/sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
                }
                else if( key == 2)
                {
                    direction1 = (p1.first - p2.first )/sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
                    direction2 = (p1.second - p2.second )/sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
                }

                x +=  direction1 * sensitivity ;
                y +=  direction2 * sensitivity;
                d.setweapon(x , y );
            }
        }
    }
    else
    {
        std::cout << "lol" << '\n';
    }

    SDL_RenderPresent(Renderer);






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
