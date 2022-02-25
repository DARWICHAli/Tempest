#include "../headers/Draw.hpp"
#include "../headers/Defs.hpp"
#include <cassert>
Draw::Draw()
{
    font_menu1 = TTF_OpenFont("ressources/fonts/Hursheys.ttf", 100);
    font_menu2 = TTF_OpenFont("ressources/fonts/Hursheys.ttf", 40);
    font_score = TTF_OpenFont("ressources/fonts/Hursheys.ttf", 100);

    if (font_menu1 == NULL || font_menu2 == NULL)
      std::cout << "je marche pas" << std::endl;

    window_width = 0;
    window_height = 0;
}

SDL_Object Draw::calculate_texture(std::string text,SDL_Color color,int type, SDL_Renderer* renderer)
{
    TTF_Font* font;
    switch (type) {
        case 0:
            font=font_menu1;
            break;
        case 1:
            font=font_menu2;
            break;
        case 2:
            font=font_score;
            break;
  }
  const char * textprint = text.c_str();
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, textprint, color);
  SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
  int tempWidth, tempHeight;
  SDL_QueryTexture(Message, NULL, NULL, &tempWidth, &tempHeight);
  SDL_Rect Message_rect; //create a rect

  Message_rect.w = tempWidth; // controls the width of the rect
  Message_rect.h = tempHeight; // controls the height of the rect

  SDL_Object tmp;
  tmp.rect = Message_rect;
  tmp.texture = Message;
  tmp.width = tempWidth;
  tmp.height = tempHeight;
  SDL_FreeSurface(surfaceMessage);
  //SDL_DestroyTexture(Message);
  return tmp;
}

void Draw::init_menu(SDL_Renderer* renderer)
{

    tempest_title = calculate_texture("MCMLXXX ATARI", BLUE, 1, renderer);
    player = calculate_texture("PLAYER   1", WHITE, 0, renderer);
    rate_urself = calculate_texture("RATE YOURSELF", GREEN, 1, renderer);
    use_keys = calculate_texture("USE KEYS TO CHANGE", SOFT_BLUE, 1, renderer);
    select = calculate_texture("PRESS ENTER TO SELECT", YELLOW, 1 , renderer);




    int tempest_titleX = window_width/2 - tempest_title.width/2;
    int tempest_titleY = window_height/20 - tempest_title.height/5;
    int playerX = window_width/2 - player.width/2;
    int playerY = tempest_titleY +  window_width/10 ;
    int rate_urselfX = window_width/2  - rate_urself.width/2;
    int rate_urselfY = playerY + window_width/12;
    int use_keysX = window_width/2  - use_keys.width/2;
    int use_keysY = rate_urselfY + window_width/35;
    int selectX = window_width/2  - select.width/2;
    int selectY = use_keysY + window_width/35;
    // TODO
    /*
    le reste de menu; void .hpp
    */
    tempest_title.rect.x = tempest_titleX;
    tempest_title.rect.y = tempest_titleY;
    player.rect.x = playerX;
    player.rect.y = playerY;
    rate_urself.rect.x = rate_urselfX;
    rate_urself.rect.y = rate_urselfY;
    use_keys.rect.x = use_keysX;
    use_keys.rect.y = use_keysY;
    select.rect.x = selectX;
    select.rect.y = selectY;
    /*
    position reste menu
    */
}
void Draw::init_draw(SDL_Renderer* renderer)
{
    init_menu(renderer);
  // init_score(renderer);
  // init_score_num(0, 0, renderer);
  // init_score_numGO(0, 0, renderer);
  // init_Game_over(renderer);
}




int Draw::print_menu(SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
    draw_elem (TEMPEST_TITLE, renderer);
    draw_elem (PLAYER, renderer);
    draw_elem (RATE_URSELF, renderer);
    draw_elem (USE_KEYS, renderer);
    draw_elem (PRESS_ENTER_SELECT, renderer);
    SDL_RenderPresent(renderer);

    SDL_Event events;
    int running = 0;

    while (SDL_PollEvent(&events))
    {
        switch(events.type)
        {
            case SDL_WINDOWEVENT:
                if (events.window.event == SDL_WINDOWEVENT_CLOSE)
                    running = 3;
            case SDL_MOUSEBUTTONDOWN: // Click de souris,
                if ( (events.button.x > player.rect.x && events.button.x < player.rect.x + player.width)
                && (events.button.y > player.rect.y && events.button.y < player.rect.y + player.height) )
                {
                    SDL_Log("DUNNO");
                    running = 1;
                }
                else if ( (events.button.x > rate_urself.rect.x && events.button.x < rate_urself.rect.x + rate_urself.width )
                && (events.button.y > rate_urself.rect.y && events.button.y < rate_urself.rect.y + rate_urself.height ) )
                {
                    SDL_Log("RATE SMTH!");
                    running = 2;
                }
                else if ( (events.button.x > select.rect.x && events.button.x < select.rect.x + select.width )
                && (events.button.y > select.rect.y && events.button.y < select.rect.y + select.height) )
                {
                    SDL_Log("il y a plus de bouton pour sortir ");
                    running = 3;
                }
                break;
        }
    }
    SDL_RenderClear(renderer);
    return running;
}






void Draw::draw_elem(int type, SDL_Renderer* renderer)
{
  switch(type)
  {
    case TEMPEST_TITLE:
        SDL_RenderCopy(renderer, tempest_title.texture, NULL, &tempest_title.rect);
        break;
    case PLAYER:
        SDL_RenderCopy(renderer, player.texture, NULL, &player.rect);
        break;
    case RATE_URSELF:
        SDL_RenderCopy(renderer, rate_urself.texture, NULL, &rate_urself.rect);
        break;
    case USE_KEYS:
        SDL_RenderCopy(renderer, use_keys.texture, NULL, &use_keys.rect);
        break;
    case PRESS_ENTER_SELECT:
        SDL_RenderCopy(renderer, select.texture, NULL, &select.rect);
        break;

  }
}





void Draw::setHeightWidth(int h, int w)
{
  window_width = w;
  window_height = h;

}
