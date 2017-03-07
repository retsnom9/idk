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
	SDL_Event event;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer);

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
				x -= 10;
			}

			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				x += 10;
			}

			if (event.key.keysym.sym == SDLK_UP)
			{
				y -= 10;
			}

			if (event.key.keysym.sym == SDLK_DOWN)
			{
				y += 10;
			}

			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

			SDL_RenderClear(renderer);

			SDL_Rect rectangle;
			rectangle.x = x;
			rectangle.y = y;
			rectangle.w = 50;
			rectangle.h = 50;

			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

			SDL_RenderFillRect(renderer, &rectangle);

			SDL_RenderPresent(renderer);
		}
	}

	SDL_Quit();
	return(EXIT_SUCCESS);
}