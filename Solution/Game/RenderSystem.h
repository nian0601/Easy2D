#pragma once

#include "ISystem.h"
#include <unordered_map>
#include <string>
#include <GrowingArray.h>

namespace Easy2D
{
	class ResourceManager;
	class Sprite;
}

class RenderSystem : public ISystem
{
public:
	RenderSystem();
	~RenderSystem();

	void Create(unsigned int aEntityID, const std::string& aPath, Easy2D::ResourceManager& aResourceManager);
	void Update(float aDelta) override;
	void Render() override;

	eComponent GetType() override;

private:
	std::unordered_map<unsigned int, int> myLookup;
	CU::GrowingArray<Easy2D::Sprite*> mySprites;
};

