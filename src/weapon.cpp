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


std::pair<int, int>  Weapon::MoveWeapon( int32_t centreX, int32_t centreY, int32_t key , int32_t  type ,std::vector<std::pair<int, int>> points,Draw &d)
{
    if(!key)
        return std::make_pair(-1,-1);

    float direction1;
    float direction2;
    std::pair<int, int> p1;
    std::pair<int, int> p2 ;
    std::pair<int, int> tmp;
    std::size_t indice;
    std::size_t indice2;

    // on va commencer la partie
    std::pair<int, int> wepinfo = d.getweaponinfo();

    if(!x && !y)
    {
        x = (points.at(0).first + points.at(1).first)/2 - wepinfo.first;
        y = (points.at(0).second + points.at(1).second)/2 - wepinfo.second;
        // weapon.rect.x  = (s.points.at(0).first + s.points.at(1).first)/2 ;
        // weapon.rect.y = (s.points.at(0).second + s.points.at(1).second)/2 - weapon.height;
    }
    // clavier
    if(type == 0 )
    {

        if(key) // 1 ou 2
        {
            //sound("ogg_blasterMove.ogg");
            int tmpx = x + wepinfo.first;
            int tmpy = y + wepinfo.second;
            for (std::size_t it = 0; it < points.size(); ++it)
            {
                indice = it;
                indice2 = (it+1)%points.size();
                p1 = points.at(it);
                p2 = points.at(indice2);
                if(abs(distance(p1, p2) - (sqrt(pow(tmpx - p1.first , 2) +pow( tmpy - p1.second , 2) * 1.0) +  sqrt(pow(p2.first - tmpx , 2) +pow( p2.second - tmpy, 2) * 1.0)))< 2.)
                {
                    break;
                }
                indice2 = !indice? points.size()-1: indice-1;
                p2 = points.at(indice2);
                if(abs(distance(p1, p2) - (sqrt(pow(tmpx - p1.first , 2) +pow( tmpy - p1.second , 2) * 1.0) +  sqrt(pow(p2.first - tmpx , 2) +pow( p2.second - tmpy, 2) * 1.0)))< 2.)
                {
                    break;
                }
            }
        //droite
            if(key == 1 )
            {
                indice = (indice+1)%points.size();
                indice2 = (indice2+1)%points.size();
                p1 = points.at(indice);
                p2 = points.at(indice2);
            }
            else if(key == 2)
            {
                indice = !indice? points.size()-1: indice-1;
                indice2 = !indice2? points.size()-1: indice2-1;
                p1 = points.at(indice);
                p2 = points.at(indice2);

            }
            x =  (p1.first + p2.first)/2 - wepinfo.first;
            y = (p1.second + p2.second)/2 - wepinfo.second;
            d.setweapon(x , y );
        }
    }
    else
    {
        std::cout << "lol" << '\n';
    }

    return std::make_pair(indice,indice2);
}

int Weapon::getdirection(std::vector<std::pair<int, int>> points , Draw&d)
{
    int dir;
    int ind1,ind2;
    std::pair<int, int> p1;
    std::pair<int, int> p2 ;
    std::pair<int, int> wepinfo = d.getweaponinfo();
    int tmpx = x + wepinfo.first;
    int tmpy = y + wepinfo.second;

    for (size_t i = 0; i < points.size(); i++) {
        ind1 = i;
        ind2 = i+1%points.size();
        p1 = points.at(ind1);
        p2 = points.at(ind2);
        if(abs(distance(p1, p2) - (sqrt(pow(tmpx - p1.first , 2) +pow( tmpy - p1.second , 2) * 1.0) +  sqrt(pow(p2.first - tmpx , 2) +pow( p2.second - tmpy, 2) * 1.0)))< 2.)
        {
            break;
        }
        ind2 = !ind1? points.size()-1: ind1-1;
        p2 = points.at(ind2);
        if(abs(distance(p1, p2) - (sqrt(pow(tmpx - p1.first , 2) +pow( tmpy - p1.second , 2) * 1.0) +  sqrt(pow(p2.first - tmpx , 2) +pow( p2.second - tmpy, 2) * 1.0)))< 2.)
        {
            break;
        }

    }
    int res;
    if(ind2 == 0 )
        res = points.size();
    else if(ind1 == 0)
        res = points.size();
    else
        res = ind1 < ind2 ? ind1: ind2;

    return res;
}

void Weapon::FireWeapon(int32_t type, Draw&d,std::shared_ptr<SDL_Renderer> renderer,std::vector<std::pair<int, int>> points )
{
    SDL_FObject f;
    //important if fire before moving of the first time
    // it position the weapon on the first line drawn
    if(!x && !y)
    {
        std::pair<int, int> wepinfo = d.getweaponinfo();
        x = (points.at(0).first + points.at(1).first)/2 - wepinfo.first;
        y = (points.at(0).second + points.at(1).second)/2 - wepinfo.second;

    }
    if(type == 0)
    {
        f = d.fcalculate_texture(".",GREEN, 2, renderer);
        f.rect.x=x;
        f.rect.y=y;
        f.direction = getdirection(points,d);
        //d.append_fire(1);
        d.addfire_init(x,y);
        d.addfire(f);

    }
    else if(type == 1)
    {
        //sound("ogg_blasterBullet.ogg");
        f = d.fcalculate_texture("X",RED, 2, renderer);
        f.rect.x=x;
        f.rect.y=y;
        f.direction = getdirection(points,d);
        //d.append_fire(1);
        d.addfire_init(x,y);
        d.addfire(f);
    }
}
