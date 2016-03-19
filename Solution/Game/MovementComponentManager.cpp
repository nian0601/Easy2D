#include "MovementComponentManager.h"
#include <Input.h>
#include <Vector2f.h>
#include "PositionComponentManager.h"
#include "Enums.h"
#include <Engine.h>

MovementComponentManager::MovementComponentManager(Easy2D::Engine& aEngine)
	: IComponentManager(aEngine)
	, myData(16)
	, myInput(aEngine.GetInput())
	, myPositionComponentManager(static_cast<PositionComponentManager&>(aEngine.GetComponentManager(eComponent::POSITION)))
	, myWindowSize(aEngine.GetWindowSize())
{
}


MovementComponentManager::~MovementComponentManager()
{
}

void MovementComponentManager::Create(Entity aEntity, const CU::Vector2f& aStartVelocity)
{
	MovementData data;
	data.myOwner = aEntity;
	data.myVelocity = aStartVelocity;

	myData.Add(data);
}


void MovementComponentManager::OnBeginFrame()
{
	for (MovementData& data : myData)
	{
		data.myPosition = myPositionComponentManager.GetPosition(data.myOwner);
	}
}


void MovementComponentManager::Update(float aDelta)
{
	for (MovementData& data : myData)
	{
		//CU::Vector2f pos = myPositionComponentManager.GetPosition(data.myOwner);
		//pos += data.myVelocity * aDelta;

		data.myPosition += data.myVelocity * aDelta;

		if (Outside(data.myPosition.x, 0.f, myWindowSize.x))
		{
			data.myVelocity.x *= -1.f;
		}
		if (Outside(data.myPosition.y, 0.f, myWindowSize.y))
		{
			data.myVelocity.y *= -1.f;
		}

		myPositionComponentManager.SetPosition(data.myOwner, data.myPosition);
	}
}

void MovementComponentManager::OnEndFrame()
{
	for each (const MovementData& data in myData)
	{
		myPositionComponentManager.SetPosition(data.myOwner, data.myPosition);
	}
}


void MovementComponentManager::Render()
{
}

unsigned int MovementComponentManager::GetID()
{
	return eComponent::MOVEMENT;
}

void MovementComponentManager::SetVelocity(Entity aEntity, const CU::Vector2f& aVelocity)
{
	myData[aEntity].myVelocity = aVelocity;
}

bool MovementComponentManager::Outside(float aObjectPos, float aMinPos, float aMaxPos) const
{
	return aObjectPos < aMinPos || aObjectPos > aMaxPos;
}