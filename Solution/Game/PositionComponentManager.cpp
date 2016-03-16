#include "PositionComponentManager.h"
#include "Enums.h"

PositionComponentManager::PositionComponentManager(Easy2D::Engine& aEngine)
	: IComponentManager(aEngine)
	, myPositions(16)
{
}


PositionComponentManager::~PositionComponentManager()
{
}

void PositionComponentManager::Create(Entity aEntity, const CU::Vector2f& aStartPosition)
{
	myPositions.Add(aStartPosition);
	myLookup[aEntity] = myPositions.Size() - 1;
}

void PositionComponentManager::Update(float aDelta)
{
}

void PositionComponentManager::Render()
{
}

const CU::Vector2f& PositionComponentManager::GetPosition(Entity aEntity)
{
	return myPositions[myLookup[aEntity]];
}

void PositionComponentManager::SetPosition(Entity aEntity, const CU::Vector2f& aPosition)
{
	myPositions[myLookup[aEntity]] = aPosition;
}

unsigned int PositionComponentManager::GetID()
{
	return eComponent::POSITION;
}
