#include "stdafx.h"

GameSetting::GameSetting()
{
}


GameSetting::~GameSetting()
{
}

void GameSetting::Open()
{
	PlaySound("Texture/sound/Example2.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

	m_pBackGround = new BackGround;
	m_pBackGround->m_Sprite.m_Posset = Vector2(0.f, 0.f);
	m_pBackGround->m_Sprite.LoadTextureFromFile("Texture/GameSettingBG.png");

	m_pButton = new Button;
	m_pButton->m_Sprite.LoadTextureFromFile("Texture/StartButton.png");
	m_pButton->m_Sprite.SetCustomVB();
	m_pButton->m_Sprite.SetImageUV(0.f, 0.f, 231.f, 129.f);
	m_pButton->m_Sprite.SetImageSize(231.f, 129.f);
	m_pButton->m_Sprite.m_Position = Vector3(1550.5f, 866.5f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton);

	m_pGameStart = new GameStart;

	m_pPlayer2[0] = new Player2;
	m_pPlayer2[1] = new Player2;
	m_pPlayer3[0] = new Player3;
	m_pPlayer3[1] = new Player3;
	m_pPlayer4 = new Player4;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m_pPlayerMap[i][j] = new PlayerMap;
			m_pPlayerMap[i][j]->m_pPlayer2[0] = m_pPlayer2[0];
			m_pPlayerMap[i][j]->m_pPlayer2[1] = m_pPlayer2[1];
			m_pPlayerMap[i][j]->m_pPlayer3[0] = m_pPlayer3[0];
			m_pPlayerMap[i][j]->m_pPlayer3[1] = m_pPlayer3[1];
			m_pPlayerMap[i][j]->m_pPlayer4 = m_pPlayer4;
			m_pPlayerMap[i][j]->Init();
			m_pPlayerMap[i][j]->m_iNumber = m_iPlayerMapNumber;
			m_pPlayerMap[i][j]->m_Sprite.m_Position = Vector3(530.f + ( 70 * j), 223.f + (70 * i), 0.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayerMap[i][j]);
			m_iPlayerMapNumber++;
		}
	}

	m_pPlayer2[0]->Tag = "Player2";
	m_pPlayer2[0]->Init();
	m_pPlayer2[0]->m_Sprite.m_Position = Vector3(1286.f, 307.5f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayer2[0]);

	m_pPlayer2[1]->Tag = "Player2_1";
	m_pPlayer2[1]->Init();
	m_pPlayer2[1]->m_Sprite.m_Position = Vector3(1406.f, 307.5f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayer2[1]);

	m_pPlayer3[0]->Tag = "Player3";
	m_pPlayer3[0]->Init();
	m_pPlayer3[0]->m_Sprite.m_Position = Vector3(1286.5f, 538.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayer3[0]);

	m_pPlayer3[1]->Tag = "Player3_1";
	m_pPlayer3[1]->Init();
	m_pPlayer3[1]->m_Sprite.m_Position = Vector3(1405.5, 538.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayer3[1]);

	m_pPlayer4->Tag = "Player4";
	m_pPlayer4->Init();
	m_pPlayer4->m_Sprite.m_Position = Vector3(1351.f, 749.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayer4);

	Text * m_pText = new Text;
	m_pText->Init();
	m_pText->m_Sprite.LoadTextureFromFile("Texture/Space.png");
	m_pText->m_Sprite.m_Position = Vector3(0.f, 950.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pText);

	BlackScreen * m_pBlackScreen = new BlackScreen;
	m_pBlackScreen->Init();
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pBlackScreen);

	Cursor * m_pCursor = new Cursor;
	m_pCursor->Init();
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pCursor);
}

void GameSetting::Render()
{
	m_pBackGround->m_Sprite.OnRender();
}

