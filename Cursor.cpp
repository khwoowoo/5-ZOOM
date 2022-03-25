#include "stdafx.h"


Cursor::Cursor()
{
}


Cursor::~Cursor()
{
}

void Cursor::Init()
{
	m_Sprite.m_Posset = Vector2(0.f, 0.f);
	m_Sprite.LoadTextureFromFile("Texture/Cusrsor.png");
}

void Cursor::Render()
{
	m_Sprite.OnRender();
}

void Cursor::Update(float deltatime)
{
	Vector3 vPoint = KeyManager::GetInstance()->vMouse;
	m_Sprite.m_Position = vPoint;
}
