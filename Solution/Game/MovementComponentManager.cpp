#include "MovementComponentManager.h"
#include <Input.h>
#include <Vector2f.h>
#include "PositionComponentManager.h"
#include "Enums.h"
#include <Engine.h>

MovementComponentManager::MovementComponentManager(Easy2D::Engine& aEngine)
	: IComponentManager(aEngine)
	, myData(16)
	, myInput(aEngine.GetInput())
	, myPositionComponentManager(static_cast<PositionComponentManager&>(aEngine.GetComponentManager(eComponent::POSITION)))
{
}


MovementComponentManager::~MovementComponentManager()
{
}

void MovementComponentManager::Create(Entity aEntity, Easy2D::eKey aUpKey, Easy2D::eKey aDownKey, Easy2D::eKey aLeftKey, Easy2D::eKey aRightKey)
{
	MovementData data;
	data.myOwner = aEntity;
	data.myUpKey = aUpKey;
	data.myDownKey = aDownKey;
	data.myLeftKey = aLeftKey;
	data.myRightKey = aRightKey;

	myData.Add(data);
	myLookup[aEntity] = myData.Size() - 1;
}

void MovementComponentManager::Update(float aDelta)
{
	for (MovementData& data : myData)
	{
		CU::Vector2f pos = myPositionComponentManager.GetPosition(data.myOwner);
		
		if (myInput.KeyIsPressed(data.myUpKey))
		{
			pos.y -= 10.f * aDelta;
		}
		else if (myInput.KeyIsPressed(data.myDownKey))
		{
			pos.y += 10.f * aDelta;
		}
		else if (myInput.KeyIsPressed(data.myLeftKey))
		{
			pos.x -= 10.f * aDelta;
		}
		else if (myInput.KeyIsPressed(data.myRightKey))
		{
			pos.x += 10.f * aDelta;
		}

		myPositionComponentManager.SetPosition(data.myOwner, pos);
	}
}

void MovementComponentManager::Render()
{
}

unsigned int MovementComponentManager::GetID()
{
	return eComponent::MOVEMENT;
}

