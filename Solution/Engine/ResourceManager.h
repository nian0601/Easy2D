#pragma once

#include <string>
#include <unordered_map>

struct SDL_Renderer;
struct SDL_Texture;

namespace Easy2D
{
	class Sprite;
	class ResourceManager
	{
	public:
		ResourceManager(SDL_Renderer* aSDLRenderer);
		~ResourceManager();

		Sprite* GetSprite(const std::string& aPath);

	private:
		void LoadSprite(const std::string& aPath);
		SDL_Texture* CreateTexture(const std::string& aPath);

		std::unordered_map<std::string, Sprite*> mySprites;
		SDL_Renderer* mySDLRenderer;
	};
}
