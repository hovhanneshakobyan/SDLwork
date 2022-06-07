#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
using namespace std;
//void printMessageAt(const string& msg, Uint32 x, Uint32 y, TTF_Font *myFont, SDL_Surface *screen) {
  //  SDL_Rect dest = {50,50,0,0};
   // SDL_Color color = {0, 0, 0, 0};
   // SDL_Surface *stext = TTF_RenderText_Blended(myFont, "", color);
   // if (stext) {
     //   SDL_BlitSurface( stext, NULL, screen, &dest );
       // SDL_FreeSurface(stext);
   // }
   // else {
     //   throw
       // string("");
  //  }
//}
int main () {
	
{
   SDL_Init( SDL_INIT_EVERYTHING );
   SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
   SDL_Window* window = SDL_CreateWindow( "Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800 , 600, SDL_WINDOW_SHOWN );
   SDL_Renderer* renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

	//case SDL_KEYDOWN:
        //{
            //char keyDown = ev.key.keysym.scancode;

           // if (keyDown == SDL_SCANCODE_RETURN)  EnterKeyPressed = true;
           // else if (keyDown == SDL_SCANCODE_BACKSPACE)  BackSpaceKeyPressed = true;
           // else if (keyDown == SDL_SCANCODE_SPACE)  SpacebarKeyPressed = true;
         //   else if (keyDown == SDL_SCANCODE_ESCAPE)  EscapeKeyPressed = true;
       // }
     //   break;

   TTF_Init();

TTF_Font* font = TTF_OpenFont ("gor.ttf", 60);
SDL_Color col = {255,255, 0, 255};
//SDL_Surface* surf = TTF_RenderUTF8_Blended(font, "omg", col);
//SDL_Teture* tex = SDL_CreateTextureFromSurface(renderer, surf);
    
//TTF_SizeText ("gor.ttf", &20, &20);
//if (W> (Left-Right))

	bool isRunning = true;
	SDL_Event ev;

	string text = " ";
	//line = " ";
	

	while(isRunning)
	{
		SDL_RenderClear(renderer);
		while(SDL_PollEvent(&ev) != 0)
	{	

	
		if(ev.type == SDL_QUIT)	
			isRunning = false;
		else if (ev.type == SDL_TEXTINPUT)
		{
			text += ev.text.text;
			cout << text << endl;	
		
		}
		if (ev.type ==SDL_KEYDOWN && ev.key.keysym.sym == SDLK_BACKSPACE)
		{
			text.pop_back();
		}
	}
	SDL_Rect box;
	box.x = 0;
	box.y = 0;	
	SDL_Surface* surf = TTF_RenderText_Blended_Wrapped(font, text.c_str(), col, 800);
	box.w = surf -> w;
	box.h = surf -> h;
	//box.w = surf -> 
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	
	SDL_RenderCopy(renderer, tex, NULL, &box);
	SDL_RenderPresent(renderer);
	SDL_FreeSurface(surf);
	SDL_DestroyTexture(tex);
	}




	return 0;
}
	
	
	
	



	







}
