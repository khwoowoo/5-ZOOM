#include "stdafx.h"


Player2::Player2()
{
}


Player2::~Player2()
{
}

void Player2::Init()
{
	//107.f 76.f
	m_Sprite.LoadTextureFromFile("Texture/Player2.png");
	m_Sprite.SetCustomVB();
	m_Sprite.SetImageUV(0.f, 0.f, 76.f, 107);
	m_Sprite.SetImageSize(76.f, 107);
}

void Player2::Render()
{
	m_Sprite.OnRender();
}

void Player2::Update(float deltatime)
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

bool Player2::CollisionTo(IObject * obj)
{
	return false;
}

void Player2::Sprite(float deltatime)
{
	m_fCount += deltatime;

	//회전을 사용하지 않았다면
	if (m_bRotate == false)
	{
		if (m_fCount >= 0.1f)
		{
			m_Sprite.SetCustomVB();
			m_Sprite.SetImageUV(76.f *m_iFrame, 76.f + 107.f, 76.f, 107.f);
			m_Sprite.SetImageSize(76.f, 107.f);
			m_iFrame++;

			if (m_iFrame >= 9)
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
			m_Sprite.SetImageUV(107.f *m_iFrame, 76.f + 107.f + 107.f, 107.f, 76.f);
			m_Sprite.SetImageSize(107.f, 76.f);
			m_iFrame++;

			if (m_iFrame >= 9)
			{
				m_iFrame = 0;
			}
			m_fCount = 0.f;
		}
	}

}

void Player2::AttSprite(float deltatime)
{
	m_fAttCount += deltatime;

	if (m_fAttCount >= 0.1f)
	{
		m_Sprite.SetCustomVB();
		m_Sprite.SetImageUV(107.f *m_iAttFrame, 76.f + 107.f + 107.f + 76.f, 107.f, 76.f);
		m_Sprite.SetImageSize(107.f, 76.f);
		m_iAttFrame++;

		if (m_iAttFrame >= 5)
		{
			m_bAttSprite = false;
			m_iAttFrame = 0;
		}
		m_fAttCount = 0.f;
	}
}
