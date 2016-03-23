#pragma once

#include <CollisionEvent.h>
#include <IComponentManager.h>
#include <GrowingArray.h>
#include <StaticArray.h>

#include <Rect.h>
#include <GameEnums.h>


class PositionComponentManager;
class MovementComponentManager;
class EventSystem;
class CollisionComponentManager : public Easy2D::IComponentManager
{
public:
	CollisionComponentManager(Easy2D::Engine& aEngine);
	~CollisionComponentManager();

	void Create(Entity aOwner, const Easy2D::Rect& aRect, unsigned int aCollisionGroup, unsigned int aCollisionFilter);

	void OnBeginFrame() override;
	void Update(float) override;
	void OnEndFrame() override;
	void Render() override;
	unsigned int GetID() override;

private:
	CollisionComponentManager(CollisionComponentManager&) = delete;
	void operator=(CollisionComponentManager&) = delete;

	struct CollisionData
	{
		Entity myOwner;
		Easy2D::Rect myRect;
		unsigned int myCollisionGroup;
		unsigned int myCollisionFilter;
		CU::Vector2f myVelocity;
	};

	bool CanCollide(const CollisionData& aData1, const CollisionData& aData2) const;
	bool Collision(const CollisionData& aFirst, const CollisionData& aSecond) const;
	eCollisionSide GetCollisionSide(const Easy2D::Rect& aFirst, const Easy2D::Rect& aSecond) const;


	CU::StaticArray<int, MAX_ENTITY_COUNT> myLookup;
	CU::GrowingArray<CollisionData> myCollisionData;
	CU::GrowingArray<CollisionEvent> myCollisionEvents;

	PositionComponentManager& myPositionManager;
	MovementComponentManager& myMovementManager;
	EventSystem& myEventSystem;
};

