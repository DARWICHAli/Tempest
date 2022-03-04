#include "../headers/weapon.hpp"




Weapon::Weapon (){}
Weapon::~Weapon (){}


void Weapon::DrawWeapon(SDL_Renderer * Renderer, int32_t centreX, int32_t centreY)
{
    // couleurs changes avec le niveau
    // rect pour le moment
    // 
    SDL_SetRenderDrawColor(Renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(Renderer, centreX-25 ,centreY-25 , centreX-25, centreY+25 );
    SDL_RenderDrawLine(Renderer, centreX-25, centreY+25 , centreX+25 ,centreY+25);
    SDL_RenderDrawLine(Renderer, centreX+25 ,centreY+25 , centreX+25 ,centreY-25 );
    SDL_RenderDrawLine(Renderer, centreX+25 ,centreY-25 , centreX-25 ,centreY-25 );
    SDL_RenderPresent(Renderer);


    //SDL_RenderPresent(renderer);
    SDL_RenderClear(Renderer);


}
