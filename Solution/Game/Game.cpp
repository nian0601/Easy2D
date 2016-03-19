#include "Game.h"
#include <Engine.h>
#include <ResourceManager.h>
#include <Sprite.h>
#include "RenderComponentManager.h"
#include "PositionComponentManager.h"
#include "MovementComponentManager.h"
#include "CollisionComponentManager.h"
#include <Rect.h>

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
	CollisionComponentManager& collisionManager = aEngine.CreateComponentManager<CollisionComponentManager>();

	//for (int i = 0; i < MAX_ENTITY_COUNT; ++i)
	for (int i = 0; i < 100; ++i)
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
		movementManager.Create(entity, velocity);
		collisionManager.Create(entity, Easy2D::Rect({ 8.f, 8.f }));
		//collisionManager.Create(entity, 16.f);
	}
}

void Game::Update(float)
{
}

void Game::Render()
{
}