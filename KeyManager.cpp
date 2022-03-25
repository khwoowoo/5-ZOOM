#include "stdafx.h"


KeyManager::KeyManager()
{
}


KeyManager::~KeyManager()
{
}

void KeyManager::Update()
{
	bool CurKeyState[256];

	for (int i = 0; i < 256; ++i)
	{
		CurKeyState[i] = GetAsyncKeyState(i) & 0x8000;

		bool curkey = CurKeyState[i];
		bool prevkey = PrevKeyState[i];

		if (prevkey == false && curkey == false) KeyState[i] = EKEY_NONE;
		else if (prevkey == false && curkey == true) KeyState[i] = EKEY_DOWN;
		else if (prevkey == true && curkey == true) KeyState[i] = EKEY_PRESS;
		else if (prevkey == true && curkey == false) KeyState[i] = EKEY_UP;

		PrevKeyState[i] = CurKeyState[i];
	}
}

INT KeyManager::GetKeyState(int nKey)
{
	return KeyState[nKey];
}

void KeyManager::SetMousePos(int x, int y)
{
	vMouse = Vector3((float)x, (float)y, 0.f);
}
