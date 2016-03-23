#include "EventSystem.h"


EventSystem::EventSystem()
	: mySubscribers(16)
{
}


EventSystem::~EventSystem()
{
}

void EventSystem::Subscribe(IEventSubscriber* aSubscriber)
{
	mySubscribers.Add(aSubscriber);
}
