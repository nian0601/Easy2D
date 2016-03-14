#pragma once

struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Window;

namespace Easy2D
{
	class Renderer
	{
	public:
		Renderer(SDL_Window* aWindow);
		~Renderer();

		void Clear();
		void Present();

		SDL_Renderer* GetSDLRenderer() const;

	private:
		SDL_Renderer* mySDLRenderer;
	};

	inline SDL_Renderer* Renderer::GetSDLRenderer() const
	{
		return mySDLRenderer;
	}
}

