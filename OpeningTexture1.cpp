#include "stdafx.h"


OpeningTexture1::OpeningTexture1()
{
}


OpeningTexture1::~OpeningTexture1()
{
}

void OpeningTexture1::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/intro1.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 920.f, 731.f);
	m_Sprite.SetImageSize(920.f, 731.f);
}

void OpeningTexture1::Render()
{
	m_Sprite.OnRender();
}

void OpeningTexture1::Update(float deltatime)
{
	m_Sprite.m_Position.x += deltatime * 500.f * m_iMove;

	if (m_Sprite.m_Position.x > 510.f)
	{
		m_Sprite.m_Position.x = 510.f;
	}

	Sprite(deltatime);
}

void OpeningTexture1::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(920.f * m_iFrame, 0.f, 920.f, 731.f);
		m_Sprite.SetImageSize(920.f, 731.f);
		m_iFrame++;

		if (m_iFrame >= 4)
		{
			m_iFrame = 0;
		}
		m_fCount = 0.f;
	}
}
