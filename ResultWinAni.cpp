#include "stdafx.h"


ResultWinAni::ResultWinAni()
{
}


ResultWinAni::~ResultWinAni()
{
}

void ResultWinAni::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/ResultWinAni.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 533.f, 483.f);
	m_Sprite.SetImageSize(533.f, 483.f);
}

void ResultWinAni::Render()
{
	m_Sprite.OnRender();
}

void ResultWinAni::Update(float deltatime)
{
	Sprite(deltatime);
}

void ResultWinAni::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(533.f * m_iFrame, 0.f, 533.f, 483.f);
		m_Sprite.SetImageSize(533.f, 483.f);
		m_iFrame++;

		if (m_iFrame >= 10)
		{
			m_iFrame = 0;
		}
		m_fCount = 0.f;
	}
}
