#include "../headers/weapon.hpp"


float sensitivity = 20;

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
            //on veux les 2 points les plus proches
            p1 = points.at(0);
            indice = 0;
            float min = sqrt(pow(x - points.at(0).first, 2) +pow(y - points.at(0).second, 2) * 1.0);
            for (std::size_t it = 1; it < points.size(); ++it) {
                std::cout << "dist " << sqrt(pow(x - points.at(it).first, 2) +pow(y - points.at(it).second, 2) * 1.0)<< '\n';
                std::cout << "min " << min <<  '\n';
                if(min > sqrt(pow(x - points.at(it).first, 2) +pow(y - points.at(it).second, 2) * 1.0))
                {
                    // point plus proche
                    std::cout << "it : " << it << " at "<< points.at(it).first  << "  "<< points.at(it).second << '\n';
                    p1 =  points.at(it);
                    indice  = it;
                    min = sqrt(pow(x - points.at(it).first, 2) +pow(y - points.at(it).second, 2) * 1.0);
                }
            }

            // for (std::size_t it = 0; it < points.size(); ++it)
            // {
            //     indice = it;
            //     indice2 = (it+1)%points.size();
            //     p1 = points.at(it);
            //     p2 = points.at(indice2);
            //     if(abs(distance(p1, p2) - (sqrt(pow(x - p1.first , 2) +pow( y - p1.second , 2) * 1.0) +  sqrt(pow(p2.first - x , 2) +pow( p2.second - y, 2) * 1.0)))> 1.)
            //     {
            //         break;
            //     }
            //     indice2 = !indice? points.size()-1: indice-1;
            //     p2 = points.at(indice2);
            //     if(abs(distance(p1, p2) - (sqrt(pow(x - p1.first , 2) +pow( y - p1.second , 2) * 1.0) +  sqrt(pow(p2.first - x , 2) +pow( p2.second - y, 2) * 1.0)))> 1.)
            //     {
            //         break;
            //     }
            // }
            // if(sqrt(pow(x - p1.first , 2) +pow( y - p1.second , 2) * 1.0) > sqrt(pow(p2.first - x , 2) +pow( p2.second - y, 2) * 1.0))
            // {
            //     int tmp = indice;
            //     indice = indice2;
            //     indice2= indice;
            // }




            int minx = 10000;
            int miny = 10000;
            int maxx = -1;
            int maxy = -1;
            for(auto i : points )
            {
                if(minx > i.first)
                    minx = i.first;
                if(miny > i.second)
                    miny = i.second;
                if(maxx < i.first)
                    maxx = i.first;
                if(maxy < i.second)
                    maxy = i.second;
            }

            if(x < minx || x > maxx || y < miny || y > maxy)
            {
                //fixing
                x = p1.first;
                y = p1.second;
                d.setweapon(x ,y);
            }
            //changement de direction
            std::cout << p1.first << " " << p1.second   << '\n';
            std::cout <<  x << " " <<   y  << '\n';

            if( (abs(p1.first - x)== 0 ) &&  (abs(p1.second - y) == 0))
            {

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
                x +=  direction1 * sensitivity;
                y +=  direction2 * sensitivity;

                d.setweapon(x , y );

            }
            else
            {

                indice2 = (indice+1)%points.size();
                p2 = points.at(indice2);
                // vec(AC) B est sur AC si AC = AB + BC
                if(abs(distance(p1, p2) - (sqrt(pow(x - p1.first , 2) +pow( y - p1.second , 2) * 1.0) +  sqrt(pow(p2.first - x , 2) +pow( p2.second - y, 2) * 1.0)))> 1.)
                {
                    indice2 = !indice? points.size()-1: indice-1;
                    p2 = points.at(indice2);
                }
                std::cout << distance(p1, p2)<< " , "<<  sqrt(pow(x - p1.first , 2) +pow( y - p1.second , 2) * 1.0) +  sqrt(pow(p2.first - x , 2) +pow( p2.second - y, 2) * 1.0) << '\n';
                // 1 2 3 4 5 1 2 3
                // a droite 1 2 3 4 5
                // a gauche 5 4 3 2 1
                // donc en key  == 1 ie droite vec(X,x+1%N) = indiceG - indiceP
                // key == 2 = gauche vec(x+1%N,X) = indiceP - indiceG

                //DROITE
                if(key == 1)
                {
                    if(indice2 == ((indice+1)%points.size()))
                    {
                        direction1 = (p2.first - p1.first )/sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
                        direction2 = (p2.second - p1.second )/sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
                    }
                    else
                    {
                        direction1 = (p1.first - p2.first )/sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
                        direction2 = (p1.second - p2.second )/sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
                    }

                }
                else if( key == 2)
                {
                    std::cout << "here" << indice << indice2 << '\n';
                    if(indice2 == (!indice? points.size()-1: indice-1))
                    {
                        std::cout << "here again" << '\n';
                        direction1 = (p2.first - p1.first )/sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
                        direction2 = (p2.second - p1.second )/sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
                    }
                    else
                    {
                        direction1 = (p1.first - p2.first )/sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
                        direction2 = (p1.second - p2.second )/sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
                    }
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
