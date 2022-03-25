#include "stdafx.h"


MonsterDie2::MonsterDie2()
{
}


MonsterDie2::~MonsterDie2()
{
}

void MonsterDie2::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/MonsterDie2.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 65.f, 134.f);
	m_Sprite.SetImageSize(65.f, 134.f);
}

void MonsterDie2::Render()
{
	m_Sprite.SetColor(25, 25, 25, 255);
	m_Sprite.OnRender();
}

void MonsterDie2::Update(float deltatime)
{
	if (m_iFrame == -1)
	{
		m_fCount1 += deltatime;
		if (m_fCount1 >= 0.5f)
		{
			m_iFrame = 0;
			m_fCount1 = 0.f;
		}
	}
	else
	{
		Sprite(deltatime);
	}
}

void MonsterDie2::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(65.f * m_iFrame, 0.f, 65.f, 134.f);
		m_Sprite.SetImageSize(65.f, 134.f);
		m_iFrame++;

		if (m_iFrame >= 6)
		{
			m_Sprite.SetCustomVB();
			m_Sprite.SetImageUV(0.f, 0.f, 0.f, 0.f);
			m_Sprite.SetImageSize(0.f, 0.f);
			m_iFrame = -1;
		}
		m_fCount = 0.f;
	}
}
