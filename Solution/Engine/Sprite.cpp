#include "stdafx.h"

#include <SDL.h>
#include "Sprite.h"


namespace Easy2D
{
	Sprite::Sprite(SDL_Texture* aSDLTexture, SDL_Renderer* aSDLRenderer, const CU::Vector2f aSize)
		: mySDLTexture(aSDLTexture)
		, mySDLRenderer(aSDLRenderer)
		, mySize(aSize)
	{
	}
	
	
	Sprite::~Sprite()
	{
	}

	void Sprite::Render(const CU::Vector2f aPosition)
	{
		SDL_Rect rect;
		rect.x = int(aPosition.x - mySize.x / 2.f);
		rect.y = int(aPosition.y - mySize.y / 2.f);
		rect.w = int(mySize.x);
		rect.h = int(mySize.y);
		SDL_RenderCopy(mySDLRenderer, mySDLTexture, NULL, &rect);
	}

}
