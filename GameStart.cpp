#include "stdafx.h"


GameStart::GameStart()
{
}


GameStart::~GameStart()
{
}

void GameStart::Open()
{
	//srand((unsigned int)time(NULL));
	PlaySound("Texture/Wavs/Techno_1.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

	m_pBackGround = new BackGround;
	m_pBackGround->m_Sprite.m_Posset = Vector2(0.f, 0.f);
	m_pBackGround->m_Sprite.LoadTextureFromFile("Texture/GameStartBG.png");
	
	m_pPenquin = new Penquin;
	m_pPenquin->Init();
	m_pPenquin->m_Sprite.m_Position = Vector3(960.f, 520.f, 0.f);
	m_pPenquin->m_iFrame = 1;
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPenquin);

	UiTexture * m_pUiTexture = new UiTexture;
	m_pUiTexture->m_Sprite.LoadTextureFromFile("Texture/ui.png");
	m_pUiTexture->m_Sprite.m_Position = Vector3(395.f, 79.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pUiTexture);

	BGAni * m_pBGAni = new BGAni;
	m_pBGAni->Init();
	m_pBGAni->m_Sprite.m_Position = Vector3(437.5f, 989.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pBGAni);

	//ai 1185  223
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m_pPlayerMap[i][j] = new PlayerMap;
			m_pPlayerMap[i][j]->m_bGameStart = true;
			m_pPlayerMap[i][j]->Init();
			m_pPlayerMap[i][j]->m_iNumber = m_iPlayerMapNumber;
			m_pPlayerMap[i][j]->m_Sprite.m_Position = Vector3(150.f + (70 * j), 222.f + (70 * i), 0.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayerMap[i][j]);

			for (int k = 0; k < m_iPlayerPosNumberCount; k++)
			{
				if (m_aPlayerPosNumber[k] == m_iPlayerMapNumber)
				{
					//m_pPlayerMap[i][j]->m_Sprite.SetColor(0, 0, 255, 255);
					m_pPlayerMap[i][j]->m_bPlayerPos = true;
				}
			}
			m_iPlayerMapNumber++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (m_pPlayerMap[i][j]->m_iNumber == m_pPlayer2[0]->m_iColPosNum)
			{
				m_pPlayer2[0]->Tag = "Player2";
				m_pPlayer2[0]->m_bSetting = true;
				m_pPlayer2[0]->Init();
				m_pPlayer2[0]->m_Sprite.m_Position = m_pPlayerMap[i][j]->m_Sprite.m_Position;
				if (m_pPlayer2[0]->m_bRotate == false)
					m_pPlayer2[0]->m_Sprite.m_Position.y -= 35.f;
				else
					m_pPlayer2[0]->m_Sprite.m_Position.x -= 35.f;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayer2[0]);
			}

			else if (m_pPlayerMap[i][j]->m_iNumber == m_pPlayer2[1]->m_iColPosNum)
			{
				m_pPlayer2[1]->Tag = "Player2_1";
				m_pPlayer2[1]->m_bSetting = true;
				m_pPlayer2[1]->Init();
				m_pPlayer2[1]->m_Sprite.m_Position = m_pPlayerMap[i][j]->m_Sprite.m_Position;
				if (m_pPlayer2[1]->m_bRotate == false)
					m_pPlayer2[1]->m_Sprite.m_Position.y -= 35.f;
				else
					m_pPlayer2[1]->m_Sprite.m_Position.x -= 35.f;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayer2[1]);
			}

			else if (m_pPlayerMap[i][j]->m_iNumber == m_pPlayer3[0]->m_iColPosNum)
			{
				m_pPlayer3[0]->Tag = "Player3";
				m_pPlayer3[0]->m_bSetting = true;
				m_pPlayer3[0]->Init();
				m_pPlayer3[0]->m_Sprite.m_Position = m_pPlayerMap[i][j]->m_Sprite.m_Position;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayer3[0]);
			}

			else if (m_pPlayerMap[i][j]->m_iNumber == m_pPlayer3[1]->m_iColPosNum)
			{
				m_pPlayer3[1]->Tag = "Player3_1";
				m_pPlayer3[1]->m_bSetting = true;
				m_pPlayer3[1]->Init();
				m_pPlayer3[1]->m_Sprite.m_Position = m_pPlayerMap[i][j]->m_Sprite.m_Position;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayer3[1]);
			}

			else if (m_pPlayerMap[i][j]->m_iNumber == m_pPlayer4->m_iColPosNum)
			{
				m_pPlayer4->Tag = "Player4";
				m_pPlayer4->m_bSetting = true;
				m_pPlayer4->Init();
				m_pPlayer4->m_Sprite.m_Position = m_pPlayerMap[i][j]->m_Sprite.m_Position;
				m_pPlayer4->m_Sprite.m_Position.x -= 35.f;
				m_pPlayer4->m_Sprite.m_Position.y -= 35.f;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayer4);
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m_pAiMap[i][j] = new AiMap;
			m_pAiMap[i][j]->m_pGameStart = m_pGameStart;
			m_pAiMap[i][j]->m_iNumber = m_iAiMapNumber;
			m_pAiMap[i][j]->Init();
			//m_pAiMap[i][j]->m_pCursor = m_pCursor;
			m_pAiMap[i][j]->m_Sprite.m_Position = Vector3(1185.f + (70 * j), 222.f + (70 * i), 0.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pAiMap[i][j]);
			m_iAiMapNumber++;
		}
	}
	CreateAi();


	for (int i = 0; i < 4; i++)
	{
		m_pScore[i] = new Score;
		m_pScore[i]->Init();
		m_pScore[i]->m_pGameStart = m_pGameStart;
		m_pScore[i]->m_Sprite.m_Position = Vector3(491.f + (27 * i), 105.f ,0.f);
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pScore[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		m_pBestScore[i] = new Score;
		m_pBestScore[i]->Init();
		m_pBestScore[i]->m_pGameStart = m_pGameStart;
		m_pBestScore[i]->m_Sprite.m_Position = Vector3(640.f + (27 * i), 105.f, 0.f);
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pBestScore[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		m_pTern[i] = new Score;
		m_pTern[i]->Init();
		m_pTern[i]->m_pGameStart = m_pGameStart;
		m_pTern[i]->m_Sprite.m_Position = Vector3(359.f +  (27 * i), 105.f, 0.f);
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pTern[i]);
	}
	m_iTern += 1;

	ItemSlot * m_pItemSlot = new ItemSlot;
	m_pItemSlot->m_pGameStart = m_pGameStart;
	m_pItemSlot->Init();
	m_pItemSlot->m_Sprite.m_Position = Vector3(1505.f, 1004.f + 177.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pItemSlot);

	BlackScreen * m_pBlackScreen = new BlackScreen;
	m_pBlackScreen->Init();
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pBlackScreen);

	m_pCursor = new Cursor;
	m_pCursor->Init();
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pCursor);
}

