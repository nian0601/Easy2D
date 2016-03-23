#pragma once
#include <IComponentManager.h>
#include <IEventSubscriber.h>
#include <GameEnums.h>
#include <GrowingArray.h>
#include <Vector2f.h>
#include <StaticArray.h>

namespace Easy2D
{
	class Input;
}

class PositionComponentManager;
class MovementComponentManager : public Easy2D::IComponentManager, public IEventSubscriber
{
public:
	MovementComponentManager(Easy2D::Engine& aEngine);
	~MovementComponentManager();

	void Create(Entity aEntity, const CU::Vector2f& aStartVelocity);

	void OnBeginFrame() override;
	void Update(float) override;
	void OnEndFrame() override;
	void Render() override;
	unsigned int GetID() override;

	void SetVelocity(Entity aEntity, const CU::Vector2f& aVelocity);
	CU::Vector2f GetVelocity(Entity aEntity) const;

	void OnEvent(const CollisionEvent& aEvent);

private:
	MovementComponentManager(MovementComponentManager&) = delete;
	void operator=(MovementComponentManager&) = delete;

	bool Outside(float aObjectPos, float aMinPos, float aMaxPos) const;
	void Reflect(Entity aEntity, eCollisionSide aCollisionSide);
	eCollisionSide OppositeCollision(eCollisionSide aCollisionSide) const;

	struct MovementData
	{
		Entity myOwner;
		CU::Vector2f myVelocity;
		CU::Vector2f myPosition;
	};

	CU::GrowingArray<MovementData> myData;
	CU::StaticArray<int, MAX_ENTITY_COUNT> myLookup;
	const Easy2D::Input& myInput;
	PositionComponentManager& myPositionComponentManager;
	const CU::Vector2f& myWindowSize;
};

