#pragma once

#include "Enums.h"

class ISystem
{
public:
	//virtual void Create(unsigned int) = 0;
	virtual void Update(float) = 0;
	virtual void Render() = 0;
	virtual eComponent GetType() = 0;
};