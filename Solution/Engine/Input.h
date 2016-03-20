#pragma once

#include "Easy2DEnums.h"
#include <Vector2f.h>
#include <Vector2i.h>
namespace Easy2D
{
	class Input
	{
	public:
		Input();
		~Input();

		bool KeyDown(eKey aKey) const;
		bool KeyUp(eKey aKey) const;
		bool KeyIsPressed(eKey aKey) const;

		void OnSDLKeyDown(int aKey);
		void OnSDLKeyUp(int aKey);
		void OnBeginFrame();
	
		const CU::Vector2f& GetMousePosition() const;
	private:
		int GetSDLScanCode(eKey aKey) const;

		bool myCurrentKeyStates[512];
		bool myPreviousKeyStates[512];

		CU::Vector2f myMousePosition;
		CU::Vector2i myIntMousePosition;
	};

	inline const CU::Vector2f& Input::GetMousePosition() const
	{
		return myMousePosition;
	}
}

