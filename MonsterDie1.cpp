#include "stdafx.h"


MonsterDie1::MonsterDie1()
{
}


MonsterDie1::~MonsterDie1()
{
}

void MonsterDie1::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/MonsterDie1.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 61.f, 70.f);
	m_Sprite.SetImageSize(61.f, 70.f);
}

void MonsterDie1::Render()
{
	m_Sprite.SetColor(25, 25, 25, 255);
	m_Sprite.OnRender();
}

void MonsterDie1::Update(float deltatime)
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

void MonsterDie1::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(61.f * m_iFrame, 0.f, 61.f, 70.f);
		m_Sprite.SetImageSize(61.f, 70.f);
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
