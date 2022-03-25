#include "stdafx.h"


Penquin::Penquin()
{
}


Penquin::~Penquin()
{
}

void Penquin::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/Penquin.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 186.f, 1073.f);
	m_Sprite.SetImageSize(186.f, 1073.f);
}

void Penquin::Render()
{
	m_Sprite.OnRender();
}

void Penquin::Update(float deltatime)
{
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(186.f * m_iFrame, 0.f, 186.f, 1073.f);
	m_Sprite.SetImageSize(186.f, 1073.f);
}