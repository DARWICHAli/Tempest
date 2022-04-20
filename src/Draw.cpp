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


Draw::Draw():
scoreval{0}
{
    font_menu1 = TTF_OpenFont("ressources/fonts/Hursheys.ttf", 100);
    font_score = TTF_OpenFont("ressources/fonts/Hursheys.ttf", 50);
    font_menu2 = TTF_OpenFont("ressources/fonts/Hursheys.ttf", 50);

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
            font=font_score;
            break;
        case 2:
            font=font_menu2;
            break;
    }
    const char * textprint = text.c_str();
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, textprint, color);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    int tempWidth, tempHeight;
    SDL_QueryTexture(Message, NULL, NULL, &tempWidth, &tempHeight);
    SDL_Rect Message_rect; //create a rect

    Message_rect.w = tempWidth/2; // controls the width of the rect
    Message_rect.h = tempHeight/2; // controls the height of the rect

    SDL_Object tmp;
    tmp.rect = Message_rect;
    tmp.texture = Message;
    tmp.width = tempWidth/2;
    tmp.height = tempHeight/2;
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
            font=font_score;
            break;
        case 2:
            font=font_menu2;
            break;
  }

  const char * textprint = text.c_str();
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, textprint, color);
  SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
  int tempWidth, tempHeight;
  SDL_QueryTexture(Message, NULL, NULL, &tempWidth, &tempHeight);
  SDL_FRect Message_rect; //create a rect

  Message_rect.w = tempWidth/2; // controls the width of the rect
  Message_rect.h = tempHeight/2; // controls the height of the rect

  SDL_FObject tmp;
  tmp.rect = Message_rect;
  tmp.texture = Message;
  tmp.width = tempWidth/2;
  tmp.height = tempHeight/2;
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

    return;
}


void Draw::initmonsters(SDL_Renderer*renderer,Shapes s,int cenx,int ceny)
{

        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(1, s.points.size());

        for( int j = 0; j< NBR_MONSTER; j++)
        {
            SDL_FObject monster;
            monster = fcalculate_texture(".",RED, 2, renderer);
            monster.rect.x=cenx;
            monster.rect.y=ceny;
            monster.direction=distrib(gen);
            monster.apper=distrib(gen)+1;
            //draw.setmonster(monster);
            monsters.push_back(monster);

        }
        return;
}

void Draw::reducetimemonsters()
{
    for (size_t i = 0; i < monsters.size(); i++)
    {
        if(monsters.at(i).apper)
            monsters.at(i).apper--;
    }
}



void Draw::init_draw(SDL_Renderer* renderer)
{
    init_menu(renderer);
    init_game(renderer);
}

void Draw::print_game(SDL_Renderer* renderer,Shapes &s, int level, Shapes &weap)
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);

    draw_elem (LIFE, renderer,0);
    draw_elem (SCORE, renderer,0);

    s.Drawshape(renderer,window_width , window_height, level);
    draw_elem(FIRE,renderer,0);
    draw_elem (MONSTER, renderer,0);

    std::pair<int , int > tmpwep = std::make_pair(weapon.rect.x, weapon.rect.y);
    weap.drawweapon(renderer,level,tmpwep);

    //test centre;
    //SDL_RenderDrawPoint(renderer, window_width/2, window_height/2);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);

    if(!monsters.size())//il n'y a pas des monstre
    {
        initmonsters(renderer,s,window_width/2,window_height/2);
        weapon.rect.x  = (s.points.at(0).first + s.points.at(1).first)/2 ;
        weapon.rect.y = (s.points.at(0).second + s.points.at(1).second)/2 - weapon.height;
    }
}

