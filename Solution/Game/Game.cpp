#include "Game.h"
#include <Engine.h>
#include <ResourceManager.h>
#include <Sprite.h>
#include "RenderComponentManager.h"
#include "PositionComponentManager.h"
#include "MovementComponentManager.h"
Game::Game()
{
}


Game::~Game()
{
}

void Game::Init(Easy2D::Engine& aEngine)
{
	PositionComponentManager& positionManager = aEngine.CreateComponentManager<PositionComponentManager>();
	RenderComponentManager& renderManager = aEngine.CreateComponentManager<RenderComponentManager>();
	MovementComponentManager& movementManager = aEngine.CreateComponentManager<MovementComponentManager>();

	Entity entity = aEngine.CreateEntity();
	renderManager.Create(entity, "Data/test.bmp", aEngine.GetResourceManager());
	positionManager.Create(entity, CU::Vector2f(200.f, 200.f));
	movementManager.Create(entity, Easy2D::eKey::_W, Easy2D::eKey::_S, Easy2D::eKey::_A, Easy2D::eKey::_D);

	Entity entity2 = aEngine.CreateEntity();
	renderManager.Create(entity2, "Data/test.bmp", aEngine.GetResourceManager());
	positionManager.Create(entity2, CU::Vector2f(600.f, 200.f));
	movementManager.Create(entity2, Easy2D::eKey::_I, Easy2D::eKey::_K, Easy2D::eKey::_J, Easy2D::eKey::_L);
}

void Game::Update(float aDelta)
{
}

void Game::Render()
{
}