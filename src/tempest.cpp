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
    std::pair<int, int> pos = {-1,-1};
    //double i = 0;
    //double h;
    //double sensitivity=0.001;
    //double z=1;
    int level = 13;
    Shapes weaponshape;
    clock_t time_req;
    time_req = clock();

    draw.print_game(renderer,s, level,weaponshape,pos);
    draw.setlevel(level,renderer);

    // double cenx=s.getcoordcentre().first;
    // double ceny=s.getcoordcentre().second;
    double cenx= WW/2 ;
    double ceny= WH/2;

    while (!quit) {
        if((float)(clock()-time_req)/CLOCKS_PER_SEC >= .4)
        {
            draw.reducetimemonsters();
            time_req = clock();
        }

        if( draw.getmonstersize() == 0)
        {
            SDL_Log("Clear level!");
            draw.clearlevel();
            s.clearlevelShape();
            level++%15;
            draw.setlevel(level,renderer);
            std::cout << "level "<< level << '\n';
        }
        /*
        if(getlives()== 0)
        {
            break;
        }
        */

        draw.print_game(renderer,s, level,weaponshape,pos);
        //move monsters and detect collision
        //std::cout << "z is eq to " << z << '\n';
        draw.movemonsters(s,cenx ,ceny);
        //move fire and detect collision
        draw.actionfire(cenx ,ceny,renderer);
        // update score ?!

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
                            pos = w.MoveWeapon(mousey, mousey ,key, type,s.points,draw);
                            SDL_Log("RIGHT!");
                            break;
                        case SDLK_LEFT:
                            key = 2 ;
                            pos = w.MoveWeapon(mousey, mousey ,key, type,s.points,draw);
                            SDL_Log("LEFT!");
                            break;
                        case SDLK_UP:
                            SDL_Log("UP!");
                            w.FireWeapon(1,draw,renderer,s.points);
                            break;
                        case SDLK_SPACE:
                            SDL_Log("SPACE");
                            w.FireWeapon(0,draw,renderer,s.points);
                            break;
                        default:
                            break;

                    }
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
    // SDL_Rect r;
    // if (SDL_GetDisplayBounds(0, &r) != 0) {
    //     SDL_Log("SDL_GetDisplayBounds failed: %s", SDL_GetError());
    //     return 1;
    // }
    screen_width = WW/*r.w*/;
    screen_height = WH/*r.h*/;
    window = SDL_CreateWindow("Tempest", 0, 0, screen_width, screen_height,  SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
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

    int play_mode = 0;
    clock_t time_req;
    time_req = clock();
    int timer = 10;
    bool quit = false;
    Weapon w;

    int mousex= 0;
    int mousey =0;

    int type = 0; // si on utlise mouse ou keyboard ,, a modifier après

    while (!quit)
    {
        if((float)(clock()-time_req)/CLOCKS_PER_SEC >= .4)
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
            //quit = false;
            draw.game_over(renderer);
        }

    }
    return 0;
}
