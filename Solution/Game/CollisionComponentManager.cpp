#include "CollisionComponentManager.h"
#include "MovementComponentManager.h"
#include "Enums.h"
#include "PositionComponentManager.h"
#include <Engine.h>

CollisionComponentManager::CollisionComponentManager(Easy2D::Engine& aEngine)
	: IComponentManager(aEngine)
	, myMovementManager(static_cast<MovementComponentManager&>(aEngine.GetComponentManager(eComponent::MOVEMENT_COMPONENT)))
	, myPositionManager(static_cast<PositionComponentManager&>(aEngine.GetComponentManager(eComponent::POSITION_COMPONENT)))
	, myCollisionData(16)
	, myCollisionResults(16)
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

			if (CanCollide(data1, data2) == true && Collision(data1.myRect, data2.myRect) == true)
			{
				CollisionResult result;
				result.myFirst = data1.myOwner;
				result.mySecond = data2.myOwner;
				result.myCollisionSide = GetCollisionSide(data1.myRect, data2.myRect);
				myCollisionResults.Add(result);
			}
		}
	}
}

void CollisionComponentManager::OnEndFrame()
{
	for each (const CollisionResult& result in myCollisionResults)
	{
		int apa = 5;
	}
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

bool CollisionComponentManager::Collision(const Easy2D::Rect& aFirst, const Easy2D::Rect& aSecond) const
{
	if (aFirst.myMin.x > aSecond.myMax.x) return false;
	if (aFirst.myMin.y > aSecond.myMax.y) return false;

	if (aFirst.myMax.x < aSecond.myMin.x) return false;
	if (aFirst.myMax.y < aSecond.myMin.y) return false;

	return true;
}

Easy2D::eCollisionSide CollisionComponentManager::GetCollisionSide(const Easy2D::Rect& aFirst, const Easy2D::Rect& aSecond) const
{
	if (abs(aFirst.myMin.x - aSecond.myMax.x) < 1.f) return Easy2D::eCollisionSide::LEFT;
	if (abs(aFirst.myMax.x - aSecond.myMin.x) < 1.f) return Easy2D::eCollisionSide::RIGHT;
	if (abs(aFirst.myMin.y - aSecond.myMax.y) < 1.f) return Easy2D::eCollisionSide::TOP;
	if (abs(aFirst.myMax.y - aSecond.myMin.y) < 1.f) return Easy2D::eCollisionSide::TOP;

	return Easy2D::eCollisionSide::NONE;
}