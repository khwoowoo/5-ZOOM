#include "stdafx.h"


MenuTexture::MenuTexture()
{
}


MenuTexture::~MenuTexture()
{
}

void MenuTexture::Init()
{
	m_pButton = new Button;
	m_pButton->m_Sprite.LoadTextureFromFile("Texture/ResultButton.png");
	m_pButton->m_Sprite.SetCustomVB();
	m_pButton->m_Sprite.SetImageUV(0.f, 0.f, 173.f, 184.f);
	m_pButton->m_Sprite.SetImageSize(173.f, 184.f);
	m_pButton->m_Sprite.m_Position = Vector3(1331.5f, 207.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton);
}

void MenuTexture::Render()
{
	m_Sprite.OnRender();
	m_pButton->m_Sprite.OnRender();
	m_pCursor->m_Sprite.OnRender();
}

void MenuTexture::Update(float deltatime)
{
	if (m_pButton->m_bIn == true)
	{
		m_pButton->m_Sprite.SetCustomVB();
		m_pButton->m_Sprite.SetImageUV(173.f, 0.f, 173.f, 184.f);
		m_pButton->m_Sprite.SetImageSize(173.f, 184.f);
	}
	else
	{
		m_pButton->m_Sprite.SetCustomVB();
		m_pButton->m_Sprite.SetImageUV(0.f, 0.f, 173.f, 184.f);
		m_pButton->m_Sprite.SetImageSize(173.f, 184.f);
	}
}

bool MenuTexture::CollisionTo(IObject * obj)
{
	if (m_pButton->m_bIsDown == true)
	{
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(m_pButton);
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
		return true;
	}
	return false;
}
