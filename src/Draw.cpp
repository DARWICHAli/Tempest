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
    font_score = TTF_OpenFont("ressources/fonts/Hursheys.ttf", 100);
    font_menu2 = TTF_OpenFont("ressources/fonts/Hursheys.ttf", 50);

    if (font_menu1 == NULL || font_menu2 == NULL)
      std::cout << "je marche pas" << std::endl;

    window_width = 0;
    window_height = 0;
}

SDL_Object Draw::calculate_texture(std::string text,SDL_Color color,int type, std::shared_ptr<SDL_Renderer> renderer)
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
    std::shared_ptr<SDL_Surface> surfaceMessage = sdl_shared(TTF_RenderText_Solid(font, textprint, color));
    std::shared_ptr<SDL_Texture> Message = sdl_shared(SDL_CreateTextureFromSurface(renderer.get(), surfaceMessage.get()));
    int tempWidth, tempHeight;
    SDL_QueryTexture(Message.get(), NULL, NULL, &tempWidth, &tempHeight);
    SDL_Rect Message_rect; //create a rect

    Message_rect.w = tempWidth/2; // controls the width of the rect
    Message_rect.h = tempHeight/2; // controls the height of the rect

    SDL_Object tmp;
    tmp.rect = Message_rect;
    tmp.texture = Message;
    tmp.width = tempWidth/2;
    tmp.height = tempHeight/2;

    //SDL_FreeSurface(surfaceMessage.get());
    //SDL_DestroyTexture(Message);
    return tmp;
}

SDL_FObject Draw::fcalculate_texture(std::string text,SDL_Color color,int type, std::shared_ptr<SDL_Renderer> renderer)
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
  std::shared_ptr<SDL_Surface> surfaceMessage =   sdl_shared(TTF_RenderText_Solid(font, textprint, color));
  std::shared_ptr<SDL_Texture> Message = sdl_shared(SDL_CreateTextureFromSurface(renderer.get(), surfaceMessage.get()));
  int tempWidth, tempHeight;
  SDL_QueryTexture(Message.get(), NULL, NULL, &tempWidth, &tempHeight);
  SDL_FRect Message_rect; //create a rect

  Message_rect.w = tempWidth/2; // controls the width of the rect
  Message_rect.h = tempHeight/2; // controls the height of the rect

  SDL_FObject tmp;
  tmp.rect = Message_rect;
  tmp.texture = Message;
  tmp.width = tempWidth/2;
  tmp.height = tempHeight/2;
  //SDL_FreeSurface(surfaceMessage.get());
  //SDL_DestroyTexture(Message);
  return tmp;
}

void Draw::init_menu(std::shared_ptr<SDL_Renderer> renderer)
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

void Draw::init_game(std::shared_ptr<SDL_Renderer> renderer)
{
    weapon = calculate_texture("X",BLUE, 1, renderer);
    score = calculate_texture("000",GREEN, 1, renderer);
    life = calculate_texture("XXXXX",YELLOW, 1, renderer);
    level_game = calculate_texture("0",GREEN, 1, renderer);

    lifeval = 5;

    weapon.rect.x = 0;
    weapon.rect.y = 0;

    life.rect.x = window_width/4;
    life.rect.y = window_height/8;

    score.rect.x = window_width/4;
    score.rect.y = life.rect.y - 50;

    level_game.rect.x = window_width/2;
    level_game.rect.y = window_height/10;

    return;
}


<<<<<<< HEAD
void Draw::initmonsters(std::shared_ptr<SDL_Renderer>renderer,Shapes s,int cenx,int ceny)
=======
void Draw::initmonsters(const int& cenx,const int& ceny)
>>>>>>> dev
{

        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(1, NBR_MONSTER/2);

        for( int j = 0; j< NBR_MONSTER; j++)
        {
            //SDL_FObject monster;
            Monster  monster(cenx-weapon.width/2,ceny-weapon.height/2,distrib(gen),distrib(gen)+1,1/SCALE_VAL);
            // monster = fcalculate_texture(".",RED, 2, renderer);
            // monster.rect.x=cenx-weapon.width/2;
            // monster.rect.y=ceny-weapon.height/2;
            // monster.direction=distrib(gen);
            // monster.apper=distrib(gen)+1;
            //draw.setmonster(monster);
            //std :: cout << "MX = "<< monster.get_x() <<std::endl;
            monsters.push_back(monster);


        }
        return;
}