void GameStart::Render()
{
	m_pBackGround->m_Sprite.OnRender();
}

void GameStart::Update(float deltatime)
{
	AiAutoAtt(deltatime);
	Item3AllKill(deltatime);
	if (m_iScore < 0)
		m_iScore = 0;

	if (m_iScore > m_iBestScore)
		m_iBestScore = m_iScore;

	for (int i = 0; i < 4; i++)
		m_pScore[i]->m_eScoreType = (ESCORE_TYPE)m_pScore[i]->m_aScore[i];

	for (int i = 0; i < 4; i++)
		m_pBestScore[i]->m_eScoreType = (ESCORE_TYPE)m_pBestScore[i]->m_aBestScore[i];

	for (int i = 0; i < 2; i++)
		m_pTern[i]->m_eScoreType = (ESCORE_TYPE)m_pTern[i]->m_aTernScore[i];

	m_pCursor->Render();
}

void GameStart::Close()
{
	for (int i = 0; i < 15; i++)
	{
		m_aPlayerPosNumber[i] = 0;
		m_aAiPos[i] = 0;
	}

	m_iPlayerPosNumberCount = 0;
	m_iPlayerMapNumber = 0;
	m_iAiMapNumber = 0;

	m_bAiAtt = false;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			bCheckAi[i][j] = false;
			bCheckAiAtt[i][j] = false;
			bCheckAiAllkill[i][j] = false;
		}
	}
	m_fAiAttCount = 0.f;
	m_iAiAttCount = 0;

	m_iScore = 0;
	m_iBestScore = 0;
	m_iTern = 0;
	m_iNextAtt = 0;
	m_iBonurse = 0;
	m_bItem1 = false;
	m_bItem2 = false;
	m_iItem2Num = -1;
	m_bItem3 = false;

	m_fAiAllkillCount = 0.f;
	m_iAiAllkillCount = 0;
	m_iItem3Count = 0;

	m_iWinCount = 0;
	m_iLoseCount = 0;

	SAFE_DELETE(m_pBackGround);
}

