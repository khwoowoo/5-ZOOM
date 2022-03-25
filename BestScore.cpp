#include "stdafx.h"

BestScore::BestScore()
{
}


BestScore::~BestScore()
{
}

void BestScore::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/Best.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 801.f, 445.f);
	m_Sprite.SetImageSize(801.f, 445.f);

	m_pButton = new Button;
	m_pButton->m_Sprite.LoadTextureFromFile("Texture/BestButton.png");
	m_pButton->m_Sprite.SetCustomVB();
	m_pButton->m_Sprite.SetImageUV(0.f, 0.f, 63.f, 67.f);
	m_pButton->m_Sprite.SetImageSize(63.f, 67.f);
	m_pButton->m_Sprite.m_Position = Vector3(1300.f, 430.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton);
}

void BestScore::Render()
{
	m_Sprite.OnRender();
}

void BestScore::Update(float deltatime)
{
	if (m_pButton->m_bIn == true)
	{
		m_pButton->m_Sprite.SetCustomVB();
		m_pButton->m_Sprite.SetImageUV(63.f, 0.f, 63.f, 67.f);
		m_pButton->m_Sprite.SetImageSize(63.f, 67.f);
	}
	else
	{
		m_pButton->m_Sprite.SetCustomVB();
		m_pButton->m_Sprite.SetImageUV(0.f, 0.f, 63.f, 67.f);
		m_pButton->m_Sprite.SetImageSize(63.f, 67.f);
	}

	//if (m_iFrame <= 8)
	//{
	//	Sprite(deltatime);
	//}
	//else
	//{
	//	m_Sprite.SetCustomVB();
	//	m_Sprite.SetImageUV(801.f * 0, 0.f, 801.f, 445.f);
	//	m_Sprite.SetImageSize(801.f, 445.f);
	//}
	Sprite(deltatime);
}

bool BestScore::CollisionTo(IObject * obj)
{
	if (obj->Tag == "PlayerMap")
	{
		if (m_pButton->m_bIsDown == true)
		{
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(m_pButton);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
			return true;
		}
	}
	return false;
}

void BestScore::Sprite(float deltatime)
{
	m_fCount += deltatime;

	if (m_fCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(801.f * m_iFrame, 0.f, 801.f, 445.f);
		m_Sprite.SetImageSize(801.f, 445.f);
		m_iFrame++;
		if (m_iFrame >= 8)
		{
			m_iFrame = 0;
		}
		m_fCount = 0.f;
	}
}
