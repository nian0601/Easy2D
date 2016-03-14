#pragma once
#include <string>

struct SDL_Texture;
struct SDL_Renderer;

namespace Easy2D
{
	class Sprite
	{
	public:
		Sprite(SDL_Texture* aSDLTexture, SDL_Renderer* aSDLRenderer);
		~Sprite();

		void Render();

	private:
		SDL_Texture* mySDLTexture;
		SDL_Renderer* mySDLRenderer;
	};
	
}
