#include "stdafx.h"

#include "Engine.h"
#include "IGame.h"
#include "ResourceManager.h"
#include <SDL.h>
#include "Sprite.h"
#include "Renderer.h"

namespace Easy2D
{
	Engine::Engine(IGame& aGame)
		: mySDLWindow(NULL)
		, myGame(aGame)
	{
		SetupSDL();
		myRenderer = new Renderer(mySDLWindow);
		myResourceManager = new ResourceManager(myRenderer->GetSDLRenderer());

		mySprite = myResourceManager->GetSprite("Data/test.bmp");
		myGame.Init(*this);
	}


	Engine::~Engine()
	{
		SDL_DestroyWindow(mySDLWindow);
		SDL_Quit();
	}

	void Engine::Run()
	{
		while (ShouldQuit() == false)
		{
			Update();
			Render();
		}
	}

	bool Engine::ShouldQuit()
	{
		return myShouldQuit;
	}

	void Engine::SetupSDL()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! Error: %s", SDL_GetError());
		}
		else
		{
			mySDLWindow = SDL_CreateWindow("SDL_Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
			if (mySDLWindow == NULL)
			{
				printf("SDL could not create window! Error: %s", SDL_GetError());
			}
		}
	}

	void Engine::Update()
	{
		myGame.Update(1.f / 30.f);
	}

	void Engine::Render()
	{
		myRenderer->Clear();

		myGame.Render();

		mySprite->Render(CU::Vector2f(200.f, 200.f));

		myRenderer->Present();
	}

}