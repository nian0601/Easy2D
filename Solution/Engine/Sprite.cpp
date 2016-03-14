#include "stdafx.h"

#include <SDL.h>
#include "Sprite.h"


namespace Easy2D
{
	Sprite::Sprite(SDL_Texture* aSDLTexture, SDL_Renderer* aSDLRenderer)
		: mySDLTexture(aSDLTexture)
		, mySDLRenderer(aSDLRenderer)
	{
	}
	
	
	Sprite::~Sprite()
	{
	}

	void Sprite::Render()
	{
		SDL_RenderCopy(mySDLRenderer, mySDLTexture, NULL, NULL);
	}

}
