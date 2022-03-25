#include "stdafx.h"

ResultLoseAni::ResultLoseAni()
{
}


ResultLoseAni::~ResultLoseAni()
{
}

void ResultLoseAni::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/ResultLoseAni.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 533.f, 415.f);
	m_Sprite.SetImageSize(533.f, 415.f);
}

void ResultLoseAni::Render()
{
	m_Sprite.OnRender();
}

void ResultLoseAni::Update(float deltatime)
{
	Sprite(deltatime);
}

void ResultLoseAni::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(533.f * m_iFrame, 0.f, 533.f, 415.f);
		m_Sprite.SetImageSize(533.f, 415.f);
		m_iFrame++;

		if (m_iFrame >= 6)
		{
			m_iFrame = 0;
		}
		m_fCount = 0.f;
	}
}
