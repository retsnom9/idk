#include <stdio.h>
#include <stdlib.h>
#include "SDL/include/SDL.h"

#pragma comment( lib, "SDL/lib/x86/SDL2.lib")
#pragma comment( lib, "SDL/lib/x86/SDL2main.lib")

int main(int argc, char* args[])
{
	int close = 0;
	int x = 295;
	int y = 215;
	SDL_Texture* texture;
	SDL_Event event;
	SDL_Surface* surface;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer);
    surface = SDL_LoadBMP("ship.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, surface); 
	surface->clip_rect.h = 60;
	surface->clip_rect.w = 60;


	while (close == 0)
	{
		

		if (SDL_PollEvent(&event))
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				close++;
			}
			
			if (event.key.keysym.sym == SDLK_LEFT)
			{
				surface->clip_rect.x -= 10;
			}

			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				surface->clip_rect.x += 10;
			}

			if (event.key.keysym.sym == SDLK_UP)
			{
				surface->clip_rect.y -= 10;
			}

			if (event.key.keysym.sym == SDLK_DOWN)
			{
				surface->clip_rect.y += 10;
			}

			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

			SDL_RenderClear(renderer);

			

		

			

			
			SDL_RenderCopy(renderer, texture, NULL, &surface->clip_rect);

			SDL_RenderPresent(renderer);
		}
	}

	SDL_Quit();
	return(EXIT_SUCCESS);
}