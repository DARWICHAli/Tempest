
#include "../headers/shapes.hpp"


// probalement on a pas besoin de construire chaque niveau
// check hershey's vector


Shapes::Shapes() :
    type{TRIANGLE}
{}


void Shapes::colorcol(std::shared_ptr<SDL_Renderer> Renderer,std::pair<int, int> pair,int color)
{
    int index = pair.first;
    int index2 = pair.second;
    color = 1;
    // to init r b g
    switch (color) {
        case 1:
        break;

    }
    SDL_SetRenderDrawColor(Renderer.get(), 0, 255, 0, SDL_ALPHA_OPAQUE);

    SDL_RenderDrawLine(Renderer.get(), points[index].first,points[index].second ,points_centre[index].first ,points_centre[index].second );
    SDL_RenderDrawLine(Renderer.get(), points[index2].first,points[index2].second ,points_centre[index2].first ,points_centre[index2].second );


}





void Shapes::clearlevelShape()
{
    points.clear();
    points_centre.clear();
    return;
}

Shapes::~Shapes(){}


std::pair<int, int> Shapes::getcoordcentre()
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < points.size(); i++)
    {
        x+= points_centre.at(i).first;
        y+= points_centre.at(i).second;
    }
    x/=points_centre.size();//moyenne
    y/=points_centre.size();

    return std::make_pair(x , y);
}


/*
centrer les points du shape vers un point
ne marche pas
*/
void Shapes::center(int s_x,int s_y)
{
    int dist =0;
    int dist2=0;
    int x =0;
    int y =0;
    for (int i = 0; i < points.size(); i++)
    {
        x+= points.at(i).first;
        y+= points.at(i).second;
    }
    x/=points.size();//moyenne
    y/=points.size();

    dist = abs(x -s_x);
    dist2 = abs(y-s_y);
    for (int i = 0; i < points.size(); i++)
    {
        // centrer
        if(s_x >x )
            points.at(i).first = points.at(i).first +dist;
        else
            points.at(i).first = points.at(i).first -dist;
        if(s_y > y )
            points.at(i).second = points.at(i).second+dist2;
        else
            points.at(i).second = points.at(i).second-dist2;

    }
}


void Shapes::center_reduce(int window_width,int window_height)
{
    int centerx = window_width/2;
    int centery = window_height/2;

    int dist =0;
    int dist2=0;
    int x =0;
    int y =0;

    //reduce
    for (int i = 0; i < points.size(); i++)
    {
        x+= points.at(i).first*SCALE_VAL;
        y+= points.at(i).second*SCALE_VAL;
    }
    x/=points.size();//moyenne
    y/=points.size();
    dist2 = abs(y-centery);
    dist = abs(x -centerx);
    //dist-=dist2;
    for (int i = 0; i < points.size(); i++)
    {
        // reduire centrer
        points_centre.push_back(std::make_pair((points.at(i).first*SCALE_VAL)+(dist), (points.at(i).second*SCALE_VAL)+(dist2)));

    }

}


void Shapes::Display(std::shared_ptr<SDL_Renderer> Renderer, int color, int cycl)
{
    int r,g,b;
    // r= 0;
    // b = 0;
    // g = 255;
    switch (color) {
        case 1://bleu
            r= 0;
            g = 0;
            b = 255;
            break;
        case 2://red
            r= 255;
            g = 0;
            b = 0;
            break;
        case 3://yellow
            r= 255;
            g = 255;
            b = 0;
            break;
        case 4://cyan
            r= 0;
            g = 255;
            b = 255;
            break;
        case 5://black invisible
            r= 0;
            g = 0;
            b = 0;
            break;
        case 6://green
            r= 0;
            g = 255;
            b = 0;
            break;

    }

    SDL_SetRenderDrawColor(Renderer.get(), r, g, b, SDL_ALPHA_OPAQUE);
    for (int i = 0; i < points.size(); i++)
    {
        if(!cycl)
        {
            if(i != points.size()-1)
            {
                SDL_RenderDrawLine(Renderer.get(), points.at(i).first , points.at(i).second ,points.at((i+1)%points.size()).first , points.at((i+1)%points.size()).second );
                SDL_RenderDrawLine(Renderer.get(), points_centre.at(i).first , points_centre.at(i).second ,points_centre.at((i+1)%points_centre.size()).first , points_centre.at((i+1)%points_centre.size()).second );
            }
        }
        else
        {
            SDL_RenderDrawLine(Renderer.get(), points.at(i).first , points.at(i).second ,points.at((i+1)%points.size()).first , points.at((i+1)%points.size()).second );
            SDL_RenderDrawLine(Renderer.get(), points_centre.at(i).first , points_centre.at(i).second ,points_centre.at((i+1)%points_centre.size()).first , points_centre.at((i+1)%points_centre.size()).second );

        }
        SDL_RenderDrawLine(Renderer.get(), points[i].first,points[i].second ,points_centre[i].first ,points_centre[i].second );

    }
}


