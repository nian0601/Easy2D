#pragma once

#include <IComponentManager.h>
#include <GrowingArray.h>
#include <StaticArray.h>

#include <Rect.h>

class PositionComponentManager;
class MovementComponentManager;
class CollisionComponentManager : public Easy2D::IComponentManager
{
public:
	CollisionComponentManager(Easy2D::Engine& aEngine);
	~CollisionComponentManager();

	void Create(Entity aOwner, float aRadius);
	void Create(Entity aOwner, const Easy2D::Rect& aRect);

	void Update(float) override;
	void Render() override;
	unsigned int GetID() override;

private:
	CollisionComponentManager(CollisionComponentManager&) = delete;
	void operator=(CollisionComponentManager&) = delete;

	bool Collision(const CU::Vector2f& aFirstPos, float aFirstRadius, const CU::Vector2f& aSecondPos, float aSecondRadius) const;
	bool Collision(const Easy2D::Rect& aFirst, const Easy2D::Rect& aSecond) const;

	struct CollisionData
	{
		Entity myOwner;
		float myRadius;
		const CU::Vector2f* myPosition;
		Easy2D::Rect myRect;
	};

	CU::StaticArray<int, MAX_ENTITY_COUNT> myLookup;
	CU::GrowingArray<CollisionData> myCollisionData;

	PositionComponentManager& myPositionManager;
	MovementComponentManager& myMovementManager;
};

