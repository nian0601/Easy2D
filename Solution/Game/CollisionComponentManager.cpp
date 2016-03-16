#include "CollisionComponentManager.h"
#include "MovementComponentManager.h"
#include "Enums.h"
#include "PositionComponentManager.h"
#include <Engine.h>

CollisionComponentManager::CollisionComponentManager(Easy2D::Engine& aEngine)
	: IComponentManager(aEngine)
	, myMovementManager(static_cast<MovementComponentManager&>(aEngine.GetComponentManager(eComponent::MOVEMENT)))
	, myPositionManager(static_cast<PositionComponentManager&>(aEngine.GetComponentManager(eComponent::POSITION)))
	, myCollisionData(16)
{
}


CollisionComponentManager::~CollisionComponentManager()
{
}

void CollisionComponentManager::Create(Entity aOwner, float aRadius)
{
	CollisionData data;
	data.myOwner = aOwner;
	data.myRadius = aRadius;

	myCollisionData.Add(data);
	myLookup[aOwner] = myCollisionData.Size() - 1;
}

void CollisionComponentManager::Create(Entity aOwner, const Easy2D::Rect& aRect)
{
	CollisionData data;
	data.myOwner = aOwner;
	data.myRect = aRect;

	myCollisionData.Add(data);
	myLookup[aOwner] = myCollisionData.Size() - 1;
}

void CollisionComponentManager::Update(float)
{
	for (CollisionData& data : myCollisionData)
	{
		data.myPosition = &myPositionManager.GetPosition(data.myOwner);
		data.myRect.Update(*data.myPosition);
	}

	int size = myCollisionData.Size();
	for (int i = 0; i < size; ++i)
	{
		const CollisionData& data1 = myCollisionData[i];

		for (int j = i + 1; j < size; ++j)
		{
			const CollisionData& data2 = myCollisionData[j];

			//if (data1.myOwner != data2.myOwner && Collision(*data1.myPosition, data1.myRadius, *data2.myPosition, data2.myRadius) == true)
			if (data1.myOwner != data2.myOwner && Collision(data1.myRect, data2.myRect) == true)
			{
				//myMovementManager.Reflect(data1.myOwner);
				//myMovementManager.Reflect(data2.myOwner);

				myMovementManager.SetVelocity(data1.myOwner, CU::GetNormalized(*data1.myPosition - *data2.myPosition) * 200.f);
				myMovementManager.SetVelocity(data2.myOwner, CU::GetNormalized(*data2.myPosition - *data1.myPosition) * 200.f);
			}
		}
	}
}

void CollisionComponentManager::Render()
{
}

unsigned int CollisionComponentManager::GetID()
{
	return eComponent::COLLISION;
}

bool CollisionComponentManager::Collision(const CU::Vector2f& aFirstPos, float aFirstRadius, const CU::Vector2f& aSecondPos, float aSecondRadius) const
{
	return CU::Length2(aFirstPos - aSecondPos) < (aFirstRadius + aSecondRadius * aFirstRadius + aSecondRadius);
}

bool CollisionComponentManager::Collision(const Easy2D::Rect& aFirst, const Easy2D::Rect& aSecond) const
{
	if (aFirst.myMin.x > aSecond.myMax.x) return false;
	if (aFirst.myMin.y > aSecond.myMax.y) return false;

	if (aFirst.myMax.x < aSecond.myMin.x) return false;
	if (aFirst.myMax.y < aSecond.myMin.y) return false;

	return true;
}