void Shapes::drawweapon(std::shared_ptr<SDL_Renderer> renderer,int level,std::pair<int, int> weapon)
{
    int r,g,b;
    if(level <= 15)
    {
        r = 255;
        g = 255;
        b = 0;
    }
    else if(level >= 16 && level <= 31)
    {
        r = 0;
        g = 255;
        b = 0;
    }
    else if(level >= 32 && level <= 47)
    {
        r = 0;
        g = 0;
        b = 255;
    }
    else if(level >= 48 && level <= 63)
    {
        r = 0;
        g = 0;
        b = 255;
    }
    else if(level >= 64 && level <= 79)
    {
        r = 255;
        g = 255;
        b = 0;
    }
    else if(level >= 80 && level <= 96)
    {
        r = 255;
        g = 0;
        b = 0;
    }

    level = 5;
    if(!points.size())
    {
        switch (level) {
            case 5:
            {
                points.push_back(std::make_pair(100 , 100));
                points.push_back(std::make_pair(150 , 100));
                points.push_back(std::make_pair(100 , 150));
                points.push_back(std::make_pair(150 , 150));
                center(weapon.first,weapon.second);
                break;
            }
        }
    }
    center(weapon.first,weapon.second);
    SDL_SetRenderDrawColor(renderer.get(), r, g, b, SDL_ALPHA_OPAQUE);
    for (int i = 0; i < points.size(); i++)
    {
        SDL_RenderDrawLine(renderer.get(), points.at(i).first , points.at(i).second ,points.at((i+1)%points.size()).first , points.at((i+1)%points.size()).second );
    }

    return;
}



void Shapes::DrawCircle(std::shared_ptr<SDL_Renderer> renderer, int32_t centreX, int32_t centreY,int color)
{
    if(!points.size())
    {
        points.push_back(std::make_pair(centreX*0.25, centreY*0.25));
        points.push_back(std::make_pair(centreX*0.5, centreY*0.125));
        points.push_back(std::make_pair(centreX*0.75, centreY*0.25));
        points.push_back(std::make_pair(centreX*0.875, centreY*0.5));
        points.push_back(std::make_pair(centreX*0.75, centreY*0.75));
        points.push_back(std::make_pair(centreX*0.5, centreY*0.875));
        points.push_back(std::make_pair(centreX*0.25, centreY*0.75));
        points.push_back(std::make_pair(centreX*0.125, centreY*0.5));

        center_reduce(centreX ,centreY);

    }
    Display(renderer, color, 1);
}


void Shapes::DrawTriangle(std::shared_ptr<SDL_Renderer> Renderer, int32_t centreX, int32_t centreY,int color)
{
        if(!points.size())
        {
            points.push_back(std::make_pair(centreX*0.5 , centreY*1.75));
            points.push_back(std::make_pair(centreX*1.5,centreY*1.75));
            points.push_back(std::make_pair(centreX, centreY*0.25 ));
            center_reduce(centreX*2 ,centreY*2);

        }
        Display(Renderer, color, 1);


}


void Shapes::DrawRectangle(std::shared_ptr<SDL_Renderer> Renderer, int32_t centreX, int32_t centreY,int color)
{

    if(!points.size())
    {
        points.push_back(std::make_pair(centreX*0.25 , centreY*.75));
        points.push_back(std::make_pair(centreX*0.75 , centreY*0.75));
        points.push_back(std::make_pair(centreX*0.75,centreY*0.25));
        points.push_back(std::make_pair(centreX*0.25, centreY*0.25));
        center_reduce(centreX,centreY);
        // points_centre.push_back(std::make_pair(375, 425));
        // points_centre.push_back(std::make_pair(425, 425));
        // points_centre.push_back(std::make_pair(425, 375));
        // points_centre.push_back(std::make_pair(375, 375));

    }
    Display(Renderer, color, 1);



}