void Draw::reducetimemonsters()
{
    for (size_t i = 0; i < monsters.size(); i++)
    {
        monsters.at(i).reduce_apper();
    }
}



void Draw::init_draw(std::shared_ptr<SDL_Renderer> renderer)
{
    init_menu(renderer);
    init_game(renderer);
    init_game_over(renderer);
}

void Draw::init_game_over(std::shared_ptr<SDL_Renderer> renderer)
{

    game_over_var  =  calculate_texture("GAME OVER !!!",RED, 1, renderer);
    game_over_var.rect.x = window_width/2 - game_over_var.width/2;
    game_over_var.rect.y = window_height/8;

    // score.rect.x = window_width/2 - score.width/2;
    // score.rect.y = game_over_var.rect.y + score.height*2;


}



void Draw::print_game(std::shared_ptr<SDL_Renderer> renderer,Shapes &s, int level, Shapes &weap,std::pair<int, int> pos)
{
    SDL_RenderClear(renderer.get());
    SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0xff);

    draw_elem (LIFE, renderer,0);
    draw_elem (SCORE, renderer,0);
    draw_elem(LEVEL_GAME,renderer,0);

    s.Drawshape(renderer,window_width , window_height, level);

    std::pair<int , int > tmpwep = std::make_pair(weapon.rect.x, weapon.rect.y);
    weap.drawweapon(renderer,level,tmpwep);
    //test centre;
    //SDL_RenderDrawPoint(renderer, window_width/2, window_height/2);

    if(pos.first != -1)
        s.colorcol(renderer,pos,1);


<<<<<<< HEAD
    SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0xff);
    SDL_RenderPresent(renderer.get());
    SDL_RenderClear(renderer.get());

=======
>>>>>>> dev
    if(!monsters.size())//il n'y a pas des monstre
    {
        initmonsters(window_width/2,window_height/2);
        weapon.rect.x  = (s.points.at(0).first + s.points.at(1).first)/2 ;
        weapon.rect.y = (s.points.at(0).second + s.points.at(1).second)/2 - weapon.height/2;
    }

    draw_elem (MONSTER, renderer,0);
    draw_elem(FIRE,renderer,0);

    SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0xff);
    SDL_RenderPresent(renderer.get());
    SDL_RenderClear(renderer.get());




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

void Draw::game_over(std::shared_ptr<SDL_Renderer> renderer)
{
    clock_t time_req;
    time_req = clock();
    int timer = 13;
    bool quit = false;

    score.rect.x = window_width/2 - score.width/2;
    score.rect.y = game_over_var.rect.y + score.height*2;

    SDL_RenderClear(renderer.get());
    SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0xff);

    while (!quit)
    {
        draw_elem (SCORE, renderer,0);
        draw_elem (TIME, renderer,0);
        draw_elem (GAME_OVER, renderer,0);

        SDL_RenderPresent(renderer.get());
        SDL_RenderClear(renderer.get());
        if((float)(clock()-time_req)/CLOCKS_PER_SEC >= .5)
        {
            timer--;
            settimer(timer ,renderer);
            time_req = clock();
        }
        if(timer == 0)
        {
            std::cout << "time's up!!" << '\n';
            break;
        }
        SDL_Event event;
        while (!quit && SDL_PollEvent(&event))
        {
            if(event.type ==SDL_QUIT ){
                std::cout << "fin" << '\n';
                quit = true;
                break;
            }
        }
    }

}



int Draw::print_menu(std::shared_ptr<SDL_Renderer> renderer)
{
    SDL_RenderClear(renderer.get());
    SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0xff);
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

    SDL_RenderPresent(renderer.get());

    int running = 0;
    running =  gameloop();

    SDL_RenderClear(renderer.get());
    return running;
}


void Draw::clearlevel()
{
    monsters.clear();
    fire.clear();
    return;
}

