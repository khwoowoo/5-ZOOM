#include "stdafx.h"

Whale::Whale()
{
}


Whale::~Whale()
{
}

void Whale::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/Whale.png");
}

void Whale::Render()
{
	m_Sprite.OnRender();
}

void Whale::Update(float deltatime)
{
	m_Sprite.m_Position.x += deltatime * 500.f;

	if (m_Sprite.m_Position.x >= 1716.f)
	{
		m_Sprite.m_Position.x = 1716.f;
	}
}
