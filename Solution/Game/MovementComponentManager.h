#pragma once
#include <IComponentManager.h>
#include <Easy2DEnums.h>
#include <GrowingArray.h>
#include <unordered_map>
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

	void Create(Entity aEntity, const CU::Vector2f& aStartVelocity/*, Easy2D::eKey aUpKey, Easy2D::eKey aDownKey, Easy2D::eKey aLeftKey, Easy2D::eKey aRightKey*/);
	void Update(float) override;
	void Render() override;
	unsigned int GetID() override;

private:
	MovementComponentManager(MovementComponentManager&) = delete;
	void operator=(MovementComponentManager&) = delete;

	bool Outside(float aObjectPos, float aMinPos, float aMaxPos) const;

	struct MovementData
	{
		Entity myOwner;
		Easy2D::eKey myUpKey;
		Easy2D::eKey myDownKey;
		Easy2D::eKey myLeftKey;
		Easy2D::eKey myRightKey;
		CU::Vector2f myVelocity;
	};

	std::unordered_map<Entity, int> myLookup;
	CU::GrowingArray<MovementData> myData;
	const Easy2D::Input& myInput;
	PositionComponentManager& myPositionComponentManager;
	const CU::Vector2f& myWindowSize;
};

