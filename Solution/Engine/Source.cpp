#include "stdafx.h"

#include "IGame.h"
#include "Engine.h"

int main(int , char*[])
{
	Easy2D::IGame game;
	Easy2D::Engine engine(game);

	engine.Run();

	return 0;
}