void Shapes::DrawPlus(std::shared_ptr<SDL_Renderer>renderer, int32_t window_width, int32_t window_height,int color)
{



    /*
        ___0.25
     __|   |___ 0.25
    |___    ___| 0.25
       |___|0.25
         0.25
    */

    if(!points.size())
    {
        points.push_back(std::make_pair( window_width*0.375, window_height*0.875));
        points.push_back(std::make_pair(window_width*0.625, window_height*0.875 ));
        points.push_back(std::make_pair(window_width*0.625, window_height*0.75));
        points.push_back(std::make_pair(window_width*0.75, window_height*0.75));
        points.push_back(std::make_pair(window_width*0.75, window_height*0.42 ));
        points.push_back(std::make_pair(window_width*0.625, window_height*0.42));
        points.push_back(std::make_pair(window_width*0.625, window_height*0.295));
        points.push_back(std::make_pair(window_width*0.375, window_height*0.295));
        points.push_back(std::make_pair(window_width*0.375, window_height*0.42));
        points.push_back(std::make_pair(window_width*0.25, window_height*0.42 ));
        points.push_back(std::make_pair(window_width*0.25, window_height*0.75));
        points.push_back(std::make_pair(window_width*0.375, window_height*0.75 ));

        //center(window_width,window_height);
        center_reduce(window_width ,window_height);

    }
    Display(renderer, 1, 1);

}




void Shapes::DrawBowtie(std::shared_ptr<SDL_Renderer>renderer, int32_t window_width, int32_t window_height,int color)
{
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.1875,window_height* 0.1875));
        points.push_back(std::make_pair(window_width*0.5,window_height* 0.25));
        points.push_back(std::make_pair(window_width*0.8125,window_height* 0.1875));
        points.push_back(std::make_pair(window_width*0.75,window_height* 0.5));
        points.push_back(std::make_pair(window_width*0.8125,window_height* 0.8125));
        points.push_back(std::make_pair(window_width*0.5,window_height* 0.75));
        points.push_back(std::make_pair(window_width*0.1875,window_height* 0.8125));
        points.push_back(std::make_pair(window_width*0.25,window_height* 0.5));

        center_reduce(window_width ,window_height);
    }
    Display(renderer, color, 1);

    return;
}

