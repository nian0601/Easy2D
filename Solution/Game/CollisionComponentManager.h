#pragma once

#include <IComponentManager.h>
#include <GrowingArray.h>
#include <StaticArray.h>

#include <Rect.h>
#include <Easy2DEnums.h>

class PositionComponentManager;
class MovementComponentManager;
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
	};

	struct CollisionResult
	{
		Entity myFirst;
		Entity mySecond;
		Easy2D::eCollisionSide myCollisionSide;
	};

	bool CanCollide(const CollisionData& aData1, const CollisionData& aData2) const;
	bool Collision(const Easy2D::Rect& aFirst, const Easy2D::Rect& aSecond) const;
	Easy2D::eCollisionSide GetCollisionSide(const Easy2D::Rect& aFirst, const Easy2D::Rect& aSecond) const;

	


	CU::StaticArray<int, MAX_ENTITY_COUNT> myLookup;
	CU::GrowingArray<CollisionData> myCollisionData;
	CU::GrowingArray<CollisionResult> myCollisionResults;

	PositionComponentManager& myPositionManager;
	MovementComponentManager& myMovementManager;
};

