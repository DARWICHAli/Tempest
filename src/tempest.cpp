#include "../headers/tempest.hpp"

#include <list>

Tempest::Tempest():
  time_game{SDL_GetTicks()},
  level{0},
  score{0}
{

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
    Monsters m(r.w/2,((r.h*0.5)*1.2)*0.95);
    std::vector<Monsters> monsters;
    std::vector<double> avancement;
    monsters.push_back(m);
    avancement.push_back(0);
    int mousex= 0;
    int mousey =0;
    int key = 0; // 1 droite  ,2 gauche
    int type = 0; // si on utlise mouse ou keyboard ,, a modifier après
    double i = 0;
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
            // ACTION
            //force
            break;

        }


        play_mode = draw.print_menu(renderer);
        if(play_mode == 3)
            break;
        else if (play_mode == 2)
        {
            std::cout << "do_smth" << '\n';
            Shapes s;
            while (!quit) {
                draw.print_game(renderer,s);
                
                for( int j = 0; j<monsters.size(); j++)
                {
                    std::cout<<monsters.size()<<std::endl;
                    monsters[j].deplacement_Monster1(renderer,s.points,draw,avancement[j]);
                    avancement[j]=avancement[j]+0.000001;
                }
                if(i<3)
                {
                    monsters.push_back(m);
                    avancement.push_back(0);

                    i++;
                }
                //m.deplacement_Monster(renderer,s.points,draw,i);

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
                            SDL_Log("User just pressed down a key!");

                            /* Check the SDLKey values and move change the coords */
                            switch( event.key.keysym.sym ){
                                case SDLK_LEFT:
                                    key = 1 ;
                                    SDL_Log("LEFT!");
                                    break;
                                case SDLK_RIGHT:
                                    key = 2 ;
                                    SDL_Log("RIGHT!");
                                    break;
                                case SDLK_UP:
                                    SDL_Log("UP!");
                                    break;
                                case SDLK_DOWN:
                                    SDL_Log("DOWN!");
                                    break;
                                default:
                                    break;

                            }
                            w.MoveWeapon(renderer,mousey, mousey ,key, type,s.points,draw);
                            key = 0;
                            break;
                        }

                        // case SDL_MOUSEMOTION:
                        // {
                        //     SDL_Log("mouse_motion");
                        //     std::cout << event.motion.x << " , " << event.motion.y << '\n'
                        //     << event.motion.xrel << " , " << event.motion.yrel << '\n';
                        //     // utilise cursor
                        //     mousex = event.motion.x;
                        //     mousey = event.motion.y;
                        //     break;
                        // }
                        // case SDL_MOUSEBUTTONDOWN:
                        // {
                        //     if(event.button.button == SDL_BUTTON_LEFT)
                        //         SDL_Log("Fire Fire !");
                        //     else if(event.button.button == SDL_BUTTON_RIGHT)
                        //         SDL_Log("ultra Fire !");
                        //     break;
                        // }
                    }
                }
            }
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
