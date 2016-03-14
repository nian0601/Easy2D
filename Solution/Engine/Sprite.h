#pragma once
#include <string>
#include <Vector2f.h>

struct SDL_Texture;
struct SDL_Renderer;

namespace Easy2D
{
	class Sprite
	{
	public:
		Sprite(SDL_Texture* aSDLTexture, SDL_Renderer* aSDLRenderer, const CU::Vector2f aSize);
		~Sprite();

		void Render(const CU::Vector2f aPosition);

	private:
		SDL_Texture* mySDLTexture;
		SDL_Renderer* mySDLRenderer;
		CU::Vector2f mySize;
	};
	
}
