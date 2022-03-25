#include "stdafx.h"

Ai2::Ai2()
{
}


Ai2::~Ai2()
{
}

void Ai2::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/Ai2.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 73.f, 131.f);
	m_Sprite.SetImageSize(73.f, 131.f);
}

void Ai2::Render()
{
	m_Sprite.OnRender();
}

void Ai2::Update(float deltatime)
{
	Sprite(deltatime);
}

void Ai2::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(73.f * m_iFrame, 0.f, 73.f, 131.f);
		m_Sprite.SetImageSize(73.f, 131.f);
		m_iFrame++;

		if (m_iFrame >= 4)
		{
			m_iFrame = 0;
		}
		m_fCount = 0.f;
	}
}