void Shapes::DrawStylizedCross(std::shared_ptr<SDL_Renderer>renderer, int32_t window_width, int32_t window_height ,int color){
    if(!points.size())
    {


        points.push_back(std::make_pair(window_width*0.4375,window_height*0.25));
        points.push_back(std::make_pair(window_width*0.5625,window_height*0.25));
        points.push_back(std::make_pair(window_width*0.59375,window_height*0.28125));

        points.push_back(std::make_pair(window_width*0.65625,window_height*0.375));
        points.push_back(std::make_pair(window_width*0.71875,window_height*0.39375));
        points.push_back(std::make_pair(window_width*0.71875,window_height*0.45625));
        points.push_back(std::make_pair(window_width*0.65625,window_height*0.475));

        points.push_back(std::make_pair(window_width*0.59375,window_height*0.5375));
        points.push_back(std::make_pair(window_width*0.5625,window_height*0.6));
        points.push_back(std::make_pair(window_width*0.4375,window_height*0.6));

        points.push_back(std::make_pair(window_width*0.15625,window_height*0.5375));
        points.push_back(std::make_pair(window_width*0.21875,window_height*0.475));
        points.push_back(std::make_pair(window_width*0.28125,window_height*0.45625));
        points.push_back(std::make_pair(window_width*0.28125,window_height*0.39375));
        points.push_back(std::make_pair(window_width*0.34375,window_height*0.375));
        points.push_back(std::make_pair(window_width*0.40625,window_height*0.3125));



        center_reduce(window_width,window_height);
    }
    Display(renderer, color, 1);

}
void Shapes::DrawClover(std::shared_ptr<SDL_Renderer>renderer, int32_t window_width, int32_t window_height,int color )
{
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.85,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.8,window_height*0.4));
        center_reduce(window_width ,window_height);
    }
    Display(renderer, color, 1);




}
void Shapes::DrawV(std::shared_ptr<SDL_Renderer>renderer, int32_t window_width, int32_t window_height,int color)
{
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.45,window_height*0.4));
        points.push_back(std::make_pair(window_width*0.25,window_height*0.25));
        points.push_back(std::make_pair(window_width*0.45,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.55,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.75,window_height*0.25));
        points.push_back(std::make_pair(window_width*0.55,window_height*0.4));


        //center(window_width,window_height);
        center_reduce(window_width ,window_height);

    }
    Display(renderer, color, 0);

}
void Shapes::DrawSteps(std::shared_ptr<SDL_Renderer>renderer, int32_t window_width, int32_t window_height,int color)
{
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.28125,window_height*0.625));
        points.push_back(std::make_pair(window_width*0.28125,window_height*0.6875));
        points.push_back(std::make_pair(window_width*0.34375,window_height*0.6875));
        points.push_back(std::make_pair(window_width*0.34375,window_height*0.75));
        points.push_back(std::make_pair(window_width*0.40625,window_height*0.75));
        points.push_back(std::make_pair(window_width*0.40625,window_height*0.8125));
        points.push_back(std::make_pair(window_width*0.46875,window_height*0.8125));
        points.push_back(std::make_pair(window_width*0.46875,window_height*0.875));
        points.push_back(std::make_pair(window_width*0.53125,window_height*0.875));
        points.push_back(std::make_pair(window_width*0.53125,window_height*0.8125));
        points.push_back(std::make_pair(window_width*0.59375,window_height*0.8125));
        points.push_back(std::make_pair(window_width*0.59375,window_height*0.75));
        points.push_back(std::make_pair(window_width*0.65625,window_height*0.75));
        points.push_back(std::make_pair(window_width*0.65625,window_height*0.6875));
        points.push_back(std::make_pair(window_width*0.71875,window_height*0.6875));
        points.push_back(std::make_pair(window_width*0.71875,window_height*0.625));



        center_reduce(window_width ,window_height);
    }
    Display(renderer, color, 0);

}
void Shapes::DrawU(std::shared_ptr<SDL_Renderer>renderer, int32_t window_width, int32_t window_height,int color )
{
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.8,window_height*0.35));
        points.push_back(std::make_pair(window_width*0.8,window_height*0.4));
        points.push_back(std::make_pair(window_width*0.8,window_height*0.45));
        points.push_back(std::make_pair(window_width*0.8,window_height*0.5));
        points.push_back(std::make_pair(window_width*0.78,window_height*0.55));
        points.push_back(std::make_pair(window_width*0.7,window_height*0.6));
        points.push_back(std::make_pair(window_width*0.65,window_height*0.65));
        points.push_back(std::make_pair(window_width*0.55,window_height*0.7));
        points.push_back(std::make_pair(window_width*0.45,window_height*0.7));
        points.push_back(std::make_pair(window_width*0.45,window_height*0.65));
        points.push_back(std::make_pair(window_width*0.3,window_height*0.6));
        points.push_back(std::make_pair(window_width*0.22,window_height*0.55));
        points.push_back(std::make_pair(window_width*0.2,window_height*0.5));
        points.push_back(std::make_pair(window_width*0.2,window_height*0.45));
        points.push_back(std::make_pair(window_width*0.2,window_height*0.4));
        points.push_back(std::make_pair(window_width*0.2,window_height*0.35));


        //center(window_width,window_height);
        center_reduce(window_width ,window_height);

    }
    Display(renderer, color, 0);

}
void Shapes::DrawCompFlat(std::shared_ptr<SDL_Renderer>renderer, int32_t window_width, int32_t window_height  ,int color)
{
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.35,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.4,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.45,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.5,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.55,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.65,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.75,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.85,window_height*0.8));

        //center(window_width,window_height);
        center_reduce(window_width ,window_height);

    }
    Display(renderer, color, 0);

}
void Shapes::DrawHeart(std::shared_ptr<SDL_Renderer>renderer, int32_t window_width, int32_t window_height ,int color){
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.85,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.8,window_height*0.4));
        center_reduce(window_width ,window_height);
    }
    Display(renderer, color, 1);

}
void Shapes::DrawStar(std::shared_ptr<SDL_Renderer>renderer, int32_t window_width, int32_t window_height,int color ){
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.85,window_height*0.8));

        points.push_back(std::make_pair(window_width*0.8,window_height*0.4));
        center_reduce(window_width ,window_height);
    }
    Display(renderer, color, 1);

}
void Shapes::DrawW(std::shared_ptr<SDL_Renderer>renderer, int32_t window_width, int32_t window_height,int color){
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.125,window_height*0.25));
        points.push_back(std::make_pair(window_width*0.15625,window_height*0.375));
        points.push_back(std::make_pair(window_width*0.15625,window_height*0.5));
        points.push_back(std::make_pair(window_width*0.1875,window_height*0.625));

        points.push_back(std::make_pair(window_width*0.25,window_height*0.6875));
        points.push_back(std::make_pair(window_width*0.3125,window_height*0.6875));
        points.push_back(std::make_pair(window_width*0.375,window_height*0.625));
        points.push_back(std::make_pair(window_width*0.4375,window_height*0.5625));

        points.push_back(std::make_pair(window_width*0.5625,window_height*0.5625));
        points.push_back(std::make_pair(window_width*0.625,window_height*0.625));
        points.push_back(std::make_pair(window_width*0.6875,window_height*0.6875));
        points.push_back(std::make_pair(window_width*0.75,window_height*0.6875));

        points.push_back(std::make_pair(window_width*0.8125,window_height*0.625));
        points.push_back(std::make_pair(window_width*0.84375,window_height*0.5));
        points.push_back(std::make_pair(window_width*0.84375,window_height*0.375));
        points.push_back(std::make_pair(window_width*0.875,window_height*0.25));



        center_reduce(window_width ,window_height);
    }
    Display(renderer, color, 0);

}
void Shapes::DrawFan(std::shared_ptr<SDL_Renderer>renderer, int32_t window_width, int32_t window_height ,int color){
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.85,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.8,window_height*0.4));
        center_reduce(window_width ,window_height);
    }
    Display(renderer, color, 0);

}
void Shapes::DrawInfSym(std::shared_ptr<SDL_Renderer>renderer, int32_t window_width, int32_t window_height ,int color)
{
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.125, window_height*0.5));
        points.push_back(std::make_pair(window_width*0.25, window_height*0.375));
        points.push_back(std::make_pair(window_width*0.3125,window_height* 0.3125));
        points.push_back(std::make_pair(window_width*0.475, window_height*0.375));
        points.push_back(std::make_pair(window_width*0.525, window_height*0.375));
        points.push_back(std::make_pair(window_width*0.6875, window_height*0.3125));
        points.push_back(std::make_pair(window_width*0.75, window_height*0.375));
        points.push_back(std::make_pair(window_width*0.875, window_height*0.5));
        points.push_back(std::make_pair(window_width*0.75, window_height*0.625));
        points.push_back(std::make_pair(window_width*0.6875, window_height*0.6875));
        points.push_back(std::make_pair(window_width*0.525,window_height* 0.625));
        points.push_back(std::make_pair(window_width*0.475, window_height*0.625));
        points.push_back(std::make_pair(window_width*0.3125,window_height* 0.6875));
        points.push_back(std::make_pair(window_width*0.25,window_height* 0.625));

        center_reduce(window_width ,window_height);
    }
    Display(renderer, color, 1);
}

