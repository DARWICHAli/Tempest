#include "../headers/tempest.hpp"


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

    bool quit = false;
    while (!quit)
    {
        play_mode = draw.print_menu(renderer);
        if(play_mode == 3)
            break;
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
    /*
    while (start)
    {
        play_mode = draw.print_menu(renderer);
        if (play_mode == 1)
        {
            reinit_game();
            draw.init_score_num(score, level, renderer);
            while ((choice = moteur()) == 0);
            if (choice == 1)
            {
                //Mix_HaltMusic();
                //play_music(GAME_OVER);
                //draw.init_score_numGO(score, level, renderer);
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);

                if(draw.print_GameOver(renderer) ==  3)
                    start = 0;

                else if(draw.print_GameOver(renderer) == 1)
                {
                    play_music(MAIN_THEME);
                    SDL_RenderClear(renderer);
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
                    draw.print_menu(renderer);
                }
            }
        }
        else if (play_mode == 2)
        {
        int bot_num = 0;
        Bot bot;
        bot.init_game_bot(screen_height, screen_width, cell_height, cell_width);
        while((bot_num = bot.moteur(renderer)) == 0);
        if (bot_num == 2)
        start = 0;
        }

        else if (play_mode == 3)
        start = 0;
    }*/
    return 0;
}
