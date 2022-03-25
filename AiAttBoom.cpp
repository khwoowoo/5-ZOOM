#include "stdafx.h"


AiAttBoom::AiAttBoom()
{
}


AiAttBoom::~AiAttBoom()
{
}

void AiAttBoom::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/AiAttBoom.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 72.f, 72.f);
	m_Sprite.SetImageSize(72.f, 72.f);
}

void AiAttBoom::Render()
{
	m_Sprite.OnRender();
}

void AiAttBoom::Update(float deltatime)
{
	Sprite(deltatime);
}

bool AiAttBoom::CollisionTo(IObject * obj)
{
	if (obj->Tag == "AiMap")
	{
		if (m_iFrame >= 5)
		{
			m_iFrame = 0;
			Camera::GetInstance()->m_iAtt = 0;

			if (m_bAi == true)
			{
				DestoryTile * m_pDestoryTile = new DestoryTile;
				int num = rand() % 2 + 0;
				if (num == 1)
					m_pDestoryTile->m_Sprite.LoadTextureFromFile("Texture/PlayerMap1.png");
				else
					m_pDestoryTile->m_Sprite.LoadTextureFromFile("Texture/PlayerMap2.png");
				m_pDestoryTile->m_Sprite.m_Position = m_Sprite.m_Position;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pDestoryTile);
			}
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
			return true;
		}
	}
	return false;
}

void AiAttBoom::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		Camera::GetInstance()->m_iAtt = 1;
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(72.f * m_iFrame, 0.f, 72.f, 72.f);
		m_Sprite.SetImageSize(72.f, 72.f);
		m_iFrame++;
		m_fCount = 0.f;
	}
}
