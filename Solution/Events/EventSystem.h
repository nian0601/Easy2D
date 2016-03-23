#pragma once
#include <GrowingArray.h>
#include "IEventSubscriber.h"

class EventSystem
{
public:
	EventSystem();
	~EventSystem();

	template <typename T>
	void SendEvent(const T& aEvent);

	void Subscribe(IEventSubscriber* aSubscriber);

private:
	CU::GrowingArray<IEventSubscriber*> mySubscribers;
};

template <typename T>
void EventSystem::SendEvent(const T& aEvent)
{
	for (IEventSubscriber* subscriber : mySubscribers)
	{
		subscriber->OnEvent(aEvent);
	}
}