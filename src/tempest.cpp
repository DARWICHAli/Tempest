#include "../headers/tempest.hpp"

#include "../headers/constant.hpp"
#include <list>
#include <random>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>


Tempest::Tempest():
  time_game{SDL_GetTicks()},
  level{0},
  score{0}
{

}



int Tempest::game(Weapon w, Draw &draw)
{

    int mousex = 0;
    int mousey = 0;
    Shapes s;
    int key = 0; // 1 droite  ,2 gauche
    int type = 0; // si on utlise mouse ou keyboard ,, a modifier après
    bool quit = false;
    double i = 0;
    double d;
    double sensitivity=0.001;
    double z=1;

    int level = 1;
    draw.print_game(renderer,s, level);


    double cenx=s.getcoordcentre().first;
    double ceny=s.getcoordcentre().second;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, s.points.size());

    if(draw.monsters.size()==0)
    {

        for( int j = 0; j< NBR_MONSTER; j++)
        {
            SDL_FObject monster;
            monster = draw.fcalculate_texture(".",RED, 1, renderer);
            monster.rect.x=cenx;
            monster.rect.y=ceny;
            std::cout<<monster.rect.x<<std::endl;
            monster.direction=distrib(gen);
            draw.monsters.push_back(monster);
        }
    }

    while (!quit) {

        if(draw.monsters.size() == 0)
        {
            // clear board
            // init
            // level++
            // print_game(level)
            SDL_Log("Clear level!");
            //clear_level();
            s.points.clear();
            s.points_centre.clear();

            level++%15;
            draw.print_game(renderer,s, level);

            double cenx=s.getcoordcentre().first;
            double ceny=s.getcoordcentre().second;
            std::uniform_int_distribution<> distrib(1, s.points.size());
            for( int j = 0; j< NBR_MONSTER; j++)
            {
                SDL_FObject monster;
                monster = draw.fcalculate_texture(".",RED, 1, renderer);
                monster.rect.x=cenx;
                monster.rect.y=ceny;
                std::cout<<monster.rect.x<<std::endl;
                monster.direction=distrib(gen);
                draw.monsters.push_back(monster);
            }

        }


        draw.print_game(renderer,s,level);
        z -= 0.7;
        if (z >= 0)
            d = 1 - (1 - 0.07) * sqrt(z);
        else
            d = 1;
        for( int j = 0; j< draw.monsters.size(); j++)
        {

            int p1=draw.monsters[j].direction%s.points.size();
            int p2=(draw.monsters[j].direction+1)%s.points.size();


            double cx=(s.points[p1].first+s.points[p2].first)/2;
            double cy=(s.points[p1].second+s.points[p2].second)/2;
            //double normc=sqrt(cx*cx+cy*cy);
            /*cx=cx/normc;
            cy=cy/normc;*/
            double mx=draw.monsters.at(j).rect.x;
            double my=draw.monsters.at(j).rect.y;



            /*double direction1 =   (cx * mx - cy * my + s.points[p1].first - s.getcoordcentre().first) * d+ s.getcoordcentre().first;

            double direction2 = (cy * mx + cx * my + s.points[p1].second - s.getcoordcentre().second) * d+ s.getcoordcentre().second;*/
            // int direction1 = (cx - mx )/sqrt(pow(cx - mx , 2) +pow( cy -my, 2) * 1.0);
            // int direction2 = (cy - my )/sqrt(pow(cx - mx , 2) +pow( cy - my, 2) * 1.0);

            // mx=(sensitivity*(mx-cx))+mx;
            // my=(sensitivity*(my-cy))+my;
            mx=(sensitivity*(cx-mx))+mx;
            my=(sensitivity*(cy-my))+my;

            draw.monsters.at(j).rect.x=mx;
            draw.monsters.at(j).rect.y=my;


            if(abs(draw.monsters.at(j).rect.x - cx)< 1 &&  abs(draw.monsters.at(j).rect.y - cy)< 1 )
                draw.monsters.erase(draw.monsters.begin() + j);




        }
        //for(auto e : draw.fire)
        for( int i = 0; i< draw.fire.size(); i++)
        {
            draw.fire[i].rect.x=(sensitivity*(cenx-draw.fire[i].rect.x))+draw.fire[i].rect.x;
            draw.fire[i].rect.y=(sensitivity*(ceny-draw.fire[i].rect.y))+draw.fire[i].rect.y;

            for (size_t j = 0; j < draw.monsters.size(); j++) {
                double tmp1x = draw.monsters.at(j).rect.x;
                double tmp1y = draw.monsters.at(j).rect.y;
                double tmp2x = draw.fire.at(i).rect.x;
                double tmp2y = draw.fire.at(i).rect.y;


                if(abs(tmp1x - tmp2x)< 1 && abs(tmp1y - tmp2y)< 1 )
                {
                    draw.monsters.erase(draw.monsters.begin() + j);
                    draw.fire.erase(draw.fire.begin() + i);
                }
            }
            if(abs(draw.fire[i].rect.x - cenx)< 1 && abs(draw.fire[i].rect.y - ceny)< 1 )
                draw.fire.erase(draw.fire.begin() + i);


        }




        SDL_Event event;
        while (!quit && SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                {
                    std::cout << "fin" << '\n';
                    quit = true;
                    break;
                }
                case SDL_KEYDOWN:
                {
                    switch( event.key.keysym.sym ){
                        case SDLK_RIGHT:
                            key = 1 ;
                            SDL_Log("RIGHT!");
                            break;
                        case SDLK_LEFT:
                            key = 2 ;
                            SDL_Log("LEFT!");
                            break;
                        case SDLK_UP:
                            SDL_Log("UP!");
                            break;
                        case SDLK_DOWN:
                            SDL_Log("DOWN!");
                            w.FireWeapon(0,draw,renderer);
                            break;
                        default:
                            break;

                    }
                    w.MoveWeapon(mousey, mousey ,key, type,s.points,draw);
                    SDL_RenderPresent(renderer);
                    key = 0;
                    break;
                }
            }
        }
    }
    return quit;
}




