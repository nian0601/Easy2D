#pragma once
#include <IComponentManager.h>
#include <GrowingArray.h>
#include <StaticArray.h>
#include <Vector2f.h>

namespace Easy2D
{
	class Input;
}

class PositionComponentManager;
class PaddleComponentManager : public Easy2D::IComponentManager
{
public:
	PaddleComponentManager(Easy2D::Engine& aEngine);
	~PaddleComponentManager();

	void Create(Entity aEntity);
	void OnBeginFrame() override;
	void OnEndFrame() override;
	void Update(float) override;
	void Render() override;
	unsigned int GetID() override;

private:
	const Easy2D::Input& myInput;

	struct PaddleData
	{
		Entity myOwner;
		CU::Vector2f myPosition;
	};

	CU::GrowingArray<PaddleData> myData;
	PositionComponentManager& myPositionManager;
};

