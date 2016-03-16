#pragma once
#include <IComponentManager.h>
#include <Easy2DEnums.h>
#include <GrowingArray.h>
#include <Vector2f.h>

namespace Easy2D
{
	class Input;
}

class PositionComponentManager;
class MovementComponentManager : public Easy2D::IComponentManager
{
public:
	MovementComponentManager(Easy2D::Engine& aEngine);
	~MovementComponentManager();

	void Create(Entity aEntity, const CU::Vector2f& aStartVelocity);
	void Update(float) override;
	void Render() override;
	unsigned int GetID() override;

	void Reflect(Entity aEntity);
	void SetVelocity(Entity aEntity, const CU::Vector2f& aVelocity);

private:
	MovementComponentManager(MovementComponentManager&) = delete;
	void operator=(MovementComponentManager&) = delete;

	bool Outside(float aObjectPos, float aMinPos, float aMaxPos) const;

	struct MovementData
	{
		Entity myOwner;
		CU::Vector2f myVelocity;
	};

	CU::GrowingArray<MovementData> myData;
	const Easy2D::Input& myInput;
	PositionComponentManager& myPositionComponentManager;
	const CU::Vector2f& myWindowSize;
};

