#include "stdafx.h"


PlayerAtt::PlayerAtt()
{
}


PlayerAtt::~PlayerAtt()
{
}

void PlayerAtt::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/PlayerAtt.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 109.f, 110.f);
	m_Sprite.SetImageSize(109.f, 110.f);
}

void PlayerAtt::Render()
{
	m_Sprite.OnRender();
}

void PlayerAtt::Update(float deltatime)
{
	Vector3 temp = m_Sprite.m_Position - m_GetAiPos;
	m_Sprite.m_Position -= temp * deltatime * 5;
	Sprite(deltatime);
}

bool PlayerAtt::CollisionTo(IObject * obj)
{
	if (obj->Tag == "PlayerMap")
	{
		if (m_GetAiPos.x < m_Sprite.m_Position.x + 50)
		{
			PlayerAttBoom * m_pPlayerAttBoom = new PlayerAttBoom;
			//m_pPlayerAttBoom->m_pCursor = m_pCursor;
			m_pPlayerAttBoom->m_bAi = m_bAi;
			m_pPlayerAttBoom->Init();
			m_pPlayerAttBoom->m_Sprite.m_Position = m_GetAiPos;
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayerAttBoom);

			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
			return true;
		}
	}
	return false;
}

void PlayerAtt::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(109.f * m_iFrame, 0.f, 109.f, 110.f);
		m_Sprite.SetImageSize(109.f, 110.f);
		m_iFrame++;

		if (m_iFrame >= 9)
		{
			m_iFrame = 0;
		}
		m_fCount = 0.f;
	}

}
