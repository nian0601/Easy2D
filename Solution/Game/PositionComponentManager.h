#pragma once

#include <Vector2f.h>
#include <unordered_map>
#include <IComponentManager.h>
#include <GrowingArray.h>

class PositionComponentManager : public Easy2D::IComponentManager
{
public:
	PositionComponentManager(Easy2D::Engine& aEngine);
	~PositionComponentManager();

	void Create(Entity aEntity, const CU::Vector2f& aStartPosition);
	void Update(float) override;
	void Render() override;
	unsigned int GetID() override;

	const CU::Vector2f& GetPosition(Entity aEntity);
	void SetPosition(Entity aEntity, const CU::Vector2f& aPosition);

private:
	PositionComponentManager(PositionComponentManager&) = delete;
	void operator=(PositionComponentManager&) = delete;

	std::unordered_map<Entity, int> myLookup;
	CU::GrowingArray<CU::Vector2f> myPositions;
};
