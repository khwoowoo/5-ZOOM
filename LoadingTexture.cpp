#include "stdafx.h"


LoadingTexture::LoadingTexture()
{
}


LoadingTexture::~LoadingTexture()
{
}

void LoadingTexture::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/LoadingTexture.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 1098.f, 221.f);
	m_Sprite.SetImageSize(1098.f, 221.f);
}

void LoadingTexture::Render()
{
	m_Sprite.OnRender();
}

void LoadingTexture::Update(float deltatime)
{
	Sprite(deltatime);
}

void LoadingTexture::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.4f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(1098.f * m_iFrame, 0.f, 1098.f, 221.f);
		m_Sprite.SetImageSize(1098.f, 221.f);
		m_iFrame++;

		if (m_iFrame >= 3)
		{
			m_iFrame = 0;
		}
		m_fCount = 0.f;
	}
}