void GameStart::CreateAi()
{
	int num1 = 0;
	int num2 = 0;
	int count = 0;
	int _count = 0;

	for (int i = 0; i < 10; i++)
		m_aAiPos[i] = 0;

	for (int i = 0; i < 5;)
	{
		num1 = rand() % 8 + 0;
		cout << "_rand:" << num1 << endl;
		num2 = rand() % 7 + 0;
		cout << "__rand:" << num2 << endl;
		if (num1 >= 10 || num2 >= 10)
			continue;

		if (bCheckAi[num1][num2] == false)
		{
			count++;
			if (count == 1 || count == 2)
			{
				if (num1 >= 10)
					continue;
				if (num2 >= 10)
					continue;

				m_aAiPos[_count] = num1;
				_count++;
				m_aAiPos[_count] = num2;
				_count++;

				m_pAiMap[num1][num2]->m_bAi = true;
				m_pAiMap[num1][num2 + 1]->m_bAi = true;

				//m_pAiMap[_rand][__rand]->m_Sprite.SetColor(0, 0, 255, 255);
				//m_pAiMap[_rand][__rand + 1]->m_Sprite.SetColor(0, 0, 255, 255);

				for (int j= -1; j < 2; j++)
				{
					bCheckAi[num1 + j][num2 - 1] = true;
					bCheckAi[num1 + j][num2] = true;
					bCheckAi[num1 + j][num2 + 1] = true;
					bCheckAi[num1 + j][num2 + 2] = true;
				}
			}

			else if (count == 3 || count == 4)
			{
				m_aAiPos[_count] = num1;
				_count++;
				m_aAiPos[_count] = num2;
				_count++;

				m_pAiMap[num1][num2]->m_bAi = true;
				m_pAiMap[num1][num2 + 1]->m_bAi = true;
				m_pAiMap[num1][num2 + 2]->m_bAi = true;

				//m_pAiMap[_rand][__rand]->m_Sprite.SetColor(0, 0, 255, 255);
				//m_pAiMap[_rand][__rand + 1]->m_Sprite.SetColor(0, 0, 255, 255);
				//m_pAiMap[_rand][__rand + 2]->m_Sprite.SetColor(0, 0, 255, 255);


				for (int j = -1; j < 2; j++)
				{
					bCheckAi[num1 + j][num2 - 1] = true;
					bCheckAi[num1 + j][num2] = true;
					bCheckAi[num1 + j][num2 + 1] = true;
					bCheckAi[num1 + j][num2 + 2] = true;
					bCheckAi[num1 + j][num2 + 3] = true;
				}
			}

			else if (count == 5)
			{
				m_aAiPos[_count] = num1;
				_count++;
				m_aAiPos[_count] = num2;
				_count++;

				m_pAiMap[num1][num2]->m_bAi = true;
				m_pAiMap[num1][num2 + 1]->m_bAi = true;
				m_pAiMap[num1 + 1][num2]->m_bAi = true;
				m_pAiMap[num1 + 1][num2 + 1]->m_bAi = true;

				//m_pAiMap[_rand][__rand]->m_Sprite.SetColor(0, 0, 255, 255);
				//m_pAiMap[_rand][__rand + 1]->m_Sprite.SetColor(0, 0, 255, 255);
				//m_pAiMap[_rand + 1][__rand]->m_Sprite.SetColor(0, 0, 255, 255);
				//m_pAiMap[_rand + 1][__rand + 1]->m_Sprite.SetColor(0, 0, 255, 255);


				for (int j = -1; j < 3; j++)
				{
					bCheckAi[num1 + j][num2 - 1] = true;
					bCheckAi[num1 + j][num2] = true;
					bCheckAi[num1 + j][num2 + 1] = true;
					bCheckAi[num1 + j][num2 + 2] = true;
				}
			}

			i++;
		}
	}

	for (int i = 0; i < 10; i++)
		cout << m_aAiPos[i] << endl;
}

