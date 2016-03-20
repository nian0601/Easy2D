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

	void OnBeginFrame() override;
	void Update(float) override;
	void OnEndFrame() override;
	void Render() override;
	unsigned int GetID() override;

	void SetVelocity(Entity aEntity, const CU::Vector2f& aVelocity);

private:
	MovementComponentManager(MovementComponentManager&) = delete;
	void operator=(MovementComponentManager&) = delete;

	bool Outside(float aObjectPos, float aMinPos, float aMaxPos) const;

	struct MovementData
	{
		Entity myOwner;
		CU::Vector2f myVelocity;
		CU::Vector2f myPosition;
	};

	CU::GrowingArray<MovementData> myData;
	const Easy2D::Input& myInput;
	PositionComponentManager& myPositionComponentManager;
	const CU::Vector2f& myWindowSize;
};

