#pragma once

struct SDL_Window;



namespace Easy2D
{
	class Renderer;
	class ResourceManager;
	class IGame;
	class Sprite;
	class Engine
	{
	public:
		Engine(IGame& aGame);
		~Engine();

		void Run();

		bool ShouldQuit();

		ResourceManager& GetResourceManager() const;

	private:
		void operator=(Engine&) = delete;

		void SetupSDL();
		void Update();
		void Render();

		SDL_Window* mySDLWindow;
		Renderer* myRenderer;
		ResourceManager* myResourceManager;
		IGame& myGame;
		bool myShouldQuit;
	};

	inline ResourceManager& Engine::GetResourceManager() const
	{
		return *myResourceManager;
	}
}