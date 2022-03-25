#include "stdafx.h"

BlackScreen::BlackScreen()
{
}


BlackScreen::~BlackScreen()
{
}

void BlackScreen::Init()
{
	m_Sprite.m_Posset = Vector2(0.f, 0.f);
	m_Sprite.LoadTextureFromFile("Texture/BlakScreen.png");
	m_fTime = 0.f;
	m_iStart = 255;
	m_iEnd = 0;
}

void BlackScreen::Render()
{
	m_Sprite.OnRender();
}

void BlackScreen::Update(float deltatime)
{
	Dissapear(deltatime, 2.f);
}

bool BlackScreen::CollisionTo(IObject * obj)
{
	if (m_fTime >= 255)
	{
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
		return true;
	}
	return false;
}

void BlackScreen::Dissapear(float deltatime, float Delay)
{
	if (m_fTime >= 255)
	{
		m_fTime = 255;
	}
	else
	{
		m_fTime += deltatime / Delay * 250;
	}
	m_Sprite.SetColor(255, 255, 255, (int)m_math.lerp(m_iStart, m_iEnd, m_fTime));
}
