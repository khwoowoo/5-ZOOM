#include "stdafx.h"


Item2::Item2()
{
}


Item2::~Item2()
{
}

void Item2::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/Item2.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 92.f, 202.f);
	m_Sprite.SetImageSize(92.f, 202.f);
}

void Item2::Render()
{
	m_Sprite.OnRender();
}

void Item2::Update(float deltatime)
{
	if (m_Sprite.m_Position.y < 950.f)
		m_Sprite.m_Position.y = 950.f;
	else
		m_Sprite.m_Position.y -= 300.f * deltatime;

	Sprite(deltatime);

	if (m_pGameStart->m_bItem2 == false)
	{
		m_Sprite.m_Rotate.z += 300.f * deltatime;
		m_Sprite.m_Position.y += 300.f * deltatime;
		if (m_Sprite.m_Rotate.z >= 180.f)
		{
			m_Sprite.m_Rotate.z = 180.f;
			m_Sprite.m_Position.y += 300.f * deltatime;
			
		}
	}
}

bool Item2::CollisionTo(IObject * obj)
{
	if (m_Sprite.m_Position.y >= 1080.f + 202.f * 2)
	{
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
		return true;
	}
	return false;
}

void Item2::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(92.f * m_iFrame, 0.f, 92.f, 202.f);
		m_Sprite.SetImageSize(92.f, 202.f);
		m_iFrame++;

		if (m_iFrame >= 4)
		{
			m_iFrame = 0;
		}
		m_fCount = 0.f;
	}
}
