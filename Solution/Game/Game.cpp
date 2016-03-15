#include "Game.h"
#include <Engine.h>
#include <ResourceManager.h>
#include <Sprite.h>
#include "SystemManager.h"
#include "RenderSystem.h"
Game::Game()
{
}


Game::~Game()
{
}

void Game::Init(Easy2D::Engine& aEngine)
{
	mySystemManager = new SystemManager();

	unsigned int entity = mySystemManager->Create();
	unsigned int entity2 = mySystemManager->Create();
	unsigned int entity3 = mySystemManager->Create();
	mySystemManager->GetRenderSystem()->Create(entity, "Data/test.bmp", aEngine.GetResourceManager());
	mySystemManager->GetRenderSystem()->Create(entity2, "Data/test.bmp", aEngine.GetResourceManager());
	mySystemManager->GetRenderSystem()->Create(entity3, "Data/test.bmp", aEngine.GetResourceManager());
}

void Game::Update(float aDelta)
{
	mySystemManager->Update(aDelta);
}

void Game::Render()
{
	mySystemManager->Render();
}