void Shapes::Drawshape(std::shared_ptr<SDL_Renderer>renderer, int32_t window_width,int32_t window_height, int32_t level)
{

    int color = 0;
    if(level <= 15)
    {
        color = 1;//blue
    }
    else if(level >= 16 && level <= 31)
    {
        color = 2; //red
    }
    else if(level >= 32 && level <= 47)
    {
        color = 3; //yellow
    }
    else if(level >= 48 && level <= 63)
    {
        color = 4; //cayan
    }
    else if(level >= 64 && level <= 79)
    {
        color = 5; //black (invisible)
    }
    else if(level >= 80 && level <= 96)
    {
        color = 6; //green
    }




    switch (level%16) {
        case 0:
            DrawCircle(renderer , window_width , window_height,color);
            break;//circle
        case 1:
            DrawRectangle(renderer , window_width , window_height,color);
            break;
        case 2:
            DrawPlus(renderer,window_width,window_height,color);
            break;
        case 3:
            DrawBowtie(renderer,window_width,window_height,color);
            break;
        case 4 :
            DrawStylizedCross(renderer,window_width,window_height,color);
            break;
        case 5 :
            DrawTriangle(renderer , window_width/2,window_height/2,color);
            break;
        case 6 :
            //DrawClover(renderer , window_width/2,window_height/2,color);
            //break;
            level++;
        case 7 :
            DrawV(renderer , window_width,window_height,color);
            break;
        case 8 :
            DrawSteps(renderer , window_width,window_height,color);
            break;
        case 9 :
            DrawU(renderer , window_width,window_height,color);
            break;
        case 10:
            //DrawCompFlat(renderer , window_width,window_height,color);
            //break;
            level++;
        case 11:
            //DrawHeart(renderer , window_width/2,window_height/2,color);
            //break;
            level++;
        case 12:
            // DrawStar(renderer , window_width/2,window_height/2,color);
            // break;
            level++;
        case 13:
            DrawW(renderer , window_width,window_height,color);
            break;
        case 14:
            // DrawFan(renderer , window_width/2,window_height/2,color);
            // break;
            level++;
        case 15:
            DrawInfSym(renderer , window_width,window_height,color);
            break;

    }
}
