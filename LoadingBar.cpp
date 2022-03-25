#include "stdafx.h"


LoadingBar::LoadingBar()
{
}


LoadingBar::~LoadingBar()
{
}

void LoadingBar::Init()
{
	m_Sprite.m_Posset = Vector2(0.f, 0.f);
	m_Sprite.LoadTextureFromFile("Texture/LoadingBar.png");
}

void LoadingBar::Render()
{
	m_Sprite.OnRender();
}

void LoadingBar::Update(float deltatime)
{
	Width += deltatime * 500.f;
	if (Width >= 1466)
	{
		SceneManager::GetInstance()->AddScene("GameSetting", new GameSetting);
		SceneManager::GetInstance()->ChangeScene("GameSetting", true);
		Width = 0.f;
	}
	m_Sprite.SetImageUV(0.f, 0.f, Width, 55.f);
	m_Sprite.SetImageSize(Width, 55.f);
}