int Tempest::init_game()
{
    SDL_Rect r;
    if (SDL_GetDisplayBounds(0, &r) != 0) {
        SDL_Log("SDL_GetDisplayBounds failed: %s", SDL_GetError());
        return 1;
    }
    screen_width = r.w;
    screen_height = r.h;

    window = SDL_CreateWindow("Tempest", 0, 0, screen_width, screen_height,  SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Renderer* renderer_bot = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (window && renderer)
    {
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
      SDL_RenderClear(renderer);
    }
    else
    {
      fprintf(stderr,"SDL_CREATE: %s\n",SDL_GetError());
      exit(EXIT_FAILURE);
    }

    draw.setHeightWidth(screen_height, screen_width);
    draw.init_draw(renderer);
    draw.print_menu(renderer);
    SDL_RenderPresent(renderer);
    int choice = 0;
    int play_mode = 0;
    int start = 1;
    clock_t time_req;
    time_req = clock();
    int timer = 10;
    bool quit = false;
    Weapon w;
    Monsters m(0,0);

    int mousex= 0;
    int mousey =0;

    int type = 0; // si on utlise mouse ou keyboard ,, a modifier après

    while (!quit)
    {
        if((float)(clock()-time_req)/CLOCKS_PER_SEC >= .35) // a modifier
        {
            timer--;
            draw.settimer(timer ,renderer);
            time_req = clock();
        }
        if(timer == 0)
        {
            std::cout << "time's up!!" << '\n';
            break;

        }
        play_mode = draw.print_menu(renderer);
        if(play_mode == 3)
            break;
        else if (play_mode == 2)
        {

            quit = game(w,draw);
        }
        else if (play_mode == 1)
        {
            std::cout << "do_smth 2" << '\n';
        }
        SDL_Event event;
        while (!quit && SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    std::cout << "fin" << '\n';
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    SDL_Log("User just pressed down a key!");

            }
        }
    }
    return 0;
}
