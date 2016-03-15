#include "stdafx.h"
#include <cassert>
#include "Input.h"
#include <SDL.h>
#include <SDL_scancode.h>

namespace Easy2D
{
	Input::Input()
	{
		for (int i = 0; i < SDL_NUM_SCANCODES; ++i)
		{
			myCurrentKeyStates[i] = false;
			myPreviousKeyStates[i] = false;
		}
	}
	
	
	Input::~Input()
	{
	}

	bool Input::KeyDown(eKey aKey) const
	{
		int sdlCode = GetSDLScanCode(aKey);
		return (myCurrentKeyStates[sdlCode] == true) && (myPreviousKeyStates[sdlCode] == false);
	}

	bool Input::KeyUp(eKey aKey) const
	{
		int sdlCode = GetSDLScanCode(aKey);
		return (myCurrentKeyStates[sdlCode] == false) && (myPreviousKeyStates[sdlCode] == true);
	}

	bool Input::KeyIsPressed(eKey aKey) const
	{
		int sdlCode = GetSDLScanCode(aKey);
		return myCurrentKeyStates[sdlCode] == true;
	}

	void Input::OnSDLKeyDown(int aKey)
	{
		myCurrentKeyStates[aKey] = true;
	}

	void Input::OnSDLKeyUp(int aKey)
	{
		myCurrentKeyStates[aKey] = false;
	}

	void Input::OnBeginFrame()
	{
		for (int i = 0; i < SDL_NUM_SCANCODES; ++i)
		{
			myPreviousKeyStates[i] = myCurrentKeyStates[i];
		}
	}

	int Input::GetSDLScanCode(eKey aKey) const
	{
		switch (aKey)
		{
		case Easy2D::eKey::_A: return SDL_SCANCODE_A; break;
		case Easy2D::eKey::_B: return SDL_SCANCODE_B; break;
		case Easy2D::eKey::_C: return SDL_SCANCODE_C; break;
		case Easy2D::eKey::_D: return SDL_SCANCODE_D; break;
		case Easy2D::eKey::_E: return SDL_SCANCODE_E; break;
		case Easy2D::eKey::_F: return SDL_SCANCODE_F; break;
		case Easy2D::eKey::_G: return SDL_SCANCODE_G; break;
		case Easy2D::eKey::_H: return SDL_SCANCODE_H; break;
		case Easy2D::eKey::_I: return SDL_SCANCODE_I; break;
		case Easy2D::eKey::_J: return SDL_SCANCODE_J; break;
		case Easy2D::eKey::_K: return SDL_SCANCODE_K; break;
		case Easy2D::eKey::_L: return SDL_SCANCODE_L; break;
		case Easy2D::eKey::_M: return SDL_SCANCODE_M; break;
		case Easy2D::eKey::_N: return SDL_SCANCODE_N; break;
		case Easy2D::eKey::_O: return SDL_SCANCODE_O; break;
		case Easy2D::eKey::_P: return SDL_SCANCODE_P; break;
		case Easy2D::eKey::_Q: return SDL_SCANCODE_Q; break;
		case Easy2D::eKey::_R: return SDL_SCANCODE_R; break;
		case Easy2D::eKey::_S: return SDL_SCANCODE_S; break;
		case Easy2D::eKey::_T: return SDL_SCANCODE_T; break;
		case Easy2D::eKey::_U: return SDL_SCANCODE_U; break;
		case Easy2D::eKey::_V: return SDL_SCANCODE_V; break;
		case Easy2D::eKey::_W: return SDL_SCANCODE_W; break;
		case Easy2D::eKey::_X: return SDL_SCANCODE_X; break;
		case Easy2D::eKey::_Y: return SDL_SCANCODE_Y; break;
		case Easy2D::eKey::_Z: return SDL_SCANCODE_Z; break;
		case Easy2D::eKey::_0: return SDL_SCANCODE_0; break;
		case Easy2D::eKey::_1: return SDL_SCANCODE_1; break;
		case Easy2D::eKey::_2: return SDL_SCANCODE_2; break;
		case Easy2D::eKey::_3: return SDL_SCANCODE_3; break;
		case Easy2D::eKey::_4: return SDL_SCANCODE_4; break;
		case Easy2D::eKey::_5: return SDL_SCANCODE_5; break;
		case Easy2D::eKey::_6: return SDL_SCANCODE_6; break;
		case Easy2D::eKey::_7: return SDL_SCANCODE_7; break;
		case Easy2D::eKey::_8: return SDL_SCANCODE_8; break;
		case Easy2D::eKey::_9: return SDL_SCANCODE_9; break;
		}

		assert(!"Invalid input key, convertion to SDLScanCode not implemented yet");
		return SDL_SCANCODE_A;
	}
}
