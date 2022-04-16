#include "../headers/weapon.hpp"


float sensitivity = 40;

Weapon::Weapon ():
    x{0},y{0}
{}
Weapon::~Weapon (){}

void sound(std::string name)
{
    std::string tmp = "ressources/sound/"+ name ;
    if(SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not be initialized!\n"
        "SDL_Error: %s\n", SDL_GetError());
        return;
    }

    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
    {
        printf("SDL2_mixer could not be initialized!\n"
        "SDL_Error: %s\n", SDL_GetError());
        return;
    }

    Mix_Music *clapnsnare = Mix_LoadMUS(tmp.c_str());
    if(Mix_PlayMusic(clapnsnare, -1) == -1)
    {
        printf(".OGG sound could not be played!\n"
        "SDL_Error: %s\n", SDL_GetError());
    }

   //Mix_CloseAudio(); //Fermeture de l'API
}


float distance(std::pair<int, int> p1,std::pair<int, int> p2)
{
    return sqrt(pow(p2.first - p1.first , 2) +pow( p2.second - p1.second , 2) * 1.0);
}


void Weapon::MoveWeapon( int32_t centreX, int32_t centreY, int32_t key , int32_t  type ,std::vector<std::pair<int, int>> points,Draw &d)
{
    float direction1;
    float direction2;
    std::pair<int, int> p1;
    std::pair<int, int> p2 ;
    std::pair<int, int> tmp;
    std::size_t indice;
    std::size_t indice2;

    // on va commencer la partie
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
            //sound("ogg_blasterMove.ogg");

            for (std::size_t it = 0; it < points.size(); ++it)
            {
                indice = it;
                indice2 = (it+1)%points.size();
                p1 = points.at(it);
                p2 = points.at(indice2);
                if(abs(distance(p1, p2) - (sqrt(pow(x - p1.first , 2) +pow( y - p1.second , 2) * 1.0) +  sqrt(pow(p2.first - x , 2) +pow( p2.second - y, 2) * 1.0)))< 2.)
                {
                    break;
                }
                indice2 = !indice? points.size()-1: indice-1;
                p2 = points.at(indice2);
                if(abs(distance(p1, p2) - (sqrt(pow(x - p1.first , 2) +pow( y - p1.second , 2) * 1.0) +  sqrt(pow(p2.first - x , 2) +pow( p2.second - y, 2) * 1.0)))< 2.)
                {
                    break;
                }
            }
        //droite
            if(key == 1 )
            {
                p1 = points.at((indice+1)%points.size());
                p2 = points.at((indice2+1)%points.size());
            }
            else if(key == 2)
            {
                p1 = points.at(!indice? points.size()-1: indice-1);
                p2 = points.at(!indice2? points.size()-1: indice2-1);

            }
            x =  (p1.first + p2.first)/2;
            y = (p1.second + p2.second)/2;
            d.setweapon(x , y );

        }
    }
    else
    {
        std::cout << "lol" << '\n';
    }
}



void Weapon::FireWeapon(int32_t type, Draw&d,SDL_Renderer* renderer)
{
    SDL_FObject f;
    if(type == 0)
    {
        
        f = d.fcalculate_texture(".",GREEN, 1, renderer);
        f.rect.x=x;
        f.rect.y=y;
        d.fire.push_back(f);

    }
    else if(type == 1)
    {
        //sound("ogg_blasterBullet.ogg");
    }


}

void Weapon:: MoveMissile(Shapes &s,Draw &d)
{
    double sensitivity=0.02;
    for(auto e : d.fire)
    {
        std::cout << "i'm here" << std::endl;
        double cx=s.getcoordcentre().first;
        double cy=s.getcoordcentre().second;
        std::cout << "cx="<<cx << std::endl;
        std::cout << "cy="<<cy << std::endl;
        std::cout << "x="<<e.rect.x << std::endl;
        e.rect.x=(sensitivity*(-cx+e.rect.x))+e.rect.x;
        e.rect.y=(sensitivity*(-cy+e.rect.y))+e.rect.y;
        std::cout << "xaprès="<<e.rect.x << std::endl;

    }
    
}
