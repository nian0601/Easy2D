#pragma once
#include <Vector2f.h>

namespace Easy2D
{
	struct Rect
	{
		Rect(){}
		Rect(const CU::Vector2f& aSize)
			: myExtents(aSize)
		{}

		void Update(const CU::Vector2f& aCenter)
		{
			myMin = aCenter - myExtents / 2.f;
			myMax = aCenter + myExtents / 2.f;
			myCenter = aCenter;
		}

		CU::Vector2f myMin;
		CU::Vector2f myMax;
		CU::Vector2f myExtents;
		CU::Vector2f myCenter;
	};
}