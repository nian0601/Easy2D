#include "PaddleComponentManager.h"
#include <Engine.h>
#include "PositionComponentManager.h"
#include "Enums.h"
#include <Input.h>

PaddleComponentManager::PaddleComponentManager(Easy2D::Engine& aEngine)
	: IComponentManager(aEngine)
	, myInput(aEngine.GetInput())
	, myPositionManager(static_cast<PositionComponentManager&>(aEngine.GetComponentManager(eComponent::POSITION)))
	, myData(16)
{
}


PaddleComponentManager::~PaddleComponentManager()
{
}

void PaddleComponentManager::Create(Entity aEntity)
{
	PaddleData data;
	data.myOwner = aEntity;
	data.myPosition = CU::Vector2f(-1.f, -1.f);
	myData.Add(data);
}

void PaddleComponentManager::OnBeginFrame()
{
	for (PaddleData& data : myData)
	{
		data.myPosition = myPositionManager.GetPosition(data.myOwner);
	}
}

void PaddleComponentManager::OnEndFrame()
{
	for each (const PaddleData& data in myData)
	{
		myPositionManager.SetPosition(data.myOwner, data.myPosition);
	}
}

void PaddleComponentManager::Update(float)
{
	for (PaddleData& data : myData)
	{
		data.myPosition.x = myInput.GetMousePosition().x;
	}
}

void PaddleComponentManager::Render()
{
}

unsigned int PaddleComponentManager::GetID()
{
	return eComponent::PADDLE;
}