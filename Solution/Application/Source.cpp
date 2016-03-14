#include <Game.h>
#include <Engine.h>

int main()
{
	Game game;
	Easy2D::Engine engine(game);

	engine.Run();

	return 0;
}