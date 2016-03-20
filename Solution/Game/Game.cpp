#include "Game.h"
#include <Engine.h>
#include <ResourceManager.h>
#include <Sprite.h>
#include "RenderComponentManager.h"
#include "PositionComponentManager.h"
#include "MovementComponentManager.h"
#include "CollisionComponentManager.h"
#include "PaddleComponentManager.h"
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
	PaddleComponentManager& paddleManager = aEngine.CreateComponentManager<PaddleComponentManager>();

	for (int y = 0; y < 5; ++y)
	{
		for (int x = 0; x < 8; ++x)
		{
			CU::Vector2f position;
			position.x = x * (128.f + 2.f) + 128.f + 128.f/2.f;
			position.y = y * (32.f + 2.f) + 128.f;

			Entity brick = aEngine.CreateEntity();
			renderManager.Create(brick, "Data/brick.bmp", aEngine.GetResourceManager());
			positionManager.Create(brick, position);
		}
	}

	CU::Vector2f position;
	position.x = aEngine.GetWindowSize().x / 2.f - 128.f / 2.f;
	position.y = aEngine.GetWindowSize().y - 16.f;
	Entity paddle = aEngine.CreateEntity();
	renderManager.Create(paddle, "Data/paddle.bmp", aEngine.GetResourceManager());
	positionManager.Create(paddle, position);
	paddleManager.Create(paddle);
	collisionManager.Create(paddle, Easy2D::Rect(CU::Vector2f(128.f, 16.f)));


	position.x = aEngine.GetWindowSize().x / 2.f;
	position.y = aEngine.GetWindowSize().y / 1.5f;
	Entity ball = aEngine.CreateEntity();
	renderManager.Create(ball, "Data/ball.bmp", aEngine.GetResourceManager());
	positionManager.Create(ball, position);
	movementManager.Create(ball, CU::Vector2f(200.f, -200.f));
	collisionManager.Create(ball, Easy2D::Rect(CU::Vector2f(8.f, 8.f)));
}

void Game::Update(float)
{
}

void Game::Render()
{
}