void GameSetting::Update(float deltatime)
{
	if (m_pButton->m_bIn == true)
	{
		m_pButton->m_Sprite.SetCustomVB();
		m_pButton->m_Sprite.SetImageUV(231.f, 0.f, 231.f, 129.f);
		m_pButton->m_Sprite.SetImageSize(231.f, 129.f);
	}
	else
	{
		m_pButton->m_Sprite.SetCustomVB();
		m_pButton->m_Sprite.SetImageUV(0.f, 0.f, 231.f, 129.f);
		m_pButton->m_Sprite.SetImageSize(231.f, 129.f);
	}

	if (m_iSetting >= 5)
	{
		if (m_pButton->m_bIsDown == true)
		{
			SceneManager::GetInstance()->AddScene("GameStart", m_pGameStart);
			m_pGameStart->m_pGameStart = m_pGameStart;
			for (int i = 0; i < 2; i++)
			{
				m_pGameStart->m_pPlayer2[i] = new Player2;
				m_pGameStart->m_pPlayer3[i] = new Player3;

				m_pGameStart->m_pPlayer2[i]->m_iColPosNum = m_pPlayer2[i]->m_iColPosNum;
				m_pGameStart->m_pPlayer2[i]->m_bRotate = m_pPlayer2[i]->m_bRotate;
				m_pGameStart->m_pPlayer3[i]->m_iColPosNum = m_pPlayer3[i]->m_iColPosNum;
				m_pGameStart->m_pPlayer3[i]->m_bRotate = m_pPlayer3[i]->m_bRotate;
			}
			m_pGameStart->m_pPlayer4 = new Player4;
			m_pGameStart->m_pPlayer4->m_iColPosNum = m_pPlayer4->m_iColPosNum;
			m_pGameStart->m_pPlayer4->m_bRotate = m_pPlayer4->m_bRotate;
			SceneManager::GetInstance()->ChangeScene("GameStart", true);
		}
	}


	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			//2
			if (m_pPlayerMap[i][j]->m_iNumber == m_pPlayer2[0]->m_iColPosNum && m_pPlayer2[0]->m_bRotate == false && m_bCol[0] == false)
			{
				m_pPlayer2[0]->m_Sprite.m_Position = m_pPlayerMap[i][j]->m_Sprite.m_Position;
				m_pPlayer2[0]->m_Sprite.m_Position.y -= 35.f;
				m_pPlayer2[0]->m_bSetting = true;
				GetPlayerPosNum(m_pPlayerMap[i - 1][j]->m_iNumber);
				GetPlayerPosNum(m_pPlayerMap[i][j]->m_iNumber);
				m_pPlayerMap[i - 1][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[i][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_bCol[0] = true;
				m_iSetting++;
			}

			else if (m_pPlayerMap[i][j]->m_iNumber == m_pPlayer2[0]->m_iColPosNum && m_pPlayer2[0]->m_bRotate == true && m_bCol[0] == false)
			{
				m_pPlayer2[0]->m_Sprite.m_Position = m_pPlayerMap[i][j]->m_Sprite.m_Position;
				m_pPlayer2[0]->m_Sprite.m_Position.x -= 35.f;
				m_pPlayer2[0]->m_bSetting = true;
				GetPlayerPosNum(m_pPlayerMap[i][j - 1]->m_iNumber);
				GetPlayerPosNum(m_pPlayerMap[i][j]->m_iNumber);
				m_pPlayerMap[i][j - 1]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[i][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_bCol[0] = true;
				m_iSetting++;
			}

			if (m_pPlayerMap[i][j]->m_iNumber == m_pPlayer2[1]->m_iColPosNum && m_pPlayer2[1]->m_bRotate == false && m_bCol[1] == false)
			{
				m_pPlayer2[1]->m_Sprite.m_Position = m_pPlayerMap[i][j]->m_Sprite.m_Position;
				m_pPlayer2[1]->m_Sprite.m_Position.y -= 35.f;
				m_pPlayer2[1]->m_bSetting = true;
				GetPlayerPosNum(m_pPlayerMap[i - 1][j]->m_iNumber);
				GetPlayerPosNum(m_pPlayerMap[i][j]->m_iNumber);
				m_pPlayerMap[i - 1][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[i][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_bCol[1] = true;
				m_iSetting++;
			}

			else if (m_pPlayerMap[i][j]->m_iNumber == m_pPlayer2[1]->m_iColPosNum && m_pPlayer2[1]->m_bRotate == true && m_bCol[1] == false)
			{
				m_pPlayer2[1]->m_Sprite.m_Position = m_pPlayerMap[i][j]->m_Sprite.m_Position;
				m_pPlayer2[1]->m_Sprite.m_Position.x -= 35.f;
				m_pPlayer2[1]->m_bSetting = true;
				GetPlayerPosNum(m_pPlayerMap[i][j - 1]->m_iNumber);
				GetPlayerPosNum(m_pPlayerMap[i][j]->m_iNumber);
				m_pPlayerMap[i][j - 1]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[i][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_bCol[1] = true;
				m_iSetting++;
			}
			//3
			if (m_pPlayerMap[i][j]->m_iNumber == m_pPlayer3[0]->m_iColPosNum && m_pPlayer3[0]->m_bRotate == false && m_bCol[2] == false)
			{
				m_pPlayer3[0]->m_Sprite.m_Position = m_pPlayerMap[i][j]->m_Sprite.m_Position;
				m_pPlayer3[0]->m_bSetting = true;
				GetPlayerPosNum(m_pPlayerMap[i - 1][j]->m_iNumber);
				GetPlayerPosNum(m_pPlayerMap[i][j]->m_iNumber);
				GetPlayerPosNum(m_pPlayerMap[i + 1][j]->m_iNumber);
				m_pPlayerMap[i - 1][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[i][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[i + 1][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_bCol[2] = true;
				m_iSetting++;
			}

			else if (m_pPlayerMap[i][j]->m_iNumber == m_pPlayer3[0]->m_iColPosNum && m_pPlayer3[0]->m_bRotate == true && m_bCol[2] == false)
			{
				m_pPlayer3[0]->m_Sprite.m_Position = m_pPlayerMap[i][j]->m_Sprite.m_Position;
				m_pPlayer3[0]->m_bSetting = true;
				GetPlayerPosNum(m_pPlayerMap[i][j - 1]->m_iNumber);
				GetPlayerPosNum(m_pPlayerMap[i][j]->m_iNumber);
				GetPlayerPosNum(m_pPlayerMap[i][j + 1]->m_iNumber);
				m_pPlayerMap[i][j - 1]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[i][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[i][j + 1]->m_Sprite.SetColor(25, 25, 25, 255);
				m_bCol[2] = true;
				m_iSetting++;
			}

			if (m_pPlayerMap[i][j]->m_iNumber == m_pPlayer3[1]->m_iColPosNum && m_pPlayer3[1]->m_bRotate == false && m_bCol[3] == false)
			{
				m_pPlayer3[1]->m_Sprite.m_Position = m_pPlayerMap[i][j]->m_Sprite.m_Position;
				m_pPlayer3[1]->m_bSetting = true;
				GetPlayerPosNum(m_pPlayerMap[i - 1][j]->m_iNumber);
				GetPlayerPosNum(m_pPlayerMap[i][j]->m_iNumber);
				GetPlayerPosNum(m_pPlayerMap[i + 1][j]->m_iNumber);
				m_pPlayerMap[i - 1][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[i][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[i + 1][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_bCol[3] = true;
				m_iSetting++;
			}

			else if (m_pPlayerMap[i][j]->m_iNumber == m_pPlayer3[1]->m_iColPosNum && m_pPlayer3[1]->m_bRotate == true && m_bCol[3] == false)
			{
				m_pPlayer3[1]->m_Sprite.m_Position = m_pPlayerMap[i][j]->m_Sprite.m_Position;
				m_pPlayer3[1]->m_bSetting = true;
				GetPlayerPosNum(m_pPlayerMap[i][j - 1]->m_iNumber);
				GetPlayerPosNum(m_pPlayerMap[i][j]->m_iNumber);
				GetPlayerPosNum(m_pPlayerMap[i][j + 1]->m_iNumber);
				m_pPlayerMap[i][j - 1]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[i][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[i][j + 1]->m_Sprite.SetColor(25, 25, 25, 255);
				m_bCol[3] = true;
				m_iSetting++;
			}

			//4
			if (m_pPlayerMap[i][j]->m_iNumber == m_pPlayer4->m_iColPosNum && m_bCol[4] == false)
			{
				m_pPlayer4->m_Sprite.m_Position = m_pPlayerMap[i][j]->m_Sprite.m_Position;
				m_pPlayer4->m_Sprite.m_Position.x -= 35.f;
				m_pPlayer4->m_Sprite.m_Position.y -= 35.f;
				m_pPlayer4->m_bSetting = true;
				GetPlayerPosNum(m_pPlayerMap[i][j - 1]->m_iNumber);
				GetPlayerPosNum(m_pPlayerMap[i][j]->m_iNumber);
				GetPlayerPosNum(m_pPlayerMap[i - 1][j - 1]->m_iNumber);
				GetPlayerPosNum(m_pPlayerMap[i - 1][j]->m_iNumber);
				m_pPlayerMap[i][j - 1]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[i][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[i - 1][j - 1]->m_Sprite.SetColor(25, 25, 25, 255);
				m_pPlayerMap[i - 1][j]->m_Sprite.SetColor(25, 25, 25, 255);
				m_bCol[4] = true;
				m_iSetting++;
			}
		}
	}
}

void GameSetting::Close()
{
	m_iPlayerMapNumber = 0;
	for (int i = 0; i < 5; i++)
		m_bCol[i] = false;
	SAFE_DELETE(m_pBackGround);
}

void GameSetting::GetPlayerPosNum(int num)
{
	m_pGameStart->m_aPlayerPosNumber[m_pGameStart->m_iPlayerPosNumberCount] = num;
	m_pGameStart->m_iPlayerPosNumberCount++;
}
