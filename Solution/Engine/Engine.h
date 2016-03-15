#pragma once

#include "Defines.h"
#include <GrowingArray.h>

struct SDL_Window;

namespace Easy2D
{
	class Renderer;
	class ResourceManager;
	class IGame;
	class Sprite;
	class IComponentManager;
	class Input;
	class Engine
	{
	public:
		Engine(IGame& aGame);
		~Engine();

		void Run();

		bool ShouldQuit();

		ResourceManager& GetResourceManager() const;
		const Input& GetInput() const;

		Entity CreateEntity();

		template <typename T>
		T& CreateComponentManager();

		IComponentManager& GetComponentManager(unsigned int aID) const;

	private:
		Engine(Engine&) = delete;
		void operator=(Engine&) = delete;

		void SetupSDL();
		void Update();
		void Render();

		SDL_Window* mySDLWindow;
		Renderer* myRenderer;
		ResourceManager* myResourceManager;
		Input* myInput;
		IGame& myGame;
		bool myShouldQuit;

		CU::GrowingArray<IComponentManager*> myComponentManagers;
		Entity myNextEntityID;
	};

	inline ResourceManager& Engine::GetResourceManager() const
	{
		return *myResourceManager;
	}

	inline const Input& Engine::GetInput() const
	{
		return *myInput;
	}

	template <typename T>
	T& Engine::CreateComponentManager()
	{
		T* manager = new T(*this);
		myComponentManagers.Add(manager);
		return *manager;
	}
}