
#include "../headers/shapes.hpp"


// probalement on a pas besoin de construire chaque niveau
// check hershey's vector


Shapes::Shapes() :
    type{TRIANGLE}
{}

Shapes::~Shapes(){}


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

        // SDL_SetRenderDrawColor(Renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    	// //Clear the screen.
    	// SDL_RenderClear(Renderer);

    	//Setting the actual draw color.
    	SDL_SetRenderDrawColor(Renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);

    	SDL_RenderDrawLine(Renderer, centreX*0.5 ,centreY*1.75 ,centreX, centreY*0.25 );
    	SDL_RenderDrawLine(Renderer, centreX, centreY*0.25 , centreX*1.5 ,centreY*1.75);
    	SDL_RenderDrawLine(Renderer, centreX*1.5,centreY*1.75 ,centreX*0.5 ,centreY*1.75 );

        if(!points.size())
        {
            points.push_back(std::make_pair(centreX*0.5 , centreY*1.75));
            points.push_back(std::make_pair(centreX*1.5,centreY*1.75));
            points.push_back(std::make_pair(centreX, centreY*0.25 ));
        }




        SDL_RenderDrawLine(Renderer, centreX*0.95 ,centreY*1.25 ,centreX, centreY*1.2 );
    	SDL_RenderDrawLine(Renderer, centreX, centreY*1.2  , centreX*1.05 ,centreY*1.25);
    	SDL_RenderDrawLine(Renderer, centreX*1.05 ,centreY*1.25 ,centreX*0.95 ,centreY*1.25 );

        points_centre.push_back(std::make_pair(centreX*0.95 , centreY*1.25));
        points_centre.push_back(std::make_pair(centreX*1.05 ,centreY*1.25));
        points_centre.push_back(std::make_pair(centreX ,centreY*1.2));

        //
        for( size_t i = 0 ; i < points.size() ; ++i )
        {
            SDL_RenderDrawLine(Renderer, points[i].first,points[i].second ,points_centre[i].first ,points_centre[i].second );


        }
        /*#SDL_RenderDrawLine(Renderer, centreX,centreY*1.75 ,centreX ,centreY*1.25 );
        #SDL_RenderDrawLine(Renderer, centreX,centreY*1.2 ,centreX ,centreY*0.25);

        #SDL_RenderDrawLine(Renderer, centreX*0.95 ,centreY*1.25 ,centreX*0.5 ,centreY*1.75 );
        #SDL_RenderDrawLine(Renderer, centreX*1.05 , centreY*1.25 ,centreX*1.5 ,centreY*1.75);*/


}

void Shapes::DrawRectangle(SDL_Renderer * Renderer, int32_t centreX, int32_t centreY)
{

        	SDL_SetRenderDrawColor(Renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);

        	// SDL_RenderDrawLine(Renderer, centreX*0.5 ,centreY*1.75 ,centreX, centreY*0.25 );
        	// SDL_RenderDrawLine(Renderer, centreX, centreY*0.25 , centreX*1.5 ,centreY*1.75);
        	// SDL_RenderDrawLine(Renderer, centreX*1.5,centreY*1.75 ,centreX*0.5 ,centreY*1.75 );

            SDL_Rect rec = {int(centreX*0.5) ,int(centreY*0.5),centreX,centreY};
            SDL_RenderDrawRect(Renderer, &rec);

            if(!points.size())
            {
                points.push_back(std::make_pair(centreX*0.5 , centreY*1.5));
                points.push_back(std::make_pair(centreX*1.5 , centreY*1.5));
                points.push_back(std::make_pair(centreX*1.5,centreY*0.5));
                points.push_back(std::make_pair(centreX*0.5, centreY*0.5 ));
            }

            int lenx = centreX/10;
            int leny = centreY/10;

            SDL_Rect rec2 = {int(centreX*0.95) ,int(centreY*0.95),lenx,leny};
            SDL_RenderDrawRect(Renderer, &rec2);

            if(!points_centre.size())
            {
                points_centre.push_back(std::make_pair(centreX*0.95 , centreY*0.95+leny ));
                points_centre.push_back(std::make_pair(centreX*0.95+lenx , centreY*0.95+leny));
                points_centre.push_back(std::make_pair(centreX*0.95+lenx ,centreY*0.95));
                points_centre.push_back(std::make_pair(centreX*0.95 ,centreY*0.95));

            }
            for( size_t i = 0 ; i < points.size() ; ++i )
            {
                SDL_RenderDrawLine(Renderer, points[i].first,points[i].second ,points_centre[i].first ,points_centre[i].second );
            }
}




void Shapes::Drawshape(SDL_Renderer *renderer, int32_t window_width,int32_t window_height, int32_t level)
{
    switch (level) {
        case 1:
            DrawTriangle(renderer , window_width/2,window_height/2);
            break;
        case 2:
            DrawRectangle(renderer , window_width/2,window_height/2);
            break;
    }
}



// crée grille
// créer weapons
// monster
