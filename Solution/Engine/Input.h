#pragma once

#include "Easy2DEnums.h"

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

	private:
		int GetSDLScanCode(eKey aKey) const;

		bool myCurrentKeyStates[512];
		bool myPreviousKeyStates[512];
	};
}

