#include "../headers/Draw.hpp"
#include "../headers/Defs.hpp"
#include <cassert>
Draw::Draw()
{
    last_x =0;
    last_y =0;
    font_menu = TTF_OpenFont("ressources/fonts/Hursheys.ttf", 200);
    font_score = TTF_OpenFont("ressources/fonts/Hursheys.ttf", 100);

    if (font_menu == NULL)
      std::cout << "je marche pas" << std::endl;

    window_width = 0;
    window_height = 0;
}

void Draw::draw(int last_x,int last_y)
{
    Uint8 color[4] = {255,0,0,255};
    SDL_Window* window = SDL_CreateWindow("Test_SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600,
    						  SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI);
    	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    	assert (renderer != NULL);

    	bool quit = false;
    	while (!quit)
    	{
    		SDL_Event event;
    		while (!quit && SDL_PollEvent(&event))
    		{
    			switch (event.type)
    			{
    			case SDL_QUIT:
    				quit = true;
    				break;
    			}
    		}

            const Uint8* state = SDL_GetKeyboardState(NULL);
        	if (state[SDL_SCANCODE_SPACE])
        	{
        		SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        		SDL_RenderClear(renderer);
        	}
        	int x,y;
        	if ( SDL_GetMouseState(&x,&y) & SDL_BUTTON(SDL_BUTTON_LEFT) )
        	{
        		const Uint8* state = SDL_GetKeyboardState(NULL);
        		SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
        		if (state[SDL_SCANCODE_RSHIFT])
        		{
        			SDL_RenderDrawLine(renderer, last_x,last_y,x,y);
        		}
        		else
        		{
        			SDL_RenderDrawPoint(renderer, x, y);
        		}
        		last_x = x;
        		last_y = y;
        	}

    		SDL_RenderPresent(renderer);
    	}

}


SDL_Object Draw::calculate_texture(std::string text,SDL_Color color,int type, SDL_Renderer* renderer)
{
  TTF_Font* font;
  switch (type) {
    case 0:
      font=font_menu;
      break;
    case 1:
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
    tempest_title = calculate_texture("Tempest", RED, 0, renderer);
    solo_mode = calculate_texture("Mode Solo", GREEN, 1, renderer);
    vs_IA = calculate_texture("Solo vs IA", BLUE, 1, renderer);
    leave = calculate_texture("Sortir", PINK, 1, renderer);

    int tempest_titleX = window_width/2 - tempest_title.width/2;
    int tempest_titleY = window_height/10 - tempest_title.height/10;
    int solo_modeX = window_width/2 - solo_mode.width/2;
    int solo_modeY = (window_height/3  - solo_mode.height/3)+ tempest_titleY ;
    int vs_IAY = solo_modeY + window_width/14; // ( SCREEN_HEIGHT/2 + 150) - tempHeight/2;
    int vs_IAX = window_width/2  - vs_IA.width/2;
    int leaveX = window_width/2  - leave.width/2;;
    int leaveY = vs_IAY + window_width/7;

    tempest_title.rect.x = tempest_titleX;
    tempest_title.rect.y = tempest_titleY;
    solo_mode.rect.x = solo_modeX;
    solo_mode.rect.y = solo_modeY;
    vs_IA.rect.x = vs_IAX;
    vs_IA.rect.y = vs_IAY;
    leave.rect.x = leaveX;
    leave.rect.y = leaveY;
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
    draw_elem (SOLO_MODE, renderer);
    draw_elem (VS_IA, renderer);
    draw_elem (LEAVE, renderer);
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
                if ( (events.button.x > solo_mode.rect.x && events.button.x < solo_mode.rect.x + solo_mode.width)
                && (events.button.y > solo_mode.rect.y && events.button.y < solo_mode.rect.y + solo_mode.height) )
                {
                    SDL_Log("Mode Solo");
                    running = 1;
                }
                else if ( (events.button.x > vs_IA.rect.x && events.button.x < vs_IA.rect.x + vs_IA.width )
                && (events.button.y > vs_IA.rect.y && events.button.y < vs_IA.rect.y + vs_IA.height ) )
                {
                    SDL_Log("Solo vs IA");
                    running = 2;
                }
                else if ( (events.button.x > leave.rect.x && events.button.x < leave.rect.x + leave.width )
                && (events.button.y > leave.rect.y && events.button.y < leave.rect.y + leave.height) )
                {
                    SDL_Log("Sortir");
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
      /*
    case SCORE:
      SDL_RenderCopy(renderer, score.texture, NULL, &score.rect);
      break;
    case SCORE_NUM:
      SDL_RenderCopy(renderer, score_num.texture, NULL, &score_num.rect);
      break;
    case LEVEL:
      SDL_RenderCopy(renderer, level.texture, NULL, &level.rect);
      break;
    case LEVEL_NUM:
      SDL_RenderCopy(renderer, level_num.texture, NULL, &level_num.rect);
      break;
    case LOOSE:
      SDL_RenderCopy(renderer, game_over.texture, NULL, &game_over.rect);
      break;
    case BACK_MENU:
      SDL_RenderCopy(renderer, back_menu.texture, NULL, &back_menu.rect);
      break;
      */
    case LEAVE:
      SDL_RenderCopy(renderer, leave.texture, NULL, &leave.rect);
      break;
    case TEMPEST_TITLE:
      SDL_RenderCopy(renderer, tempest_title.texture, NULL, &tempest_title.rect);
      break;
    case SOLO_MODE:
      SDL_RenderCopy(renderer, solo_mode.texture, NULL, &solo_mode.rect);
      break;
    case VS_IA:
      SDL_RenderCopy(renderer, vs_IA.texture, NULL, &vs_IA.rect);
      break;
/*    case SCORE_GO:
      SDL_RenderCopy(renderer, score_GO.texture, NULL, &score_GO.rect);
      break;
    case SCORE_NUMGO:
      SDL_RenderCopy(renderer, score_numGO.texture, NULL, &score_numGO.rect);
      break;
    case LEVEL_GO:
      SDL_RenderCopy(renderer, level_GO.texture, NULL, &level_GO.rect);
      break;
    case LEVEL_NUMGO:
      SDL_RenderCopy(renderer, level_numGO.texture, NULL, &level_numGO.rect);
      break;*/

  }
}





void Draw::setHeightWidth(int h, int w)
{
  window_width = w;
  window_height = h;

}
