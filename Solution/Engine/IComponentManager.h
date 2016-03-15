#pragma once

#include "Defines.h"

namespace Easy2D
{
	class Engine;
	class IComponentManager
	{
	public:
		virtual void Update(float) = 0;
		virtual void Render() = 0;
		virtual unsigned int GetID() = 0;

	protected:
		IComponentManager(Engine&){};
	};
}