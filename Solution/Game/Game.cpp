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

	for (int i = 0; i < 1000; ++i)
	{
		CU::Vector2f pos;
		pos.x = float(rand() % 1280);
		pos.y = float(rand() % 720);

		CU::Vector2f velocity;
		velocity.x = float((rand() % 400) - 400.f);
		velocity.y = float((rand() % 400) - 400.f);

		Entity entity = aEngine.CreateEntity();
		renderManager.Create(entity, "Data/ball.bmp", aEngine.GetResourceManager());
		positionManager.Create(entity, pos);
		movementManager.Create(entity, velocity/*Easy2D::eKey::_W, Easy2D::eKey::_S, Easy2D::eKey::_A, Easy2D::eKey::_D*/);
	}

	//Entity entity = aEngine.CreateEntity();
	//renderManager.Create(entity, "Data/ball.bmp", aEngine.GetResourceManager());
	//positionManager.Create(entity, CU::Vector2f(200.f, 200.f));
	//movementManager.Create(entity, CU::Vector2f(200.f, 200.f)/*Easy2D::eKey::_W, Easy2D::eKey::_S, Easy2D::eKey::_A, Easy2D::eKey::_D*/);

	//Entity entity2 = aEngine.CreateEntity();
	//renderManager.Create(entity2, "Data/ball.bmp", aEngine.GetResourceManager());
	//positionManager.Create(entity2, CU::Vector2f(600.f, 200.f));
	//movementManager.Create(entity2, CU::Vector2f(-200.f, -200.f)/*Easy2D::eKey::_I, Easy2D::eKey::_K, Easy2D::eKey::_J, Easy2D::eKey::_L*/);
}

void Game::Update(float aDelta)
{
}

void Game::Render()
{
}