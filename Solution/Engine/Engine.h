#pragma once

#include "Defines.h"
#include <GrowingArray.h>
#include <Vector2f.h>

struct SDL_Window;

class EventSystem;

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
		EventSystem& GetEventSystem() const;

		Entity CreateEntity();

		template <typename T>
		T& CreateComponentManager();

		IComponentManager& GetComponentManager(unsigned int aID) const;

		const CU::Vector2f& GetWindowSize() const;

	private:
		Engine(Engine&) = delete;
		void operator=(Engine&) = delete;

		void SetupSDL();
		void OnBeginFrame();
		void Update();
		void Render();
		void OnEndFrame();

		SDL_Window* mySDLWindow;
		Renderer* myRenderer;
		ResourceManager* myResourceManager;
		Input* myInput;
		IGame& myGame;
		CU::Vector2f myWindowSize;
		bool myShouldQuit;

		CU::GrowingArray<IComponentManager*> myComponentManagers;
		Entity myNextEntityID;
		EventSystem* myEventSystem;

		float myTotalTime;
		float myPreviousTime;
	};

	inline ResourceManager& Engine::GetResourceManager() const
	{
		return *myResourceManager;
	}

	inline const Input& Engine::GetInput() const
	{
		return *myInput;
	}

	inline EventSystem& Engine::GetEventSystem() const
	{
		return *myEventSystem;
	}

	template <typename T>
	T& Engine::CreateComponentManager()
	{
		T* manager = new T(*this);
		myComponentManagers.Add(manager);
		return *manager;
	}

	inline const CU::Vector2f& Engine::GetWindowSize() const
	{
		return myWindowSize;
	}
}