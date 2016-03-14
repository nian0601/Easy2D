#include "stdafx.h"

#include "Sprite.h"
#include <SDL.h>
#include "ResourceManager.h"


namespace Easy2D
{
	ResourceManager::ResourceManager(SDL_Renderer* aRenderer)
		: mySDLRenderer(aRenderer)
	{
	}
	
	
	ResourceManager::~ResourceManager()
	{
	}

	Sprite* ResourceManager::GetSprite(const std::string& aPath)
	{
		if (mySprites.find(aPath) == mySprites.end())
		{
			LoadSprite(aPath);
		}

		return mySprites[aPath];
	}

	void ResourceManager::LoadSprite(const std::string& aPath)
	{
		CU::Vector2f size;

		SDL_Texture* texture = NULL;
		SDL_Surface* loadedSurface = SDL_LoadBMP(aPath.c_str());

		if (loadedSurface == NULL)
		{
			printf("Failed to LoadSprite ( %s )! Error: %s", aPath.c_str(), SDL_GetError());
		}
		else
		{
			texture = SDL_CreateTextureFromSurface(mySDLRenderer, loadedSurface);
			if (texture == NULL)
			{
				printf("Failed to create texture from %s! Error: %s", aPath.c_str(), SDL_GetError());
			}

			size.x = loadedSurface->w;
			size.y = loadedSurface->h;

			SDL_FreeSurface(loadedSurface);
		}

		mySprites[aPath] = new Sprite(texture, mySDLRenderer, size);
	}
}
