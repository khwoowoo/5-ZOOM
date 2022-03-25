#include "stdafx.h"


Button::Button()
{
}


Button::~Button()
{
}

void Button::Render()
{
	m_Sprite.OnRender();
}

void Button::Update(float deltatime)
{
	Vector3 vPoint = KeyManager::GetInstance()->vMouse;
	Vector3 vDelta = m_Sprite.m_Position - vPoint;

	if (D3DXVec3Length(&vDelta) < m_fDataSize)
	{
		m_bIn = true;

		if (m_bSizeUp == true)
		{
			m_Sprite.m_Scale = Vector2(1.5f, 1.5f);
			m_Sprite.m_ScalePivot = Vector2((float)(m_Sprite.m_Texture.info.Width * 1.5), (float)(m_Sprite.m_Texture.info.Height * 1.5));
		}

		if (KeyManager::GetInstance()->GetKeyState(VK_LBUTTON) == EKEY_DOWN)
		{
			m_bIsDown = true;
		}
		else
			m_bIsDown = false;
	}
	else
	{
		m_bIn = false;
		m_bIsDown = false;

		if (m_bSizeUp == true)
		{
			m_Sprite.m_Scale = Vector2(1.0f, 1.0f);
			m_Sprite.m_ScalePivot = Vector2((float)(m_Sprite.m_Texture.info.Width), (float)(m_Sprite.m_Texture.info.Height));
		}
	}
}
