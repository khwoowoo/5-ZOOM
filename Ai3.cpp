#include "stdafx.h"


Ai3::Ai3()
{
}


Ai3::~Ai3()
{
}

void Ai3::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/Ai3.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 82.f, 195.f);
	m_Sprite.SetImageSize(82.f, 195.f);
}

void Ai3::Render()
{
	m_Sprite.OnRender();
}

void Ai3::Update(float deltatime)
{
	Sprite(deltatime);
}

void Ai3::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(82.f * m_iFrame, 0.f, 82.f, 195.f);
		m_Sprite.SetImageSize(82.f, 195.f);
		m_iFrame++;

		if (m_iFrame >= 4)
		{
			m_iFrame = 0;
		}
		m_fCount = 0.f;
	}
}
