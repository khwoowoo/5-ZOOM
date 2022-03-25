#include "stdafx.h"


AiMap::AiMap()
{
}


AiMap::~AiMap()
{
}

void AiMap::Init()
{
	Tag = "AiMap";
	m_Sprite.LoadTextureFromFile("Texture/Aimap.png");
}

void AiMap::Render()
{
	m_Sprite.OnRender();
}

void AiMap::Update(float deltatime)
{
	Vector3 vPoint = KeyManager::GetInstance()->vMouse;
	Vector3 vDelta = m_Sprite.m_Position - vPoint;

	if (D3DXVec3Length(&vDelta) < 30.f && m_bAtt1 == true)
	{
		//ai가 공격을 하지 않고 있는 경우에만 할 수 있다
		if (m_pGameStart->m_bAiAtt == false)
		{
			//item2을 사용한 경유
			if (m_pGameStart->m_bItem2 == true)
			{
				if (KeyManager::GetInstance()->GetKeyState(VK_LBUTTON) == EKEY_DOWN)
				{
					m_pGameStart->m_iItem2Num = m_iNumber;
					m_pGameStart->Item2Att_();
					m_pGameStart->m_bItem2 = false;

					Item2Att * m_pItem2Att = new Item2Att;
					m_pItem2Att->Init();
					m_pItem2Att->m_Sprite.m_Position = m_Sprite.m_Position;
					SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pItem2Att);

				}
			}
			else
			{
				if (KeyManager::GetInstance()->GetKeyState(VK_LBUTTON) == EKEY_DOWN)
				{
					PlayerAtt * m_pPlayerAtt = new PlayerAtt;
					//m_pPlayerAtt->m_pCursor = m_pCursor;
					m_pPlayerAtt->Init();
					int num = rand() % 5;
					RandomPos(num);
					m_pPlayerAtt->m_Sprite.m_Position = m_Random[num];
					m_pPlayerAtt->m_GetAiPos = m_Sprite.m_Position;
					SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayerAtt);
					//ai가 있는 곳이라면
					if (m_bAi == true)
					{
						MonsterDie1 * m_pMonsterDie1 = new MonsterDie1;
						m_pMonsterDie1->Init();
						m_pMonsterDie1->m_Sprite.m_Position = m_Sprite.m_Position;
						SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pMonsterDie1);

						m_pPlayerAtt->m_bAi = true;
						//죽은 타일이라고 알려준다
						m_bDie = true;
						m_Sprite.SetColor(0, 0, 255, 255);

						if (m_pGameStart->m_iNextAtt >= 1)
						{
							//보너스 점수
							m_pGameStart->m_iBonurse++;
							m_pGameStart->m_iScore += 25 * m_pGameStart->m_iBonurse;
						}
						m_pGameStart->AiDie();
						m_pGameStart->m_iWinCount++;
						m_pGameStart->ResultWin();

					}
					else
					{
						m_pPlayerAtt->m_bAi = false;

						//item1을 사용한 경유
						if (m_pGameStart->m_bItem1 == true)
						{
							m_pGameStart->m_bAiAtt = false;
							m_pGameStart->m_bItem1 = false;
						}
						else
						{
							//공격을 실패했으니 ai에게 공격턴을 준다
							m_pGameStart->m_bAiAtt = true;
						}

						m_bTileDestory = true;
						//m_Sprite.SetColor(25, 25, 25, 255);

						m_pGameStart->m_iNextAtt = 0;
						m_pGameStart->m_iBonurse = 0;
					}
					//중복 공격 방지
					m_bAtt1 = false;
				}
			}
		}

	}
}

bool AiMap::CollisionTo(IObject * obj)
{
	if (obj->Tag == "PlayerMap")
	{
		if (m_bTileDestory == true)
		{
			m_pGameStart->m_iItem3Count++;
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
			return true;
		}
	}
	return false;
}

void AiMap::RandomPos(int num)
{
	if (num == 0)
	{
		m_Random[0] = m_pGameStart->m_pPlayer2[0]->m_Sprite.m_Position;
		m_pGameStart->m_pPlayer2[0]->m_bAttSprite = true;
	}

	else if (num == 1)
	{
		m_Random[1] = m_pGameStart->m_pPlayer2[1]->m_Sprite.m_Position;
		m_pGameStart->m_pPlayer2[1]->m_bAttSprite = true;
	}

	else if (num == 2)
	{
		m_Random[2] = m_pGameStart->m_pPlayer3[0]->m_Sprite.m_Position;
		m_pGameStart->m_pPlayer3[0]->m_bAttSprite = true;
	}

	else if (num == 3)
	{
		m_Random[3] = m_pGameStart->m_pPlayer3[1]->m_Sprite.m_Position;
		m_pGameStart->m_pPlayer3[1]->m_bAttSprite = true;
	}

	else if (num == 4)
	{
		m_Random[4] = m_pGameStart->m_pPlayer4->m_Sprite.m_Position;
		m_pGameStart->m_pPlayer4->m_bAttSprite = true;
	}
}