void GameStart::AiAutoAtt(float deltatime)
{
	int _rand = 0;
	int __rand = 0;

	if (m_bAiAtt == true)
	{
		m_pPenquin->m_iFrame = 2;
		m_fAiAttCount += deltatime;

		if (m_fAiAttCount > 2.0f)
		{
			if (m_iAiAttCount == 100)
			{
				return;
			}

			//랜덤으로 공격할 것을 정해준다
			for (int i = 0; i < 1; )
			{
				_rand = rand() % 10;
				__rand = rand() % 10;

				if (bCheckAiAtt[_rand][__rand] == false)
				{
					bCheckAiAtt[_rand][__rand] = true;
					i++;
				}
			}
			AiAtt * m_pAiAtt = new AiAtt;
			m_pAiAtt->Init();
			m_pAiAtt->m_GetPlayerPos = m_pPlayerMap[_rand][__rand]->m_Sprite.m_Position;
			m_pAiAtt->m_Sprite.m_Position = Vector3(960.f, 540.f, 0.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pAiAtt);

			//Player가 있는 곳
			if (m_pPlayerMap[_rand][__rand]->m_bPlayerPos == true)
			{
				m_pAiAtt->m_bAi = false;
				m_pPlayerMap[_rand][__rand]->m_Sprite.SetColor(0, 0, 255, 255);

				//공격 받으면 -5
				m_iScore -= 5;
				m_iLoseCount++;
				ResultLose();
				m_pPlayerMap[_rand][__rand]->m_bDestroy = false;

				MonsterDie1 * m_pMonsterDie1 = new MonsterDie1;
				m_pMonsterDie1->Init();
				m_pMonsterDie1->m_Sprite.m_Position = m_pPlayerMap[_rand][__rand]->m_Sprite.m_Position;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pMonsterDie1);
			}
			else
			{
				m_pAiAtt->m_bAi = true;
				//Player가 없는 곳이니 공격을 중지 한다
				m_bAiAtt = false;
				//m_pPlayerMap[_rand][__rand]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[_rand][__rand]->m_bDestroy = true;
				//턴증가
				m_iTern += 1;
				//턴이 중가할때마다 -1 이다
				m_iScore -= 1;
			}

			m_iAiAttCount++;
			m_fAiAttCount = 0.f;
			m_pPenquin->m_iFrame = 1;

		}
	}
}

