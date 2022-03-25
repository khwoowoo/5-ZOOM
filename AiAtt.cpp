#include "stdafx.h"


AiAtt::AiAtt()
{
}


AiAtt::~AiAtt()
{
}

void AiAtt::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/AiAtt.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 114.f, 116.f);
	m_Sprite.SetImageSize(114.f, 116.f);
}

void AiAtt::Render()
{
	m_Sprite.OnRender();
}

void AiAtt::Update(float deltatime)
{
	Vector3 temp = m_Sprite.m_Position - m_GetPlayerPos;
	m_Sprite.m_Position -= temp * deltatime * 5;
	Sprite(deltatime);
}

bool AiAtt::CollisionTo(IObject * obj)
{
	if (obj->Tag == "AiMap")
	{
		if (m_GetPlayerPos.x + 50 > m_Sprite.m_Position.x )
		{
			AiAttBoom * m_pAiAttBoom = new AiAttBoom;
			m_pAiAttBoom->Init();
			m_pAiAttBoom->m_bAi = m_bAi;
			m_pAiAttBoom->m_Sprite.m_Position = m_GetPlayerPos;
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pAiAttBoom);

			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
			return true;
		}
	}
	return false;
}

void AiAtt::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(114.f * m_iFrame, 0.f, 114.f, 116.f);
		m_Sprite.SetImageSize(114.f, 116.f);
		m_iFrame++;

		if (m_iFrame >= 9)
		{
			m_iFrame = 0;
		}
		m_fCount = 0.f;
	}

}
