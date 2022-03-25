#include "stdafx.h"


Item3::Item3()
{
}


Item3::~Item3()
{
}

void Item3::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/Item3.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 99.f, 86.f);
	m_Sprite.SetImageSize(99.f, 86.f);
}

void Item3::Render()
{
	m_Sprite.OnRender();
}

void Item3::Update(float deltatime)
{
	Vector3 temp = m_Sprite.m_Position - m_GetAiPos;
	m_Sprite.m_Position -= temp * deltatime * 5;
	Sprite(deltatime);
}

bool Item3::CollisionTo(IObject * obj)
{
	if (obj->Tag == "PlayerMap")
	{
		if (m_GetAiPos.x < m_Sprite.m_Position.x + 50)
		{
			PlayerAttBoom * m_pPlayerAttBoom = new PlayerAttBoom;
			m_pPlayerAttBoom->m_bAi = false;
			m_pPlayerAttBoom->Init();
			m_pPlayerAttBoom->m_Sprite.m_Position = m_GetAiPos;
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayerAttBoom);

			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
			return true;
		}
	}
	return false;
}

void Item3::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(99.f * m_iFrame, 0.f, 99.f, 86.f);
		m_Sprite.SetImageSize(99.f, 86.f);
		m_iFrame++;

		if (m_iFrame >= 5)
		{
			m_iFrame = 0;
		}
		m_fCount = 0.f;
	}
}
