#include "../headers/tempest.hpp"

#include <list>

Tempest::Tempest():
  time_game{SDL_GetTicks()},
  level{0},
  score{0}
{

}

int Tempest::game(Weapon w , Monsters m,std::vector<Monsters> &monsters,std::vector<double> &avancement)
{

    int mousex = 0;
    int mousey = 0;
    Shapes s;
    int key = 0; // 1 droite  ,2 gauche
    int type = 0; // si on utlise mouse ou keyboard ,, a modifier après
    bool quit = false;
    double i = 0;
    double d;
    draw.print_game(renderer,s);

    monsters.at(0).x = s.getcoordcentre().first;
    monsters.at(0).y = s.getcoordcentre().second;

    while (!quit) {
        draw.print_game(renderer,s);
        // if(monsters.size() == 1)
        // {
        //     m.x=s.getcoordcentre().first;
        //     m.y=s.getcoordcentre().second;
        //     monsters.at(0).x =m.x;
        //     monsters.at(0).y= m.y;
        //
        //     std::cout << "m"<<m.x << m.y<<std::endl;
        //     // monsters.push_back(m);
        // }
        for( int j = 0; j< monsters.size(); j++)
        {
            /*avancement[j]-=0.07;
            if (avancement[j] >= 0)
                d = 1 - (1 - 0.07) * sqrt(avancement[j]);
            else
                d = 1;*/
            //std::cout << "/* message */"<< monsters.at(j).x  << '\n';
            monsters[j].deplacement_Monster1(renderer,s.points,draw,d,monsters.at(j).x,monsters.at(j).y);
            //std::cout << "/* message2 */"<< monsters.at(j).x  << '\n';
            draw.setmonster(monsters.at(j).x,monsters.at(j).y,j);
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
                            w.FireWeapon(1);
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
    std::vector<Monsters> monsters;
    std::vector<double> avancement;
    monsters.push_back(m);
    avancement.push_back(1);
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
            quit = game(w,m,monsters,avancement);
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
