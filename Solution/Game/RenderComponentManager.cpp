#include "RenderComponentManager.h"
#include "PositionComponentManager.h"
#include <ResourceManager.h>
#include <Sprite.h>
#include "Enums.h"
#include <Engine.h>

RenderComponentManager::RenderComponentManager(Easy2D::Engine& aEngine)
	: IComponentManager(aEngine)
	, myData(16)
	, myPositionComponentManager(static_cast<PositionComponentManager&>(aEngine.GetComponentManager(eComponent::POSITION)))
{
}


RenderComponentManager::~RenderComponentManager()
{
}

void RenderComponentManager::Create(Entity aEntity, const std::string& aPath, Easy2D::ResourceManager& aResourceManager)
{
	RenderData data;
	data.myOwner = aEntity;
	data.mySprite = aResourceManager.GetSprite(aPath);
	myData.Add(data);
	myLookup[aEntity] = myData.Size() - 1;
}

void RenderComponentManager::Update(float aDelta)
{
	aDelta;
}

void RenderComponentManager::Render()
{
	for each (const RenderData& data in myData)
	{
		const CU::Vector2f& pos = myPositionComponentManager.GetPosition(data.myOwner);
		data.mySprite->Render(pos);
	}
}

unsigned int RenderComponentManager::GetID()
{
	return eComponent::POSITION;
}