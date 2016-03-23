#pragma once

#include <GameEnums.h>

struct CollisionEvent
{
	unsigned int myFirstEntity;
	unsigned int mySecondEntity;
	eCollisionSide myCollisionSide;
};