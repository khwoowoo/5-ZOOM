#include "stdafx.h"

Text::Text()
{
}


Text::~Text()
{
}

void Text::Init()
{
	m_Sprite.m_Posset = Vector2(0.f, 0.f);
	m_fTime = 0.f;
}

void Text::Render()
{
	m_Sprite.OnRender();
}

void Text::Update(float deltatime)
{
	Dissapear(deltatime, 2.f);
}

void Text::Dissapear(float deltatime, float Delay)
{
	m_fTime += deltatime / Delay * 250;
	m_Sprite.SetColor(255, 255, 255, (int)m_math.lerp(0, 255, m_fTime));
}
