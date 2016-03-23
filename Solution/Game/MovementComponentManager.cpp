
#include <CollisionEvent.h>
#include <Engine.h>
#include <EventSystem.h>
#include "Enums.h"
#include <Input.h>
#include "MovementComponentManager.h"
#include "PositionComponentManager.h"
#include <Vector2f.h>

MovementComponentManager::MovementComponentManager(Easy2D::Engine& aEngine)
	: IComponentManager(aEngine)
	, myData(16)
	, myInput(aEngine.GetInput())
	, myPositionComponentManager(static_cast<PositionComponentManager&>(aEngine.GetComponentManager(eComponent::POSITION_COMPONENT)))
	, myWindowSize(aEngine.GetWindowSize())
{
	aEngine.GetEventSystem().Subscribe(this);

	for (int& id : myLookup)
	{
		id = -1;
	}
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
	myLookup[aEntity] = myData.Size() - 1;
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
		data.myPosition += data.myVelocity * aDelta;

		if (Outside(data.myPosition.x, 0.f, myWindowSize.x))
		{
			data.myVelocity.x *= -1.f;
		}
		if (Outside(data.myPosition.y, 0.f, myWindowSize.y))
		{
			data.myVelocity.y *= -1.f;
		}
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
	return eComponent::MOVEMENT_COMPONENT;
}

void MovementComponentManager::SetVelocity(Entity aEntity, const CU::Vector2f& aVelocity)
{
	myData[aEntity].myVelocity = aVelocity;
}

bool MovementComponentManager::Outside(float aObjectPos, float aMinPos, float aMaxPos) const
{
	return aObjectPos < aMinPos || aObjectPos > aMaxPos;
}

void MovementComponentManager::OnEvent(const CollisionEvent& aEvent)
{
	if (myLookup[aEvent.myFirstEntity] != -1)
	{
		Reflect(myLookup[aEvent.myFirstEntity], aEvent.myCollisionSide);
	}

	if (myLookup[aEvent.mySecondEntity] != -1)
	{
		Reflect(myLookup[aEvent.mySecondEntity], OppositeCollision(aEvent.myCollisionSide));
	}
}

void MovementComponentManager::Reflect(Entity aEntity, eCollisionSide aCollisionSide)
{
	CU::Vector2f& velocity = myData[aEntity].myVelocity;

	switch (aCollisionSide)
	{
	case eCollisionSide::LEFT:
	case eCollisionSide::RIGHT:
		velocity.x *= -1.f;
		break;
	case eCollisionSide::TOP:
	case eCollisionSide::BOTTOM:
		velocity.y *= -1.f;
		break;
	}
}

eCollisionSide MovementComponentManager::OppositeCollision(eCollisionSide aCollisionSide) const
{
	switch (aCollisionSide)
	{
	case eCollisionSide::LEFT:
		return eCollisionSide::RIGHT;
		break;
	case eCollisionSide::RIGHT:
		return eCollisionSide::LEFT;
		break;
	case eCollisionSide::TOP:
		return eCollisionSide::BOTTOM;
		break;
	case eCollisionSide::BOTTOM:
		return eCollisionSide::TOP;
		break;
	default:
		assert(!"Invalid CollisionSide");
		break;
	}

	return eCollisionSide::NONE;
}

CU::Vector2f MovementComponentManager::GetVelocity(Entity aEntity) const
{
	if (myLookup[aEntity] == -1)
	{
		return CU::Vector2f();
	}

	return myData[myLookup[aEntity]].myVelocity;
}
