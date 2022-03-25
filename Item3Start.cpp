#include "stdafx.h"


Item3Start::Item3Start()
{
}


Item3Start::~Item3Start()
{
}

void Item3Start::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/Item3Start.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 73.f, 73.f);
	m_Sprite.SetImageSize(73.f, 73.f);
}

void Item3Start::Render()
{
	m_Sprite.OnRender();
}

void Item3Start::Update(float deltatime)
{
	Sprite(deltatime);
}

bool Item3Start::CollisionTo(IObject * obj)
{
	if (obj->Tag == "PlayerMap")
	{
		if (m_iFrame >= 5)
		{
			m_iFrame = 0;
			Camera::GetInstance()->m_iAtt = 0;
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
			return true;
		}
	}
	return false;
}

void Item3Start::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		Camera::GetInstance()->m_iAtt = 1;
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(73.f * m_iFrame, 0.f, 73.f, 73.f);
		m_Sprite.SetImageSize(73.f, 73.f);
		m_iFrame++;
		m_fCount = 0.f;
	}
}
