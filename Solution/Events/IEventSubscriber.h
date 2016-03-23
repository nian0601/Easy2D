#pragma once

struct CollisionEvent;

class IEventSubscriber
{
public:
	virtual void OnEvent(const CollisionEvent&){};

protected:
	IEventSubscriber();
	virtual ~IEventSubscriber();
};

