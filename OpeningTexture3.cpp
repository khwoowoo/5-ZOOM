#include "stdafx.h"


OpeningTexture3::OpeningTexture3()
{
}


OpeningTexture3::~OpeningTexture3()
{
}

void OpeningTexture3::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/intro3.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 920.f, 735.f);
	m_Sprite.SetImageSize(920.f, 735.f);
}

void OpeningTexture3::Render()
{
	m_Sprite.OnRender();
}

void OpeningTexture3::Update(float deltatime)
{
	m_Sprite.m_Position.y -= deltatime * 500.f * m_iMove;

	if (m_Sprite.m_Position.y < 694.f)
	{
		m_Sprite.m_Position.y = 694.f;
	}
}
