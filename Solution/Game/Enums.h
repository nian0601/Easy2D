#pragma once

enum eComponent
{
	RENDER_COMPONENT,
	POSITION_COMPONENT,
	MOVEMENT_COMPONENT,
	COLLISION_COMPONENT,
	PADDLE_COMPONENT,
	__COUNT,
};

enum eCollisionGroup : unsigned int
{
	BRICK = 1,
	PADDLE = 2,
	BALL = 4,
};