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

SDL_FObject Draw::fcalculate_texture(std::string text,SDL_Color color,int type, SDL_Renderer* renderer)
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
  SDL_FRect Message_rect; //create a rect

  Message_rect.w = tempWidth; // controls the width of the rect
  Message_rect.h = tempHeight; // controls the height of the rect

  SDL_FObject tmp;
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
    player = calculate_texture("PLAYER    1", WHITE, 1, renderer);
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
    rate_urself.rect.y = player.rect.y + rate_urself.height;
    use_keys.rect.x = window_width/2  - use_keys.width/2;
    use_keys.rect.y = rate_urself.rect.y + use_keys.height;
    select.rect.x = window_width/2  - select.width/2;
    select.rect.y = use_keys.rect.y + select.height;

    novice.rect.x = window_width/3  + novice.width/2;
    novice.rect.y = select.rect.y + novice.height;
    expert.rect.x = 2*window_width/3  + expert.width/2;//
    expert.rect.y = select.rect.y + expert.height;
    level.rect.x = window_width/3 -  novice.width/2;
    level.rect.y = novice.rect.y + level.height;
    hole.rect.x = window_width/3-  novice.width/2 ;
    hole.rect.y = level.rect.y + hole.height;
    bonus.rect.x = window_width/3 -  novice.width/2;
    bonus.rect.y = hole.rect.y + bonus.height;
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
    score = calculate_texture("000",GREEN, 1, renderer);
    life = calculate_texture("XXXXX",YELLOW, 1, renderer);

    weapon.rect.x = 0;
    weapon.rect.y = 0;
    life.rect.x = window_width*0.25;
    life.rect.y = window_height*0.125;
    score.rect.x = window_width*0.25;
    score.rect.y = life.rect.y - 50;




}