void GameStart::AiDie()
{
	for (int i = 0; i < 10; i++)
	{
		if (m_aAiPos[i] >= 10)
		{
			m_aAiPos[i] = 0;
		}
	}
	cout << "바뀐 번호:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << m_aAiPos[i]  << endl;
	}


	//2
	if (m_pAiMap[m_aAiPos[0]][m_aAiPos[1]]->m_bDie == true && m_pAiMap[m_aAiPos[0]][m_aAiPos[1] + 1]->m_bDie == true)
	{
		Ai2 * m_pAi2 = new Ai2;
		m_pAi2->Init();
		m_pAi2->m_Sprite.m_Position = m_pAiMap[m_aAiPos[0]][m_aAiPos[1]]->m_Sprite.m_Position;
		m_pAi2->m_Sprite.m_Rotate.z += 270.f;
		m_pAi2->m_Sprite.m_Position.y += 105.f;
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pAi2);

		MonsterDie2 * m_pMonsterDie2 = new MonsterDie2;
		m_pMonsterDie2->Init();
		m_pMonsterDie2->m_Sprite.m_Position = m_pAi2->m_Sprite.m_Position;
		m_pMonsterDie2->m_Sprite.m_Rotate.z += 270.f;
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pMonsterDie2);

		m_iScore += 100;
		m_iNextAtt++;

		m_pAiMap[m_aAiPos[0]][m_aAiPos[1]]->m_bDie = false;
		m_pAiMap[m_aAiPos[0]][m_aAiPos[1] + 1]->m_bDie = false;
	}
	else if (m_pAiMap[m_aAiPos[2]][m_aAiPos[3]]->m_bDie == true && m_pAiMap[m_aAiPos[2]][m_aAiPos[3] + 1]->m_bDie == true)
	{
		Ai2 * m_pAi2 = new Ai2;
		m_pAi2->Init();
		m_pAi2->m_Sprite.m_Position = m_pAiMap[m_aAiPos[2]][m_aAiPos[3]]->m_Sprite.m_Position;
		m_pAi2->m_Sprite.m_Rotate.z += 270.f;
		m_pAi2->m_Sprite.m_Position.y += 105.f;
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pAi2);

		MonsterDie2 * m_pMonsterDie2 = new MonsterDie2;
		m_pMonsterDie2->Init();
		m_pMonsterDie2->m_Sprite.m_Position = m_pAi2->m_Sprite.m_Position;
		m_pMonsterDie2->m_Sprite.m_Rotate.z += 270.f;
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pMonsterDie2);

		m_iScore += 100;
		m_iNextAtt++;

		m_pAiMap[m_aAiPos[2]][m_aAiPos[3]]->m_bDie = false;
		m_pAiMap[m_aAiPos[2]][m_aAiPos[3] + 1]->m_bDie = false;
	}
	//3
	else if (m_pAiMap[m_aAiPos[4]][m_aAiPos[5]]->m_bDie == true && m_pAiMap[m_aAiPos[4]][m_aAiPos[5] + 1]->m_bDie == true 
		&& m_pAiMap[m_aAiPos[4]][m_aAiPos[5] + 2]->m_bDie == true)
	{
		Ai3 * m_pAi3 = new Ai3;
		m_pAi3->Init();
		m_pAi3->m_Sprite.m_Position = m_pAiMap[m_aAiPos[4]][m_aAiPos[5]]->m_Sprite.m_Position;
		m_pAi3->m_Sprite.m_Rotate.z += 270.f;
		m_pAi3->m_Sprite.m_Position.y += 140.f;
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pAi3);

		MonsterDie3 * m_pMonsterDie3 = new MonsterDie3;
		m_pMonsterDie3->Init();
		m_pMonsterDie3->m_Sprite.m_Position = m_pAi3->m_Sprite.m_Position;
		m_pMonsterDie3->m_Sprite.m_Rotate.z += 270.f;
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pMonsterDie3);

		m_iScore += 100;
		m_iNextAtt++;

		m_pAiMap[m_aAiPos[4]][m_aAiPos[5]]->m_bDie = false;
		m_pAiMap[m_aAiPos[4]][m_aAiPos[5] + 1]->m_bDie = false;
		m_pAiMap[m_aAiPos[4]][m_aAiPos[5] + 1]->m_bDie = false;
	}
	else if (m_pAiMap[m_aAiPos[6]][m_aAiPos[7]]->m_bDie == true && m_pAiMap[m_aAiPos[6]][m_aAiPos[7] + 1]->m_bDie == true
		  && m_pAiMap[m_aAiPos[6]][m_aAiPos[7] + 2]->m_bDie == true)
	{
		Ai3 * m_pAi3 = new Ai3;
		m_pAi3->Init();
		m_pAi3->m_Sprite.m_Position = m_pAiMap[m_aAiPos[6]][m_aAiPos[7]]->m_Sprite.m_Position;
		m_pAi3->m_Sprite.m_Rotate.z += 270.f;
		m_pAi3->m_Sprite.m_Position.y += 140.f;
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pAi3);

		MonsterDie3 * m_pMonsterDie3 = new MonsterDie3;
		m_pMonsterDie3->Init();
		m_pMonsterDie3->m_Sprite.m_Position = m_pAi3->m_Sprite.m_Position;
		m_pMonsterDie3->m_Sprite.m_Rotate.z += 270.f;
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pMonsterDie3);

		m_iScore += 100;
		m_iNextAtt++;

		m_pAiMap[m_aAiPos[6]][m_aAiPos[7]]->m_bDie = false;
		m_pAiMap[m_aAiPos[6]][m_aAiPos[7] + 1]->m_bDie = false;
		m_pAiMap[m_aAiPos[6]][m_aAiPos[7] + 2]->m_bDie = false;
	}
	//4
	else if (m_pAiMap[m_aAiPos[8]][m_aAiPos[9]]->m_bDie == true && m_pAiMap[m_aAiPos[8]][m_aAiPos[9] + 1]->m_bDie == true && 
		     m_pAiMap[m_aAiPos[8] + 1][m_aAiPos[9]]->m_bDie == true && m_pAiMap[m_aAiPos[8] + 1][m_aAiPos[9] + 1]->m_bDie == true)
	{
		Ai4 * m_pAi4 = new Ai4;
		m_pAi4->Init();
		m_pAi4->m_Sprite.m_Position = m_pAiMap[m_aAiPos[8]][m_aAiPos[9]]->m_Sprite.m_Position;
		m_pAi4->m_Sprite.m_Rotate.z += 270.f;
		m_pAi4->m_Sprite.m_Position.y += 175.f;
		m_pAi4->m_Sprite.m_Position.x += 35.f;
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pAi4);

		MonsterDie4 * m_pMonsterDie4 = new MonsterDie4;
		m_pMonsterDie4->Init();
		m_pMonsterDie4->m_Sprite.m_Position = m_pAi4->m_Sprite.m_Position;
		m_pMonsterDie4->m_Sprite.m_Rotate.z += 270.f;
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pMonsterDie4);

		m_iScore += 100;
		m_iNextAtt++;

		m_pAiMap[m_aAiPos[2]][m_aAiPos[3]]->m_bDie = false;
		m_pAiMap[m_aAiPos[2]][m_aAiPos[3] + 1]->m_bDie = false;
	}

}

