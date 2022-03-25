#include "stdafx.h"


OpeningBG::OpeningBG()
{
}


OpeningBG::~OpeningBG()
{
}

void OpeningBG::Init()
{
	m_Sprite.m_Posset = Vector2(0.f, 0.f);
	m_Sprite.LoadTextureFromFile("Texture/OpeningBG.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 1920.f, 1080.f);
	m_Sprite.SetImageSize(1920.f, 1080.f);
}

void OpeningBG::Render()
{
	m_Sprite.OnRender();
}

void OpeningBG::Update(float deltatime)
{
	Sprite(deltatime);
}

void OpeningBG::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(1920.f * m_iFrame, 0.f, 1920.f, 1080.f);
		m_Sprite.SetImageSize(1920.f, 1080.f);
		m_iFrame++;

		if (m_iFrame >= 4)
		{
			m_iFrame = 0;
		}
		m_fCount = 0.f;
	}
}
