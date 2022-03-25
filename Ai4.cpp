#include "stdafx.h"

Ai4::Ai4()
{
}


Ai4::~Ai4()
{
}

void Ai4::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/Ai4.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 130.f, 142.f);
	m_Sprite.SetImageSize(130.f, 142.f);
}

void Ai4::Render()
{
	m_Sprite.OnRender();
}

void Ai4::Update(float deltatime)
{
	Sprite(deltatime);
}

void Ai4::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(130.f * m_iFrame, 0.f, 130.f, 142.f);
		m_Sprite.SetImageSize(130.f, 142.f);
		m_iFrame++;

		if (m_iFrame >= 4)
		{
			m_iFrame = 0;
		}
		m_fCount = 0.f;
	}
}
