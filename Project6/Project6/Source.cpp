#include <stdio.h>
#include <stdlib.h>
#include "SDL/include/SDL.h"

#pragma comment( lib, "SDL/lib/x86/SDL2.lib")
#pragma comment( lib, "SDL/lib/x86/SDL2main.lib")

int main(int argc, char* args[])
{
	int close = 0;
	int i = 0;
	int a = 0;
	int shot = 0;
	int x = 295;
	int y = 215;
	SDL_Texture* texture;
	SDL_Texture* textureb;
	SDL_Event event;
	SDL_Surface* surface;
	SDL_Surface* surfaceb[20];
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer);

	surface = SDL_LoadBMP("ship.bmp");
	textureb = SDL_CreateTextureFromSurface(renderer, surfaceb[a]);
	while (a < 20)
	{
		surfaceb[a] = SDL_LoadBMP("shot.bmp");
		surfaceb[a]->clip_rect.h = 20;
		surfaceb[a]->clip_rect.w = 20;
		surfaceb[a]->clip_rect.x = 800;
		surfaceb[a]->clip_rect.y = 800;

		a++;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	surface->clip_rect.h = 50;
	surface->clip_rect.w = 50;
	surface->clip_rect.x = x;
	surface->clip_rect.y = y;

	while (close == 0)
	{
		if (a == 20)
		{
			a = 0;
		}

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

			if (event.key.keysym.sym == SDLK_SPACE)
			{
				shot = 1;
				surfaceb[a]->clip_rect.x = (surface->clip_rect.x + 15);
				surfaceb[a]->clip_rect.y = surface->clip_rect.y;
				a++;
			}
		}

		if (i % 10 == 0)
		{
			surfaceb[a]->clip_rect.y--;
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, textureb, NULL, &surfaceb[a]->clip_rect);

		SDL_RenderCopy(renderer, texture, NULL, &surface->clip_rect);

		SDL_RenderPresent(renderer);

		i++;
	}

	a = 0;

	while (a < 20)
	{
		SDL_FreeSurface(surfaceb[0]);
	}

	SDL_DestroyWindow(window);
	SDL_FreeSurface(surface);
	SDL_Quit();
	return(EXIT_SUCCESS);
}