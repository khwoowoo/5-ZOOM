#pragma once
enum EKEY_TYPE
{
	EKEY_NONE,
	EKEY_DOWN,
	EKEY_PRESS,
	EKEY_UP,
};
class KeyManager:public CSingleInstance<KeyManager>
{
	int KeyState[256];
	bool PrevKeyState[256];
public:
	Vector3 vMouse;
public:
	KeyManager();
	virtual ~KeyManager();

	void Update();
	INT GetKeyState(int nKey);
	void SetMousePos(int x, int y);
};

