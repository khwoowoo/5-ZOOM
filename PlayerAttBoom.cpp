#include "stdafx.h"


PlayerAttBoom::PlayerAttBoom()
{
}


PlayerAttBoom::~PlayerAttBoom()
{
}

void PlayerAttBoom::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/PlayerAttBoom.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 75.f, 75.f);
	m_Sprite.SetImageSize(75.f, 75.f);
}

void PlayerAttBoom::Render()
{
	m_Sprite.OnRender();
}

void PlayerAttBoom::Update(float deltatime)
{
	Sprite(deltatime);
}

bool PlayerAttBoom::CollisionTo(IObject * obj)
{
	if (obj->Tag == "PlayerMap")
	{
		if (m_iFrame >= 5)
		{
			m_iFrame = 0;
			Camera::GetInstance()->m_iAtt = 0;

			//적이 없으면
			if (m_bAi == false)
			{
				//파괴된 타일 생성
				DestoryTile * m_pDestoryTile = new DestoryTile;
			//	m_pDestoryTile->m_pCursor = m_pCursor;
				int num = rand() % 2 + 0;
				if (num == 1)
					m_pDestoryTile->m_Sprite.LoadTextureFromFile("Texture/AiMap1.png");
				else
					m_pDestoryTile->m_Sprite.LoadTextureFromFile("Texture/AiMap2.png");
				m_pDestoryTile->m_Sprite.m_Position = m_Sprite.m_Position;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pDestoryTile);
			}
			else
			{

			}
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
			return true;
		}
	}

	return false;
}

void PlayerAttBoom::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		Camera::GetInstance()->m_iAtt = 1;
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(75.f * m_iFrame, 0.f, 75.f, 75.f);
		m_Sprite.SetImageSize(75.f, 75.f);
		m_iFrame++;
		m_fCount = 0.f;
	}

}
