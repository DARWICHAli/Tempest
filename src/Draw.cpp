#include "../headers/Draw.hpp"

#include <math.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
int fake_levels = 100 ;


Draw::Draw()
{
    font_menu1 = TTF_OpenFont("ressources/fonts/Hursheys.ttf", 100);
    font_menu2 = TTF_OpenFont("ressources/fonts/Hursheys.ttf", 50);
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
    player = calculate_texture("PLAYER    1", WHITE, 0, renderer);
    rate_urself = calculate_texture("RATE YOURSELF", GREEN, 1, renderer);
    use_keys = calculate_texture("USE KEYS TO CHANGE", SOFT_BLUE, 1, renderer);
    select = calculate_texture("PRESS ENTER TO SELECT", YELLOW, 1 , renderer);
    novice = calculate_texture("NOVICE", RED, 1 , renderer);
    expert = calculate_texture("EXPERT", RED, 1 , renderer);
    level = calculate_texture("LEVEL", GREEN, 1 , renderer);
    hole = calculate_texture("HOLE", GREEN, 1 , renderer);
    bonus = calculate_texture("BONUS", GREEN, 1 , renderer);
    timer = calculate_texture("TIME   10", GREEN, 1 , renderer);
    timer = calculate_texture("TIME   10", GREEN, 1 , renderer);

    for (int i = 0; i < fake_levels; i++)
    {
        vect_level.push_back(calculate_texture(std::to_string (i), GREEN, 1 , renderer));
        //vect_hole.push_back(calculate_texture("shape in herashey", GREEN, 1 , renderer)); // couleur depond du niveau ie "i"
        vect_bonus.push_back(calculate_texture(std::to_string (i), RED, 1 , renderer));

    }


    tempest_title.rect.x = window_width/2 - tempest_title.width/2;
    tempest_title.rect.y = window_height/20 - tempest_title.height/5;
    player.rect.x = window_width/2 - player.width/2;
    player.rect.y  = tempest_title.rect.y +  window_width/10 ;
    rate_urself.rect.x = window_width/2  - rate_urself.width/2;
    rate_urself.rect.y = player.rect.y + window_width/12;
    use_keys.rect.x = window_width/2  - use_keys.width/2;
    use_keys.rect.y = rate_urself.rect.y + window_width/35;
    select.rect.x = window_width/2  - select.width/2;
    select.rect.y = use_keys.rect.y + window_width/35;

    novice.rect.x = window_width/3  + novice.width/2;
    novice.rect.y = select.rect.y + window_width/30;
    expert.rect.x = 2*window_width/3  + expert.width/2;//
    expert.rect.y = select.rect.y + window_width/30;
    level.rect.x = window_width/3 -  novice.width/2;
    level.rect.y = novice.rect.y + window_width/30;
    hole.rect.x = window_width/3-  novice.width/2 ;
    hole.rect.y = level.rect.y + window_width/32;
    bonus.rect.x = window_width/3 -  novice.width/2;
    bonus.rect.y = hole.rect.y + window_width/32;
    timer.rect.x = window_width/2  - timer.width/2;
    timer.rect.y = 17*window_height/20 - timer.height/5;

    for (size_t i = 0; i < fake_levels; i++) {
        vect_level.at(i).rect.x = window_width/3  + (3*i+1)*novice.width/2 +novice.width/2;
        vect_level.at(i).rect.y = level.rect.y;

        vect_bonus.at(i).rect.x = window_width/3  + (3*i+1)*novice.width/2;
        vect_bonus.at(i).rect.y = bonus.rect.y;
    }
    // TODO
    /*
    le reste de menu; void .hpp
    */

}

void Draw::init_game(SDL_Renderer* renderer)
{
    weapon = calculate_texture("X",BLUE, 1, renderer);
    //score ...
    std::cout <<"this is a test " << window_height << " ,  "<< window_width<< '\n';
    // weapon.rect.x = window_width*0.25 + weapon.width/2;
    // weapon.rect.y = window_height*0.875 - weapon.height/2;
    weapon.rect.x = 0;
    weapon.rect.y = 0;
    //SDL_Object monster;
    monster = calculate_texture(".",RED, 1, renderer);
    
    monster.rect.x = window_width/2;
    monster.rect.y = ((window_height*0.5)*1.2)*0.95;
    monsters.push_back(monster);
    std::cout <<"this is a test " << monster.rect.x << " ,  "<< monster.rect.y<< '\n';

}







void Draw::init_draw(SDL_Renderer* renderer)
{
    init_menu(renderer);
    init_game(renderer);
  // init_score(renderer);
  // init_score_num(0, 0, renderer);
  // init_score_numGO(0, 0, renderer);
  // init_Game_over(renderer);
}

