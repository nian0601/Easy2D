#include "CollisionComponentManager.h"
#include "MovementComponentManager.h"
#include "Enums.h"
#include "PositionComponentManager.h"
#include <Engine.h>
#include <EventSystem.h>

CollisionComponentManager::CollisionComponentManager(Easy2D::Engine& aEngine)
	: IComponentManager(aEngine)
	, myMovementManager(static_cast<MovementComponentManager&>(aEngine.GetComponentManager(eComponent::MOVEMENT_COMPONENT)))
	, myPositionManager(static_cast<PositionComponentManager&>(aEngine.GetComponentManager(eComponent::POSITION_COMPONENT)))
	, myEventSystem(aEngine.GetEventSystem())
	, myCollisionData(16)
	, myCollisionEvents(16)
{
}


CollisionComponentManager::~CollisionComponentManager()
{
}

void CollisionComponentManager::Create(Entity aOwner, const Easy2D::Rect& aRect, unsigned int aCollisionGroup, unsigned int aCollisionFilter)
{
	CollisionData data;
	data.myOwner = aOwner;
	data.myRect = aRect;
	data.myCollisionGroup = aCollisionGroup;
	data.myCollisionFilter = aCollisionFilter;

	myCollisionData.Add(data);
	myLookup[aOwner] = myCollisionData.Size() - 1;
}

void CollisionComponentManager::OnBeginFrame()
{
	for (CollisionData& data : myCollisionData)
	{
		data.myRect.Update(myPositionManager.GetPosition(data.myOwner));
		data.myVelocity = myMovementManager.GetVelocity(data.myOwner);
	}
}

void CollisionComponentManager::Update(float)
{
	int size = myCollisionData.Size();
	for (int i = 0; i < size; ++i)
	{
		CollisionData& data1 = myCollisionData[i];

		for (int j = i + 1; j < size; ++j)
		{
			CollisionData& data2 = myCollisionData[j];

			if (CanCollide(data1, data2) == true && Collision(data1, data2) == true)
			{
				CollisionEvent result;
				result.myFirstEntity = data1.myOwner;
				result.mySecondEntity = data2.myOwner;
				result.myCollisionSide = GetCollisionSide(data1.myRect, data2.myRect);
				myCollisionEvents.Add(result);
			}
		}
	}
}

void CollisionComponentManager::OnEndFrame()
{
	for each (const CollisionEvent& event in myCollisionEvents)
	{
		myEventSystem.SendEvent(event);
	}

	myCollisionEvents.RemoveAll();
}

void CollisionComponentManager::Render()
{
}

unsigned int CollisionComponentManager::GetID()
{
	return eComponent::COLLISION_COMPONENT;
}

bool CollisionComponentManager::CanCollide(const CollisionData& aData1, const CollisionData& aData2) const
{
	if (aData1.myOwner == aData2.myOwner) return false;
	if ((aData1.myCollisionGroup & aData2.myCollisionFilter) > 0) return true;

	return false;
}

bool CollisionComponentManager::Collision(const CollisionData& aFirst, const CollisionData& aSecond) const
{
	if (aFirst.myRect.myMin.x > aSecond.myRect.myMax.x) return false;
	if (aFirst.myRect.myMin.y > aSecond.myRect.myMax.y) return false;

	if (aFirst.myRect.myMax.x < aSecond.myRect.myMin.x) return false;
	if (aFirst.myRect.myMax.y < aSecond.myRect.myMin.y) return false;


	eCollisionSide collisionSide = GetCollisionSide(aFirst.myRect, aSecond.myRect);

	switch (collisionSide)
	{
	case eCollisionSide::LEFT:
		if (aFirst.myVelocity.x < 0.f || aSecond.myVelocity.x > 0.f) return true;
		break;
	case eCollisionSide::RIGHT:
		if (aFirst.myVelocity.x > 0.f || aSecond.myVelocity.x < 0.f) return true;
		break;
	case eCollisionSide::TOP:
		if (aFirst.myVelocity.y < 0.f || aSecond.myVelocity.y > 0.f) return true;
		break;
	case eCollisionSide::BOTTOM:
		if (aFirst.myVelocity.y > 0.f || aSecond.myVelocity.y < 0.f) return true;
		break;

	}

	return false;
}

eCollisionSide CollisionComponentManager::GetCollisionSide(const Easy2D::Rect& aFirst, const Easy2D::Rect& aSecond) const
{
	if (abs(aFirst.myMin.x - aSecond.myMax.x) < 1.f) return eCollisionSide::LEFT;
	if (abs(aFirst.myMax.x - aSecond.myMin.x) < 1.f) return eCollisionSide::RIGHT;
	if (abs(aFirst.myMin.y - aSecond.myMax.y) < 1.f) return eCollisionSide::TOP;
	if (abs(aFirst.myMax.y - aSecond.myMin.y) < 1.f) return eCollisionSide::BOTTOM;

	return eCollisionSide::NONE;
}