void GameStart::Item2Att_()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int h = -1; h < 2; h++)
			{
				for (int k = -1; k < 2; k++)
				{
					if (m_pAiMap[i][j]->m_iNumber == m_iItem2Num + k + (10 * h))
					{
						//ai가 있는 곳이라면
						if (m_pAiMap[i][j]->m_bAi == true)
						{
							//죽은 타일이라고 알려준다
							m_pAiMap[i][j]->m_bDie = true;
							m_pAiMap[i][j]->m_Sprite.SetColor(0, 0, 255, 255);
							if (m_iNextAtt >= 1)
							{
								//보너스 점수
								m_iScore += 25 * m_pGameStart->m_iNextAtt;
								m_iNextAtt = 0;
							}
							AiDie();
							m_iWinCount++;
							ResultWin();

							MonsterDie1 * m_pMonsterDie1 = new MonsterDie1;
							m_pMonsterDie1->Init();
							m_pMonsterDie1->m_Sprite.m_Position = m_pAiMap[i][j]->m_Sprite.m_Position;
							SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pMonsterDie1);
						}
						else
						{
							//m_bTileDestory = true;
							DestoryTile * m_pDestoryTile = new DestoryTile;
							//m_pDestoryTile->m_pCursor = m_pCursor;
							int num = rand() % 2 + 0;
							if (num == 1)
								m_pDestoryTile->m_Sprite.LoadTextureFromFile("Texture/AiMap1.png");
							else
								m_pDestoryTile->m_Sprite.LoadTextureFromFile("Texture/AiMap2.png");
							m_pDestoryTile->m_Sprite.m_Position = m_pAiMap[i][j]->m_Sprite.m_Position;
							SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pDestoryTile);
						}
						//중복 공격 방지
						m_pAiMap[i][j]->m_bAtt1 = false;
					}
				}
			}
		}
	}
}

