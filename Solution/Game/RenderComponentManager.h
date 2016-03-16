#pragma once

#include <IComponentManager.h>
#include <string>
#include <GrowingArray.h>
#include <StaticArray.h>

namespace Easy2D
{
	class ResourceManager;
	class Sprite;
}

class PositionComponentManager;
class RenderComponentManager : public Easy2D::IComponentManager
{
public:
	RenderComponentManager(Easy2D::Engine& aEngine);
	~RenderComponentManager();

	void Create(Entity aEntity, const std::string& aPath, Easy2D::ResourceManager& aResourceManager);
	void Update(float aDelta) override;
	void Render() override;
	unsigned int GetID() override;

private:
	RenderComponentManager(RenderComponentManager&) = delete;
	void operator=(RenderComponentManager&) = delete;

	struct RenderData
	{
		Entity myOwner;
		Easy2D::Sprite* mySprite;
	};

	CU::GrowingArray<RenderData> myData;
	PositionComponentManager& myPositionComponentManager;
};

