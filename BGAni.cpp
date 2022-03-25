#include "stdafx.h"


BGAni::BGAni()
{
}


BGAni::~BGAni()
{
}

void BGAni::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/BGAni.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 875.f, 176.f);
	m_Sprite.SetImageSize(875.f, 176.f);
}

void BGAni::Render()
{
	m_Sprite.OnRender();
}

void BGAni::Update(float deltatime)
{
	//if (m_iFrame == -1)
	//{
	//	m_fCount1 += deltatime;
	//	if (m_fCount1 >= 0.5f)
	//	{
	//		m_iFrame = 0;
	//		m_fCount1 = 0.f;
	//	}
	//}
	//else
	//{
	//	Sprite(deltatime);
	//}
	Sprite(deltatime);
}

void BGAni::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(875.f * m_iFrame ,0.f, 875.f, 176.f);
		m_Sprite.SetImageSize(875.f, 176.f);
		m_iFrame++;

		if (m_iFrame >= 4)
		{
			m_iFrame = 0;
		}
		m_fCount = 0.f;
	}
}