int gameloop()
{
    SDL_Event events;
    int running = 0;
    while (SDL_PollEvent(&events))
    {
        switch(events.type)
        {
            case SDL_KEYDOWN:
            switch( events.key.keysym.sym ){
                case SDLK_RIGHT:
                    SDL_Log("RIGHT!");
                    break;
                case SDLK_LEFT:
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
        }
    }
    return running;
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

    int running = 0;
    running =  gameloop();

    SDL_RenderClear(renderer);
    return running;
}


void Draw::clearlevel()
{
    monsters.clear();
    fire.clear();
    return;
}


void Draw::actionfire(int cenx ,int ceny,SDL_Renderer * renderer)
{
    double sensitivity=0.001;
    cenx -= weapon.width/2;
    ceny -= weapon.height/2;

    int lenloop1 = fire.size();
    int lenloop2 = monsters.size();
    for( auto i = fire.begin(); i< fire.end(); i++)
    {
        i->rect.x=(sensitivity*(cenx- i->rect.x))+ i->rect.x;
        i->rect.y=(sensitivity*(ceny- i->rect.y))+ i->rect.y;

        if(abs(i->rect.x - cenx)< 1 && abs(i->rect.y - ceny)< 1 )
            fire.erase(i--);

        for (auto j = monsters.begin(); j < monsters.end(); j++)
        {
            double tmp1x = j->rect.x;
            double tmp1y = j->rect.y;
            double tmp2x = i->rect.x;
            double tmp2y = i->rect.y;

            if(abs(tmp1x - tmp2x)< 1 && abs(tmp1y - tmp2y)< 1 )
            {
                //info monsters type get
                setscore(10,renderer);
                monsters.erase(j--);
                fire.erase(i--);

            }
        }


    }

    // auto it = fire.begin();
    // while (it != fire.end())
    // {
    //     it.rect.x=(sensitivity*(cenx-it.rect.x))+it.rect.x;
    //     it.rect.y=(sensitivity*(ceny-it.rect.y))+it.rect.y;
    //
    // }


    return;
}



void Draw::movemonsters(Shapes s,int cenx ,int ceny, double &z)
{
    cenx -= weapon.width/2;
    ceny -= weapon.height/2;

    // cenx = 0;
    // ceny = 0;



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

        /*
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
        */

        /*double direction1 =   (cx * mx - cy * my + s.points[p1].first - s.getcoordcentre().first) * d+ s.getcoordcentre().first;

        double direction2 = (cy * mx + cx * my + s.points[p1].second - s.getcoordcentre().second) * d+ s.getcoordcentre().second;*/
        if(monsters.at(j).apper == 0)
        {
            int p1=monsters.at(j).direction%s.points.size();
            int p2=(monsters.at(j).direction+1)%s.points.size();

            double ux = s.points[p2].first-s.points[p1].first;
            double uy = s.points[p2].second-s.points[p1].second;
            double norm =  sqrt((ux*ux)+(uy*uy));

            ux=ux/norm;
            uy=uy/norm;
            
            double mx=(s.points[p1].first+s.points[p2].first)/2;
            double my=(s.points[p1].second+s.points[p2].second)/2;
            double x = (/*(ux*cenx) - (uy*ceny)+*/mx-cenx)*h;
            double y = (/*(uy*cenx)+(ux*ceny)+*/my-ceny)*h;

            monsters.at(j).rect.x = x+cenx;
            monsters.at(j).rect.y= y+ceny;

        }


        /*
        if(monsters.at(j).apper == 0 )
        {
            double sensitivity = 0.00001;
            int p1= monsters.at(j).direction%s.points.size();
            int p2=(monsters.at(j).direction+1)%s.points.size();
            double mx=(s.points[p1].first+s.points[p2].first)/2;
            double my=(s.points[p1].second+s.points[p2].second)/2;

            int direction1 = (cenx - mx )/sqrt(pow(cenx - mx , 2) +pow( ceny -my, 2) * 1.0);
            int direction2 = (ceny - my )/sqrt(pow(cenx - mx , 2) +pow( ceny - my, 2) * 1.0);

            mx=(sensitivity*(mx-cenx))+mx;
            my=(sensitivity*(my-ceny))+my;

            monsters.at(j).rect.x = mx+cenx;
            monsters.at(j).rect.y= mx+ceny;
        }
        */
        /*mx=(sensitivity*(cx-mx))+mx;
        my=(sensitivity*(cy-my))+my;*/


        //###########################
        //Works
        // if(monsters.at(j).apper == 0 )
        // {
        //     monsters.at(j).rect.x=(sensitivity*(cenx-monsters.at(j).rect.x))+monsters.at(j).rect.x;
        //     monsters.at(j).rect.y=(sensitivity*(ceny-monsters.at(j).rect.y))+monsters.at(j).rect.y;
        // }


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
                if(!e.apper)
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

void Draw::setscore(int scorevar, SDL_Renderer* renderer)
{
    SDL_Object scoretmp = score;
    scoreval+=scorevar;
    std::string tmp =  "0 "+ std::to_string(scoreval) ;
    score = calculate_texture(tmp , GREEN, 1 , renderer);
    score.rect.x = scoretmp.rect.x;
    score.rect.y = scoretmp.rect.y;
    draw_elem (SCORE, renderer,0);
}

void Draw::setHeightWidth(int h, int w)
{
  window_width = w;
  window_height = h;

}

void Draw::setweapon(int x , int y)
{
    weapon.rect.x = x;
    weapon.rect.y = y/*-weapon.height*/;
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


std::pair<int, int> Draw::getweaponinfo()
{
    // SDL_FObject tmp;
    // tmp.height = weapon.height
    return std::make_pair(weapon.width/2, weapon.height/2);
}
