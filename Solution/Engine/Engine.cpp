#include "stdafx.h"

#include "Engine.h"
#include <EventSystem.h>
#include "IComponentManager.h"
#include "IGame.h"
#include "Input.h"
#include "ResourceManager.h"
#include <SDL.h>
#include "Sprite.h"
#include "Renderer.h"

namespace Easy2D
{
	Engine::Engine(IGame& aGame)
		: mySDLWindow(NULL)
		, myGame(aGame)
		, myComponentManagers(16)
		, myNextEntityID(0)
		, myWindowSize(1280.f, 720.f)
	{
		SetupSDL();
		myRenderer = new Renderer(mySDLWindow);
		myResourceManager = new ResourceManager(myRenderer->GetSDLRenderer());
		myInput = new Input();
		myEventSystem = new EventSystem();

		myGame.Init(*this);

		myTotalTime = float(SDL_GetTicks());
		myPreviousTime = myTotalTime;
	}


	Engine::~Engine()
	{
		myComponentManagers.DeleteAll();
		delete myResourceManager;
		delete myRenderer;
		delete myInput;
		delete myEventSystem;

		SDL_DestroyWindow(mySDLWindow);
		SDL_Quit();
	}

	void Engine::Run()
	{
		SDL_Event event;
		while (ShouldQuit() == false)
		{
			myInput->OnBeginFrame();

			while (SDL_PollEvent(&event) != 0)
			{
				switch (event.type)
				{
				case SDL_QUIT:
					myShouldQuit = true;
					break;
				case SDL_KEYDOWN:
					myInput->OnSDLKeyDown(event.key.keysym.scancode);
					break;
				case SDL_KEYUP:
					myInput->OnSDLKeyUp(event.key.keysym.scancode);
					break;
				} 
			}

			myTotalTime = float(SDL_GetTicks());

			if (myInput->KeyDown(eKey::_ESCAPE))
			{
				myShouldQuit = true;
			}

			OnBeginFrame();
			Update();
			Render();
			OnEndFrame();

			myPreviousTime = myTotalTime;
		}
	}

	bool Engine::ShouldQuit()
	{
		return myShouldQuit;
	}

	Entity Engine::CreateEntity()
	{
		return myNextEntityID++;
	}

	IComponentManager& Engine::GetComponentManager(unsigned int aID) const
	{
		for (IComponentManager* manager : myComponentManagers)
		{
			if (manager->GetID() == aID)
			{
				return *manager;
			}
		}

		assert(!"Tried to get invalid ComponentManager");
		return *myComponentManagers[0];
	}

	void Engine::SetupSDL()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! Error: %s", SDL_GetError());
		}
		else
		{
			mySDLWindow = SDL_CreateWindow("SDL Entity System", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED
				, int(myWindowSize.x), int(myWindowSize.y), SDL_WINDOW_SHOWN);
			if (mySDLWindow == NULL)
			{
				printf("SDL could not create window! Error: %s", SDL_GetError());
			}
		}
	}

	void Engine::OnBeginFrame()
	{
		for each (IComponentManager* manager in myComponentManagers)
		{
			manager->OnBeginFrame();
		}
	}

	void Engine::Update()
	{
		float deltaTime = (myTotalTime - myPreviousTime) / 1000.f;
		for each (IComponentManager* manager in myComponentManagers)
		{
			manager->Update(deltaTime);
		}

		myGame.Update(deltaTime);
	}

	void Engine::Render()
	{
		myRenderer->Clear();

		for each (IComponentManager* manager in myComponentManagers)
		{
			manager->Render();
		}

		myGame.Render();

		myRenderer->Present();
	}

	void Engine::OnEndFrame()
	{
		for each (IComponentManager* manager in myComponentManagers)
		{
			manager->OnEndFrame();
		}
	}

}