void Draw::print_game(SDL_Renderer* renderer,Shapes &s)
{
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);

    draw_elem (WEAPON, renderer,0);
    draw_elem (MONSTER, renderer,0);
    
    
    //draw_elem (LIFE, renderer,0);
    //draw_elem (SCORE, renderer,0);


    //SDL_RenderClear(renderer);

    // check level to get the right shape
    s.DrawTriangle(renderer, window_width/2, window_height/2);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
    SDL_RenderPresent(renderer);

    /*std::cout << s.points[1].first<<std::endl;
    double d = sqrt(pow((s.points[0].first-s.points[1].first),2) + (pow((s.points[0].second-s.points[1].second),2)));
    
    double Ux=s.points[1].first-s.points[0].first;
    std::cout << "ok"<<std::endl;
    double Uy=s.points[1].second-s.points[0].second;
    double x_prim= (Ux*monster.rect.x)-(Uy*monster.rect.y);
    double y_prim= (Uy*monster.rect.x)+(Ux*monster.rect.y);
    double k=s.points[0].first+s.points[0].second;
    
    //double h;

    for (double i=0; i<=1; i=i+0.01)
    {
        std::cout <<  monster.rect.x<<std::endl;
        //sleep(2);
        /*x_prim=x_prim*(1+i);
        y_prim=y_prim*(1+i);
        monster.rect.x = (x_prim+y_prim)/k;
        monster.rect.y = monster.rect.y*(1+i);
        
        SDL_RenderCopy(renderer, monster.texture, NULL, &monster.rect);
        SDL_RenderPresent(renderer);
        //SDL_RenderClear(renderer);
    }
    sleep(2);*/

    //SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}



int Draw::print_menu(SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
    draw_elem (TEMPEST_TITLE, renderer,0);
    draw_elem (PLAYER, renderer,0);
    draw_elem (RATE_URSELF, renderer,0);
    draw_elem (USE_KEYS, renderer,0);
    draw_elem (PRESS_ENTER_SELECT, renderer,0);
    draw_elem (NOVICE, renderer,0);
    draw_elem (EXPERT, renderer,0);
    draw_elem (LEVEL, renderer,0);
    draw_elem (HOLE, renderer,0);
    draw_elem (BONUS, renderer,0);

    for (size_t i = 0; i < 5; i++) {
        draw_elem (VECT_LEVELS, renderer,i);
        draw_elem (VECT_BONUS, renderer,i);
    }


    draw_elem (TIME, renderer,0);
    SDL_RenderPresent(renderer);

    SDL_Event events;
    int running = 0;

    while (SDL_PollEvent(&events))
    {
        switch(events.type)
        {
            case SDL_KEYDOWN:
                SDL_Log("ENTER!");
                running = 2;
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






void Draw::draw_elem(int type, SDL_Renderer* renderer,int indice)
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
        case NOVICE:
            SDL_RenderCopy(renderer, novice.texture, NULL, &novice.rect);
            break;
        case EXPERT:
            SDL_RenderCopy(renderer, expert.texture, NULL, &expert.rect);
            break;
        case LEVEL:
            SDL_RenderCopy(renderer, level.texture, NULL, &level.rect);
            break;
        case HOLE:
            SDL_RenderCopy(renderer, hole.texture, NULL, &hole.rect);
            break;
        case BONUS:
            SDL_RenderCopy(renderer, bonus.texture, NULL, &bonus.rect);
            break;
        case TIME:
            SDL_RenderCopy(renderer, timer.texture, NULL, &timer.rect);
            break;
        case VECT_LEVELS:
            SDL_RenderCopy(renderer, vect_level.at(indice).texture, NULL, &vect_level.at(indice).rect);
            break;
        case VECT_BONUS:
            SDL_RenderCopy(renderer, vect_bonus.at(indice).texture, NULL, &vect_bonus.at(indice).rect);
            break;
        case WEAPON:
            SDL_RenderCopy(renderer, weapon.texture, NULL, &weapon.rect);
            break;
        case MONSTER:
            for(auto e: monsters)
                SDL_RenderCopy(renderer, e.texture, NULL, &e.rect);
            monsters.push_back(monster);
            break;
    }
}



void Draw::settimer(int time, SDL_Renderer* renderer )
{
    std::string tmp =  "TIME  "+ std::to_string(time) ;
    timer = calculate_texture(tmp , GREEN, 1 , renderer);
    timer.rect.x = window_width/2  - timer.width/2;
    timer.rect.y = 17*window_height/20 - timer.height/5;
    draw_elem (TIME, renderer,0);
}

void Draw::setHeightWidth(int h, int w)
{
  window_width = w;
  window_height = h;

}

void Draw::setweapon(int x , int y)
{
    weapon.rect.x = x;
    weapon.rect.y = y;
}
void Draw::setmonster(double x , double y)
{
    monster.rect.x = x;
    monster.rect.y = y;
}