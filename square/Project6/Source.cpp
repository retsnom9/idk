#include <stdio.h>
#include <stdlib.h>
#include "SDL/include/SDL.h"

#pragma comment( lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib")

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface* surface;
	Uint32 rmask, gmask, bmask, amask;
	SDL_Window *window;
	SDL_Renderer *renderer;

	int i = 0;

	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);

	SDL_Rect rectangle;

	rectangle.x = 295;
	rectangle.y = 215;
	rectangle.w = 50;
	rectangle.h = 50;

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	SDL_RenderFillRect(renderer, &rectangle);

	SDL_RenderPresent(renderer);

	while (1)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				{
					i++;
					break;
				}

			default:
				break;
			}
		}

		if (i == 1)
		{
			break;
		}
	}
	
	SDL_Quit();
	return(EXIT_SUCCESS);
}