void Draw::actionfire(int cenx ,int ceny, std::shared_ptr<SDL_Renderer> renderer)
{
    double sensitivity=0.001;
    cenx -= weapon.width/2;
    ceny -= weapon.height/2;

    for( auto i = fire.begin(); i< fire.end(); i++)
    {
        i->rect.x=(sensitivity*(cenx- i->rect.x))+ i->rect.x;
        i->rect.y=(sensitivity*(ceny- i->rect.y))+ i->rect.y;

        if(abs(i->rect.x - cenx)< 1 && abs(i->rect.y - ceny)< 1 )
            fire.erase(i--);

        for (auto j = monsters.begin(); j < monsters.end(); j++)
        {
            double tmp1x = j->get_x();
            double tmp1y = j->get_y();
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

    return;
}



void Draw::movemonsters(Shapes s,int cenx ,int ceny)
{
    // ça marche

    cenx -= weapon.width/2;
    ceny -= weapon.height/2;
<<<<<<< HEAD

    double sensitivity = 0.0002;

=======
    int res = 0;
>>>>>>> dev
    for( auto i = monsters.begin(); i< monsters.end(); i++)
    {
        //Monster m = monsters.at(i);
        res = i->move(s,cenx ,ceny,getweaponinfo());
        if(!res)
        {
<<<<<<< HEAD
            int p1= i->direction%s.points.size();
            int p2=(i->direction+1)%s.points.size();
            double mx=(s.points[p1].first+s.points[p2].first)/2 - weapon.width/2;
            double my=(s.points[p1].second+s.points[p2].second)/2 - weapon.height/2;

            i->rect.x += (sensitivity*(mx-i->rect.x));
            i->rect.y += (sensitivity*(my-i->rect.y));

            if(abs(i->rect.x - mx) < 1 && abs(i->rect.y - my)< 1 )
            {
                monsters.erase(i--);
                lifeval--;
            }
        }
    }
    // ne marche pas !!
    /*
    int iter = 0;
    for( auto i = monsters.begin(); i< monsters.end(); i++)
    {
        if(i->apper == 0 )
        {
            double h = 1/ zmonsters.at(iter);
            cenx -= weapon.width/2;
            ceny -= weapon.height/2;
            int p1= i->direction%s.points.size();
            int p2=(i->direction+1)%s.points.size();

            double mx=(s.points[p1].first+s.points[p2].first)/2 - weapon.width/2;
            double my=(s.points[p1].second+s.points[p2].second)/2 - weapon.height/2;

            double Ux = s.points.at(p2).first -  s.points.at(p1).first;
            double Uy =s.points.at(p2).second -  s.points.at(p1).second;

            double  norm= sqrt(Ux *Ux + Uy*Uy);

            Ux/=norm;
            Uy/= norm;

            double x  = (Ux*cenx - Uy*ceny) + mx  ;
            double y =  (Uy*cenx + Ux*ceny) + my;

            x*= h;
            y*= h;
            i->rect.x = x  ;
            i->rect.y = y ;
            // std::cout << "x "<< x  << '\n';
            //std::cout << "y "<< y  << '\n';

            zmonsters.at(iter++)+=0.02;

=======
            monsters.erase(i--);
            lifeval--;
>>>>>>> dev
        }

    }
    */
}


void Draw::draw_elem(int type, std::shared_ptr<SDL_Renderer> renderer,int indice)
{
    switch(type)
    {
        case TEMPEST_TITLE:
            SDL_RenderCopy(renderer.get(), tempest_title.texture.get(), NULL, &tempest_title.rect);
            break;
        case PLAYER:
            SDL_RenderCopy(renderer.get(), player.texture.get(), NULL, &player.rect);
            break;
        case RATE_URSELF:
            SDL_RenderCopy(renderer.get(), rate_urself.texture.get(), NULL, &rate_urself.rect);
            break;
        case USE_KEYS:
            SDL_RenderCopy(renderer.get(), use_keys.texture.get(), NULL, &use_keys.rect);
            break;
        case PRESS_ENTER_SELECT:
            SDL_RenderCopy(renderer.get(), select.texture.get(), NULL, &select.rect);
            break;
        case NOVICE:
            SDL_RenderCopy(renderer.get(), novice.texture.get(), NULL, &novice.rect);
            break;
        case EXPERT:
            SDL_RenderCopy(renderer.get(), expert.texture.get(), NULL, &expert.rect);
            break;
        case LEVEL:
            SDL_RenderCopy(renderer.get(), level.texture.get(), NULL, &level.rect);
            break;
        case HOLE:
            SDL_RenderCopy(renderer.get(), hole.texture.get(), NULL, &hole.rect);
            break;
        case BONUS:
            SDL_RenderCopy(renderer.get(), bonus.texture.get(), NULL, &bonus.rect);
            break;
        case TIME:
            SDL_RenderCopy(renderer.get(), timer.texture.get(), NULL, &timer.rect);
            break;
        case VECT_LEVELS:
            SDL_RenderCopy(renderer.get(), vect_level.at(indice).texture.get(), NULL, &vect_level.at(indice).rect);
            break;
        case VECT_BONUS:
            SDL_RenderCopy(renderer.get(), vect_bonus.at(indice).texture.get(), NULL, &vect_bonus.at(indice).rect);
            break;
        case WEAPON:
            SDL_RenderCopy(renderer.get(), weapon.texture.get(), NULL, &weapon.rect);
            break;
        case MONSTER:
            for(auto e: monsters)
<<<<<<< HEAD
            {
                if(!e.apper)
                    SDL_RenderCopyF(renderer.get(), e.texture.get(), NULL, &e.rect);
=======
            {   //std::cout << "monster x " << e.get_apper()<<std::endl;

                if(!e.get_apper())
                {
                    SDL_FObject monster;

                    monster = fcalculate_texture(".",RED, 2, renderer);
                    monster.rect.x= e.get_x();
                    monster.rect.y= e.get_y();
                    //std::cout << e.get_x() << "  " << e.get_y() << std::endl;
                    SDL_RenderCopyF(renderer.get(), monster.texture.get(), NULL, &monster.rect);
                    //SDL_RenderDrawPoint(renderer.get(), monster.rect.x, monster.rect.y);

                }

>>>>>>> dev
            }
            break;
        case FIRE:
            for(auto e: fire)
            {
                SDL_RenderCopyF(renderer.get(), e.texture.get(), NULL, &e.rect);
            }
            break;
        case LIFE:
            SDL_RenderCopy(renderer.get(), life.texture.get(), NULL, &life.rect);
            break;
        case SCORE:
            SDL_RenderCopy(renderer.get(), score.texture.get(), NULL, &score.rect);
            break;
        case GAME_OVER:
            SDL_RenderCopy(renderer.get(), game_over_var.texture.get(), NULL, &game_over_var.rect);
            break;
        case LEVEL_GAME:
            SDL_RenderCopy(renderer.get(), level_game.texture.get(), NULL, &level_game.rect);
            break;
    }
}


<<<<<<< HEAD
// void Draw::setscore(int score, std::shared_ptr<SDL_Renderer> renderer )
// {
//     std::string tmp =  "SCORE  "+ std::to_string(time) ;
//     timer = calculate_texture(tmp , GREEN, 1 , renderer);
//     timer.rect.x = window_width/2  - timer.width/2;
//     timer.rect.y = 17*window_height/20 - timer.height/5;
//     draw_elem (TIME, renderer,0);
// }




=======
>>>>>>> dev
void Draw::settimer(int time, std::shared_ptr<SDL_Renderer> renderer )
{
    std::string tmp =  "TIME  "+ std::to_string(time) ;
    timer = calculate_texture(tmp , GREEN, 1 , renderer);
    timer.rect.x = window_width/2  - timer.width/2;
    timer.rect.y = 17*window_height/20 - timer.height/5;
    draw_elem (TIME, renderer,0);
}

void Draw::setscore(int scorevar, std::shared_ptr<SDL_Renderer> renderer)
{
    //SDL_Object scoretmp = score;
    scoreval+=scorevar;
    std::string tmp =  ""+ std::to_string(scoreval) ;
    score = calculate_texture(tmp , GREEN, 1 , renderer);
    score.rect.x = window_width/4;
    score.rect.y = life.rect.y - 50;
    draw_elem (SCORE, renderer,0);
}

void Draw::setlevel(int level, std::shared_ptr<SDL_Renderer> renderer )
{
    std::string tmp =  std::to_string(level) ;
    level_game = calculate_texture(tmp , GREEN, 1 , renderer);
    level_game.rect.x = window_width/2;
    level_game.rect.y = window_height/10;
    draw_elem (LEVEL_GAME, renderer,0);
}

void Draw::setlife(int lifevar, std::shared_ptr<SDL_Renderer> renderer )
{
    std::string st = "";
    for (int i = 0; i < lifevar; i++) {
        st += "X";
    }

    life = calculate_texture(st , GREEN, 1 , renderer);
    life.rect.x = window_width/4;
    life.rect.y = window_height/8;
    draw_elem (LIFE, renderer,0);

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

void Draw::setmonster(Monster monster)
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
Monster Draw::getmonster(int indice)
{
    return monsters.at(indice);
}



std::pair<int, int> Draw::getweaponinfo()
{
    // SDL_FObject tmp;
    // tmp.height = weapon.height
    return std::make_pair(weapon.width/2, weapon.height/2);
}
