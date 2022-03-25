#include "stdafx.h"


OpeningTexture2::OpeningTexture2()
{
}


OpeningTexture2::~OpeningTexture2()
{
}

void OpeningTexture2::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/intro2.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 1847.f, 265.f);
	m_Sprite.SetImageSize(1847.f, 265.f);
}

void OpeningTexture2::Render()
{
	m_Sprite.OnRender();
}

void OpeningTexture2::Update(float deltatime)
{
	m_Sprite.m_Position.y += deltatime * 500.f * m_iMove;

	if (m_Sprite.m_Position.y > 165.f)
	{
		m_Sprite.m_Position.y = 165.f;
	}
}