void Draw::initmonsters(SDL_Renderer*renderer,Shapes s,int cenx,int ceny)
{

        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(1, s.points.size());

        for( int j = 0; j< NBR_MONSTER; j++)
        {
            SDL_FObject monster;
            monster = fcalculate_texture(".",RED, 1, renderer);
            monster.rect.x=cenx;
            monster.rect.y=ceny;
            monster.direction=distrib(gen);
            monster.apper=j+5;
            //draw.setmonster(monster);
            monsters.push_back(monster);

        }
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

void Draw::print_game(SDL_Renderer* renderer,Shapes &s, int level)
{
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);

    draw_elem (WEAPON, renderer,0);
    draw_elem (LIFE, renderer,0);
    draw_elem (SCORE, renderer,0);
    // check level to get the right shape
    s.Drawshape(renderer,window_width , window_height, level);
    //s.DrawTriangle(renderer,window_width/2 , window_height/2);
    draw_elem(FIRE,renderer,0);
    draw_elem (MONSTER, renderer,0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);

    if(!monsters.size())//il n'y a pas des monstre
    {
        initmonsters(renderer,s,window_width/2,window_height/2);
    }
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
            switch( events.key.keysym.sym ){
                case SDLK_RIGHT:
                    // move holes to right
                    SDL_Log("RIGHT!");
                    break;
                case SDLK_LEFT:
                    // move holes to left
                    SDL_Log("LEFT!");
                    break;
                case SDLK_RETURN:
                    SDL_Log("ENTER!");
                    running = 2;
                }
                break;
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


void Draw::clearlevel()
{
    monsters.clear();
    fire.clear();
    return;
}

void Draw::actionfire(int cenx ,int ceny)
{
    double sensitivity=0.001;
    for( int i = 0; i< fire.size(); i++)
    {
        fire[i].rect.x=(sensitivity*(cenx-fire[i].rect.x))+fire[i].rect.x;
        fire[i].rect.y=(sensitivity*(ceny-fire[i].rect.y))+fire[i].rect.y;

        for (size_t j = 0; j < monsters.size(); j++) {
            double tmp1x = monsters.at(j).rect.x;
            double tmp1y = monsters.at(j).rect.y;
            double tmp2x = fire.at(i).rect.x;
            double tmp2y = fire.at(i).rect.y;

            if(abs(tmp1x - tmp2x)< 1 && abs(tmp1y - tmp2y)< 1 )
            {
                // draw.delmonster(j,0);
                monsters.erase(monsters.begin() + i);
                fire.erase(fire.begin() + i);
            }
        }
        if(abs(fire[i].rect.x - cenx)< 1 && abs(fire[i].rect.y - ceny)< 1 )
            fire.erase(fire.begin() + i);
    }
    return;
}

void Draw::movemonsters(Shapes s,int cenx ,int ceny, double &z)
{
    double h;
    if (z > 0)
    {
        h =1- (1 - SCALE_VAL) * pow(z,2);
    }
    else
    {
        h = 1;
    }
    z -= 0.00007;
    //i++;
    for( int j = 0; j< monsters.size(); j++)
    {
        /*if (i > draw.getmonster(j).apper)
        {
            int p1=draw.getmonster(j).direction%s.points.size();
        int p2=(draw.getmonster(j).direction+1)%s.points.size();

        double ux = s.points[p2].first-s.points[p1].first;
        double uy=s.points[p2].second-s.points[p1].second;

        std::cout << "d = " << d << std::endl;

        double norm =  sqrt((ux*ux)+(uy*uy));
        ux=ux/norm;
        uy=uy/norm;

        double cx=(s.points[p1].first+s.points[p2].first)/2;
        double cy=(s.points[p1].second+s.points[p2].second)/2;

        double ux_prim = s.getcoordcentre().first-cx;
        double uy_prim = s.getcoordcentre().second-cy;

        double n = sqrt(ux_prim*ux_prim+uy_prim*uy_prim);


            double mx=draw.getmonster(j).rect.x;
            double my=draw.getmonster(j).rect.y;


            double x_prim= (((ux*mx)-(uy*my))*d )+cx;
            double y_prim= (((uy*mx)+(ux*my))*d)+cy;


            draw.getmonster(j).rect.x=x_prim;
            draw.getmonster(j).rect.y=y_prim;


        std::cout << "x apres = " << draw.getmonster(j).rect.x << std::endl;
        std::cout << "y apres = " << draw.getmonster(j).rect.y << std::endl;
        if(abs(draw.getmonster(j).rect.x - cx)< 1 &&  abs(draw.getmonster(j).rect.y - cy)< 1 )
            draw.monsters.erase(draw.monsters.begin() + j);


        }*/
        // double cx = s.getcoordcentre().first;
        // double cy = s.getcoordcentre().second;


        int p1= monsters.at(j).direction%s.points.size();
        int p2=(monsters.at(j).direction+1)%s.points.size();

        double mx=(s.points[p1].first+s.points[p2].first)/2;
        double my=(s.points[p1].second+s.points[p2].second)/2;

        double ux = s.points[p2].first-s.points[p1].first;
        double uy =  s.points[p2].second-s.points[p1].second;

        double norm =  sqrt((ux*ux)+(uy*uy));
        ux=ux/norm;
        uy=uy/norm;

        double x = ((ux*cenx) - (uy*ceny)+mx)*h;
        double y = ((uy*cenx)+(ux*ceny)+my)*h;

        monsters.at(j).rect.x = x+cenx;
        monsters.at(j).rect.y= y+ceny;


        /*double direction1 =   (cx * mx - cy * my + s.points[p1].first - s.getcoordcentre().first) * d+ s.getcoordcentre().first;

        double direction2 = (cy * mx + cx * my + s.points[p1].second - s.getcoordcentre().second) * d+ s.getcoordcentre().second;*/
        // int direction1 = (cx - mx )/sqrt(pow(cx - mx , 2) +pow( cy -my, 2) * 1.0);
        // int direction2 = (cy - my )/sqrt(pow(cx - mx , 2) +pow( cy - my, 2) * 1.0);

        // mx=(sensitivity*(mx-cx))+mx;
        // my=(sensitivity*(my-cy))+my;
        /*mx=(sensitivity*(cx-mx))+mx;
        my=(sensitivity*(cy-my))+my;*/

    }
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
            {
                SDL_RenderCopyF(renderer, e.texture, NULL, &e.rect);
            }
            break;
        case FIRE:
            for(auto e: fire)
            {
                SDL_RenderCopyF(renderer, e.texture, NULL, &e.rect);
            }
            break;
        case LIFE:
            SDL_RenderCopy(renderer, life.texture, NULL, &life.rect);
            break;
        case SCORE:
            SDL_RenderCopy(renderer, score.texture, NULL, &score.rect);
            break;
    }
}


// void Draw::setscore(int score, SDL_Renderer* renderer )
// {
//     std::string tmp =  "SCORE  "+ std::to_string(time) ;
//     timer = calculate_texture(tmp , GREEN, 1 , renderer);
//     timer.rect.x = window_width/2  - timer.width/2;
//     timer.rect.y = 17*window_height/20 - timer.height/5;
//     draw_elem (TIME, renderer,0);
// }




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
    return;
}
void Draw::addfire(SDL_FObject f)
{
    fire.push_back(f);
    return;
}

void Draw::setmonster(SDL_FObject monster)
{
    monsters.push_back(monster);
}
void Draw::delmonster(int indice , int type_er)
{
    if(type_er)
    {
        monsters.clear();
    }
    else
    {
        monsters.erase(monsters.begin() + indice);
    }
}

int Draw::getmonstersize()
{
    return int(monsters.size());
}
SDL_FObject Draw::getmonster(int indice)
{
    return monsters.at(indice);
}
