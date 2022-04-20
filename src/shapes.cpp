
#include "../headers/shapes.hpp"


// probalement on a pas besoin de construire chaque niveau
// check hershey's vector


Shapes::Shapes() :
    type{TRIANGLE}
{}

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


void Shapes::Display(SDL_Renderer * Renderer, int color, int cycl)
{
    int r,b,g;
    r= 0;
    b = 0;
    g = 255;

    SDL_SetRenderDrawColor(Renderer, r, b, g, SDL_ALPHA_OPAQUE);
    for (int i = 0; i < points.size(); i++)
    {
        if(!cycl)
        {
            if(i != points.size()-2)
            {
                SDL_RenderDrawLine(Renderer, points.at(i).first , points.at(i).second ,points.at((i+1)%points.size()).first , points.at((i+1)%points.size()).second );
                SDL_RenderDrawLine(Renderer, points_centre.at(i).first , points_centre.at(i).second ,points_centre.at((i+1)%points_centre.size()).first , points_centre.at((i+1)%points_centre.size()).second );
            }
        }
        else
        {
            SDL_RenderDrawLine(Renderer, points.at(i).first , points.at(i).second ,points.at((i+1)%points.size()).first , points.at((i+1)%points.size()).second );
            SDL_RenderDrawLine(Renderer, points_centre.at(i).first , points_centre.at(i).second ,points_centre.at((i+1)%points_centre.size()).first , points_centre.at((i+1)%points_centre.size()).second );

        }
        SDL_RenderDrawLine(Renderer, points[i].first,points[i].second ,points_centre[i].first ,points_centre[i].second );

    }
}


void Shapes::drawweapon(SDL_Renderer * renderer,int level,std::pair<int, int> weapon)
{
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
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);
    for (int i = 0; i < points.size(); i++)
    {
        SDL_RenderDrawLine(renderer, points.at(i).first , points.at(i).second ,points.at((i+1)%points.size()).first , points.at((i+1)%points.size()).second );
    }

}



void Shapes::DrawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y)
    {

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}


void Shapes::DrawTriangle(SDL_Renderer * Renderer, int32_t centreX, int32_t centreY)
{
        if(!points.size())
        {
            points.push_back(std::make_pair(centreX*0.5 , centreY*1.75));
            points.push_back(std::make_pair(centreX*1.5,centreY*1.75));
            points.push_back(std::make_pair(centreX, centreY*0.25 ));
            center_reduce(centreX*2 ,centreY*2);

        }
        Display(Renderer, 1, 1);


}


void Shapes::DrawRectangle(SDL_Renderer * Renderer, int32_t centreX, int32_t centreY)
{

    if(!points.size())
    {
        points.push_back(std::make_pair(centreX*0.25 , centreY*.75));
        points.push_back(std::make_pair(centreX*0.75 , centreY*0.75));
        points.push_back(std::make_pair(centreX*0.75,centreY*0.25));
        points.push_back(std::make_pair(centreX*0.25, centreY*0.25));
        //center_reduce(centreX,centreY);
        points_centre.push_back(std::make_pair(375, 425));
        points_centre.push_back(std::make_pair(425, 425));
        points_centre.push_back(std::make_pair(425, 375));
        points_centre.push_back(std::make_pair(375, 375));

    }
    Display(Renderer, 1, 1);



}

void Shapes::DrawPlus(SDL_Renderer *renderer, int32_t window_width, int32_t window_height)
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




void Shapes::DrawBowtie(SDL_Renderer *renderer, int32_t window_width, int32_t window_height)
{
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.85,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.8,window_height*0.4));
        center_reduce(window_width ,window_height);
    }
    Display(renderer, 1, 1);

    return;
}
void Shapes::DrawStylizedCross(SDL_Renderer *renderer, int32_t window_width, int32_t window_height ){
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.85,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.8,window_height*0.4));
        center_reduce(window_width ,window_height);
    }
    Display(renderer, 1, 1);

}
void Shapes::DrawClover(SDL_Renderer *renderer, int32_t window_width, int32_t window_height )
{
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.85,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.8,window_height*0.4));
        center_reduce(window_width ,window_height);
    }
    Display(renderer, 1, 1);




}
void Shapes::DrawV(SDL_Renderer *renderer, int32_t window_width, int32_t window_height)
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
    Display(renderer, 1, 0);

}
void Shapes::DrawSteps(SDL_Renderer *renderer, int32_t window_width, int32_t window_height)
{
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.85,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.8,window_height*0.4));
        center_reduce(window_width ,window_height);
    }
    Display(renderer, 1, 0);

}
void Shapes::DrawU(SDL_Renderer *renderer, int32_t window_width, int32_t window_height )
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
    Display(renderer, 1, 0);

}
void Shapes::DrawCompFlat(SDL_Renderer *renderer, int32_t window_width, int32_t window_height  )
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
    Display(renderer, 1, 0);

}
void Shapes::DrawHeart(SDL_Renderer *renderer, int32_t window_width, int32_t window_height ){
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.85,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.8,window_height*0.4));
        center_reduce(window_width ,window_height);
    }
    Display(renderer, 1, 1);

}
void Shapes::DrawStar(SDL_Renderer *renderer, int32_t window_width, int32_t window_height ){
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.85,window_height*0.8));

        points.push_back(std::make_pair(window_width*0.8,window_height*0.4));
        center_reduce(window_width ,window_height);
    }
    Display(renderer, 1, 1);

}
void Shapes::DrawW(SDL_Renderer *renderer, int32_t window_width, int32_t window_height){
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.85,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.8,window_height*0.4));
        center_reduce(window_width ,window_height);
    }
    Display(renderer, 1, 0);

}
void Shapes::DrawFan(SDL_Renderer *renderer, int32_t window_width, int32_t window_height ){
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.85,window_height*0.8));
        points.push_back(std::make_pair(window_width*0.8,window_height*0.4));
        center_reduce(window_width ,window_height);
    }
}
void Shapes::DrawInfSym(SDL_Renderer *renderer, int32_t window_width, int32_t window_height ){
    if(!points.size())
    {
        points.push_back(std::make_pair(window_width*0.8,window_height*0.4));
        center_reduce(window_width ,window_height);
    }
}

void Shapes::Drawshape(SDL_Renderer *renderer, int32_t window_width,int32_t window_height, int32_t level)
{
    switch (level) {
        case 0:
            break;//circle
        case 1:
            DrawRectangle(renderer , window_width , window_height);
            break;
        case 2:
            DrawPlus(renderer,window_width,window_height);
            break;
        case 3:
            DrawBowtie(renderer,window_width,window_height);
            break;
        case 4 :
            DrawStylizedCross(renderer,window_width/2,window_height/2);
            break;
        case 5 :
            DrawTriangle(renderer , window_width/2,window_height/2);
            break;
        case 6 :
            DrawClover(renderer , window_width/2,window_height/2);
            break;
        case 7 :
            DrawV(renderer , window_width,window_height);
            break;
        case 8 :
            DrawSteps(renderer , window_width/2,window_height/2);
            break;
        case 9 :
            DrawU(renderer , window_width,window_height);
            break;
        case 10:
            DrawCompFlat(renderer , window_width,window_height);
            break;
        case 11:
            DrawHeart(renderer , window_width/2,window_height/2);
            break;
        case 12:
            DrawStar(renderer , window_width/2,window_height/2);
            break;
        case 13:
            DrawW(renderer , window_width/2,window_height/2);
            break;
        case 14:
            DrawFan(renderer , window_width/2,window_height/2);
            break;
        case 15:
            DrawInfSym(renderer , window_width/2,window_height/2);
            break;

    }
}
