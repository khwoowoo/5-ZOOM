#include "stdafx.h"


Player3::Player3()
{
}


Player3::~Player3()
{
}

void Player3::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/Player3.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 84.f, 205.f);
	m_Sprite.SetImageSize(84.f, 205.f);
}

void Player3::Render()
{
	m_Sprite.OnRender();
}

void Player3::Update(float deltatime)
{
	if (m_bSetting == false)
	{
		Vector3 vPoint = KeyManager::GetInstance()->vMouse;
		Vector3 vDelta = m_Sprite.m_Position - vPoint;

		if (D3DXVec3Length(&vDelta) < 70.f)
		{
			if (KeyManager::GetInstance()->GetKeyState(VK_LBUTTON) == EKEY_DOWN)
			{
				if (m_bIsDown == false)
					m_bIsDown = true;
				else
					m_bIsDown = false;
			}


			if (KeyManager::GetInstance()->GetKeyState(VK_SPACE) == EKEY_DOWN)
			{
				if (m_bRotate == false)
					m_bRotate = true;
				else
					m_bRotate = false;
			}
		}

		if (m_bIsDown == true)
		{
			m_Sprite.m_Position = vPoint;
			Sprite(deltatime);
		}

		else 
		{
			Sprite(deltatime);
		}
	}
	else
	{
		if (m_bAttSprite == false)
		{
			Sprite(deltatime);
		}
		else
		{
			AttSprite(deltatime);
		}
	}
}

bool Player3::CollisionTo(IObject * obj)
{
	return false;
}

void Player3::Sprite(float deltatime)
{
	m_fCount += deltatime;

	//회전을 사용하지 않았다면
	if (m_bRotate == false)
	{
		if (m_fCount >= 0.1f)
		{
			m_Sprite.SetCustomVB();
			m_Sprite.SetImageUV(84.f * m_iFrame, 84.f + 205.f, 84.f, 205.f);
			m_Sprite.SetImageSize(84.f, 205.f);
			m_iFrame++;

			if (m_iFrame >=9)
			{
				m_iFrame = 0;
			}
			m_fCount = 0.f;
		}
	}
	else
	{
		if (m_fCount >= 0.1f)
		{
			m_Sprite.SetCustomVB();
			m_Sprite.SetImageUV(205.f * m_iFrame, 84.f + 205.f + 205.f, 205.f, 84.f);
			m_Sprite.SetImageSize(205.f, 84.f);
			m_iFrame++;

			if (m_iFrame >= 9)
			{
				m_iFrame = 0;
			}
			m_fCount = 0.f;
		}
	}
}

void Player3::AttSprite(float deltatime)
{
	m_fAttCount += deltatime;

	if (m_fAttCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(205.f * m_iAttFrame, 84.f + 205.f + 205.f + 84.f, 205.f, 84.f);
		m_Sprite.SetImageSize(205.f, 84.f);
		m_iAttFrame++;

		if (m_iAttFrame >= 5)
		{
			m_bAttSprite = false;
			m_iAttFrame = 0;
		}
		m_fAttCount = 0.f;
	}
}