void GameStart::Item3AllKill(float deltatime)
{
	int num1;
	int num2;

	if (m_bItem3 == true)
	{
		m_fAiAllkillCount += deltatime;

		if (m_fAiAllkillCount >= 0.01f)
		{
			//cout << m_iItem3Count << endl;

			if (m_iItem3Count == 86)
			{
				m_bItem3 = false;
				m_fAiAllkillCount = 0;
				return;
			}

			for (int i = 0; i < 1;)
			{
				num1 = rand() % 10;
				num2 = rand() % 10;

				if (bCheckAiAllkill[num1][num2] == false)
				{
					bCheckAiAllkill[num1][num2] = true;
					i++;
				}
			}

			if (m_pAiMap[num1][num2]->m_bAi == false)
			{
				Item3Start * m_pItem3Start = new Item3Start;
				m_pItem3Start->Init();
				m_pItem3Start->m_Sprite.m_Position = m_pPlayerMap[num1][num2]->m_Sprite.m_Position;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pItem3Start);

				Item3 * m_pItem3 = new Item3;
				m_pItem3->Init();
				m_pItem3->m_GetAiPos = m_pAiMap[num1][num2]->m_Sprite.m_Position;
				m_pItem3->m_Sprite.m_Position = m_pPlayerMap[num1][num2]->m_Sprite.m_Position;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pItem3);

				m_pAiMap[num1][num2]->m_bTileDestory = true;
				//m_Sprite.SetColor(25, 25, 25, 255);

				DestoryTile * m_pDestoryTile = new DestoryTile;
				//m_pDestoryTile->m_pCursor = m_pCursor;
				int num = rand() % 2 + 0;
				if (num == 1)
					m_pDestoryTile->m_Sprite.LoadTextureFromFile("Texture/AiMap1.png");
				else
					m_pDestoryTile->m_Sprite.LoadTextureFromFile("Texture/AiMap2.png");
				m_pDestoryTile->m_Sprite.m_Position = m_pAiMap[num1][num2]->m_Sprite.m_Position;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pDestoryTile);

				//중복 공격 방지
				m_pAiMap[num1][num2]->m_bAtt1 = false;
			}
			m_fAiAllkillCount = 0;
		}
	}

}

void GameStart::ResultWin()
{
	if (m_iWinCount == 14)
	{
		ResultTexture * m_pResultTexture = new ResultTexture;
		m_pResultTexture->m_pCursor = m_pCursor;
		m_pResultTexture->m_pGameStart = m_pGameStart;
		m_pResultTexture->m_Sprite.LoadTextureFromFile("Texture/win.png");
		m_pResultTexture->Init();
		m_pResultTexture->m_Sprite.m_Position = Vector3(962.5f, 540.f, 0.f);
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pResultTexture);

		//최고점수
		if (m_TotalScore <= m_iScore)
		{
			m_TotalScore = m_iScore;
			m_pBestScore_ = new BestScore;
			m_pBestScore_->Init();
			m_pBestScore_->m_Sprite.m_Position = Vector3(960.f, 394.f, 0.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pBestScore_);
		}
	}
}

void GameStart::ResultLose()
{
	if (m_iLoseCount == 14)
	{
		ResultTexture * m_pResultTexture = new ResultTexture;
		m_pResultTexture->m_pCursor = m_pCursor;
		m_pResultTexture->m_bWin = false;
		m_pResultTexture->m_pGameStart = m_pGameStart;
		m_pResultTexture->m_Sprite.LoadTextureFromFile("Texture/lose.png");
		m_pResultTexture->Init();
		m_pResultTexture->m_Sprite.m_Position = Vector3(962.5f, 540.f, 0.f);
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pResultTexture);
	}
}
