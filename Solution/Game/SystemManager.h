#pragma once

#include "Enums.h"
#include <StaticArray.h>

class ISystem;
class RenderSystem;
class SystemManager
{
public:
	SystemManager();
	~SystemManager();

	unsigned int Create();
	void Update(float aDelta);
	void Render();

	RenderSystem* GetRenderSystem();

private:
	CU::StaticArray<ISystem*, eComponent::__COUNT> mySystems;
	unsigned int myNextEntityID;
};