#include "SystemManager.h"
#include "ISystem.h"

#include "RenderSystem.h"

SystemManager::SystemManager()
	: myNextEntityID(0)
{
	mySystems[eComponent::RENDER] = new RenderSystem();
}


SystemManager::~SystemManager()
{
}

unsigned int SystemManager::Create()
{
	return myNextEntityID++;
}

void SystemManager::Update(float aDelta)
{
	for each (ISystem* system in mySystems)
	{
		if (system != nullptr)
		{
			system->Update(aDelta);
		}
	}
}

void SystemManager::Render()
{
	for each (ISystem* system in mySystems)
	{
		if (system != nullptr)
		{
			system->Render();
		}
	}
}

RenderSystem* SystemManager::GetRenderSystem()
{
	return static_cast<RenderSystem*>(mySystems[eComponent::RENDER]);
}