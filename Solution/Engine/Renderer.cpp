#include "stdafx.h"

#include "Renderer.h"
#include <SDL.h>

namespace Easy2D
{
	Renderer::Renderer(SDL_Window* aWindow)
	{
		mySDLRenderer = SDL_CreateRenderer(aWindow, -1, SDL_RENDERER_ACCELERATED);
		if (mySDLRenderer == NULL)
		{
			printf("SDLRenderer could not be created! Error: %s", SDL_GetError());
		}
		else
		{
			SDL_SetRenderDrawColor(mySDLRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		}
	}
	
	
	Renderer::~Renderer()
	{
		SDL_DestroyRenderer(mySDLRenderer);
		mySDLRenderer = NULL;
	}

	void Renderer::Clear()
	{
		SDL_RenderClear(mySDLRenderer);
	}

	void Renderer::Present()
	{
		SDL_RenderPresent(mySDLRenderer);
	}

}
