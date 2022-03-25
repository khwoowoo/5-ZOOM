#include "stdafx.h"


ItemUseTexture::ItemUseTexture()
{
}


ItemUseTexture::~ItemUseTexture()
{
}

void ItemUseTexture::Init()
{
	m_fTime = 0.f;
	m_Sprite.m_Scale = Vector2(3.f, 3.f);
	m_Sprite.m_ScalePivot = Vector2(107.f * 3, 108.f * 3);
}

void ItemUseTexture::Render()
{
	m_Sprite.OnRender();
}

void ItemUseTexture::Update(float deltatime)
{
	Dissapear(deltatime, 2.f);
}

bool ItemUseTexture::CollisionTo(IObject * obj)
{
	if (m_fTime >= 255)
	{
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
		return true;
	}
	return false;
}

void ItemUseTexture::Dissapear(float deltatime, float Delay)
{
	if (m_fTime >= 255)
	{
		m_fTime = 255;
	}
	else
	{
		m_fTime += deltatime / Delay * 150;
	}
	m_Sprite.SetColor(255, 255, 255, (int)m_math.lerp(255, 0, m_fTime));
}
