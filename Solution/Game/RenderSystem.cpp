#include "RenderSystem.h"
#include <ResourceManager.h>
#include <Sprite.h>
RenderSystem::RenderSystem()
	: mySprites(16)
{
}


RenderSystem::~RenderSystem()
{
}

void RenderSystem::Create(unsigned int aEntityID, const std::string& aPath, Easy2D::ResourceManager& aResourceManager)
{
	mySprites.Add(aResourceManager.GetSprite(aPath));
	myLookup[aEntityID] = mySprites.Size() - 1;
}

void RenderSystem::Update(float aDelta)
{
	aDelta;
}

void RenderSystem::Render()
{
	CU::Vector2f pos(300.f, 300.f);
	for each (Easy2D::Sprite* sprite in mySprites)
	{
		sprite->Render(pos);

		pos.x += 150.f;
	}
}

eComponent RenderSystem::GetType()
{
	return eComponent::RENDER;
}
