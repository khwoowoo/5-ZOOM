#include "stdafx.h"


PlayerMap::PlayerMap()
{
}


PlayerMap::~PlayerMap()
{
}

void PlayerMap::Init()
{
	Tag = "PlayerMap";
	m_Sprite.LoadTextureFromFile("Texture/PlayerMap.png");
}

void PlayerMap::Render()
{
	m_Sprite.OnRender();
}

void PlayerMap::Update(float deltatime)
{
}

bool PlayerMap::CollisionTo(IObject * obj)
{
	if (m_bGameStart == false)
	{
		if (obj->Tag == "Player2")
		{
			Vector3 vDelta = m_Sprite.m_Position - m_pPlayer2[0]->m_Sprite.m_Position;

			if (D3DXVec3Length(&vDelta) < 60.f &&  m_pPlayer2[0]->m_bIsDown == false)
			{
				//m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayer2[0]->m_iColPosNum = m_iNumber;
			}
		}

		else if (obj->Tag == "Player2_1")
		{
			Vector3 vDelta = m_Sprite.m_Position - m_pPlayer2[1]->m_Sprite.m_Position;

			if (D3DXVec3Length(&vDelta) < 60.f &&  m_pPlayer2[1]->m_bIsDown == false)
			{
				//m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayer2[1]->m_iColPosNum = m_iNumber;
			}
		}

		if (obj->Tag == "Player3")
		{
			Vector3 vDelta = m_Sprite.m_Position - m_pPlayer3[0]->m_Sprite.m_Position;

			if (D3DXVec3Length(&vDelta) < 60.f &&  m_pPlayer3[0]->m_bIsDown == false)
			{
				//m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayer3[0]->m_iColPosNum = m_iNumber;
			}
		}

		else if (obj->Tag == "Player3_1")
		{
			Vector3 vDelta = m_Sprite.m_Position - m_pPlayer3[1]->m_Sprite.m_Position;

			if (D3DXVec3Length(&vDelta) < 60.f &&  m_pPlayer3[1]->m_bIsDown == false)
			{
				//m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayer3[1]->m_iColPosNum = m_iNumber;
			}
		}

		if (obj->Tag == "Player4")
		{
			Vector3 vDelta = m_Sprite.m_Position - m_pPlayer4->m_Sprite.m_Position;

			if (D3DXVec3Length(&vDelta) < 60.f &&  m_pPlayer4->m_bIsDown == false)
			{
				//m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayer4->m_iColPosNum = m_iNumber;
			}
		}
	}
	else
	{
		if (m_bDestroy == true)
		{
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
			return true;
		}
	}

	return false;
}
