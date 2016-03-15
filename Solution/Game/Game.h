#pragma once
#include <IGame.h>
#include <Vector2f.h>

namespace Easy2D
{
	class Sprite;
}

class Game : public Easy2D::IGame
{
public:
	Game();
	~Game();

	void Init(Easy2D::Engine& aEngine) override;
	void Update(float aDelta) override;
	void Render() override;
};

