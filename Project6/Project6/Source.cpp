#include <stdio.h>
#include <stdlib.h>
#include "SDL/include/SDL.h"

#pragma comment( lib, "SDL/lib/x86/SDL2.lib")
#pragma comment( lib, "SDL/lib/x86/SDL2main.lib")

int main(int argc, char* args[])
{
	int close = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int b = 0;
	int a = 0;
	int shot = 0;
	int x = 295;
	int y = 215;
	SDL_Texture* texture;
	SDL_Texture* textureb;
	SDL_Texture* texturec;
	SDL_Event event;
	SDL_Surface* surface;
	SDL_Surface* surfaceb[20];
	SDL_Surface* surfacec[1];
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer);

	surface = SDL_LoadBMP("ship.bmp");

	while (a < 20)
	{
		surfaceb[a] = SDL_LoadBMP("shot.bmp");
		surfaceb[a]->clip_rect.h = 20;
		surfaceb[a]->clip_rect.w = 20;
		surfaceb[a]->clip_rect.x = 800;
		surfaceb[a]->clip_rect.y = 800;

		a++;
	}

	while (b < 2)
	{
		surfacec[b] = SDL_LoadBMP("map.bmp");
		surfacec[b]->clip_rect.h = 640;
		surfacec[b]->clip_rect.w = 640;
		surfacec[b]->clip_rect.x = 0;
		surfacec[b]->clip_rect.y = 0;

		b++;
	}

	textureb = SDL_CreateTextureFromSurface(renderer, surfaceb[0]);
	texturec = SDL_CreateTextureFromSurface(renderer, surfacec[0]);
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	surface->clip_rect.h = 50;
	surface->clip_rect.w = 50;
	surface->clip_rect.x = x;
	surface->clip_rect.y = y;
	a = 0;
	b = 0;

	while (close == 0)
	{
		if (a == 19)
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
				a++;
				shot = 1;
				surfaceb[a]->clip_rect.x = (surface->clip_rect.x + 15);
				surfaceb[a]->clip_rect.y = surface->clip_rect.y;
			}
		}

		if (i % 10 == 0)
		{
			while (k != 20)
			{
				surfaceb[k]->clip_rect.y--;
				k++;
			}
		}

		k = 0;

		if (i % 10 == 0)
		{
				surfacec[j]->clip_rect.y--;
		}



		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, texturec, NULL, &surfacec[j]->clip_rect);

		while (k != 20)
		{
			SDL_RenderCopy(renderer, textureb, NULL, &surfaceb[k]->clip_rect);
			k++;
		}
		k = 0;

		SDL_RenderCopy(renderer, texture, NULL, &surface->clip_rect);

		SDL_RenderPresent(renderer);

		i++;
	}

	a = 0;
	b = 0;

	while (a < 20)
	{
		SDL_FreeSurface(surfaceb[a]);
		a++;
	}

	while (b < 2)
	{
		SDL_FreeSurface(surfacec[b]);
		b++;
	}

	SDL_DestroyWindow(window);
	SDL_FreeSurface(surface);
	SDL_Quit();
	return(EXIT_SUCCESS);
}