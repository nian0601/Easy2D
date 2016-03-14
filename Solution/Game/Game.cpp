#include "Game.h"
#include <Engine.h>
#include <ResourceManager.h>
#include <Sprite.h>

Game::Game()
{
}


Game::~Game()
{
}

void Game::Init(Easy2D::Engine& aEngine)
{
	mySprite = aEngine.GetResourceManager().GetSprite("Data/test.bmp");
	mySprite2 = aEngine.GetResourceManager().GetSprite("Data/test.bmp");

	myPosition = CU::Vector2f(20.f, 100.f);
	myPosition2 = CU::Vector2f(20.f, 300.f);
}

void Game::Update(float aDelta)
{
	myPosition.x += 50.f * aDelta;
	myPosition2.x += 50.f * aDelta;
}

void Game::Render()
{
	mySprite->Render(myPosition);
	mySprite2->Render(myPosition2);
}
