#include "stdafx.h"


Item2Att::Item2Att()
{
}


Item2Att::~Item2Att()
{
}

void Item2Att::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/Item2Att.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 210.f, 210.f);
	m_Sprite.SetImageSize(210.f, 210.f);
}

void Item2Att::Render()
{
	m_Sprite.OnRender();
}

void Item2Att::Update(float deltatime)
{
	Sprite(deltatime);
}

bool Item2Att::CollisionTo(IObject * obj)
{
	if (m_iFrame >= 8)
	{
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
		return true;
	}
	return false;
}

void Item2Att::Sprite(float deltatime)
{
	m_fCount += deltatime;
	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(210.f * m_iFrame, 0.f, 210.f, 210.f);
		m_Sprite.SetImageSize(210.f, 210.f);
		m_iFrame++;
		m_fCount = 0.f;
	}
}
