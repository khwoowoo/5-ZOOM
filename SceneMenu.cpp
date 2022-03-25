#include "stdafx.h"


SceneMenu::SceneMenu()
{
}


SceneMenu::~SceneMenu()
{
}

void SceneMenu::Open()
{
	PlaySound("Texture/sound/MusicSurround.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

	m_pBackGround = new BackGround;
	m_pBackGround->m_Sprite.m_Posset = Vector2(0.f, 0.f);
	m_pBackGround->m_Sprite.LoadTextureFromFile("Texture/Title.png");

	m_pButton[0] = new Button;
	//m_pButton[0]->m_bSizeUp = true;
	m_pButton[0]->m_Sprite.LoadTextureFromFile("Texture/Start.png");
	m_pButton[0]->m_Sprite.SetCustomVB();
	m_pButton[0]->m_Sprite.SetImageUV(0.f, 0.f, 422.f, 204.f);
	m_pButton[0]->m_Sprite.SetImageSize(422.f, 204.f);
	m_pButton[0]->m_Sprite.m_Position = Vector3(955.f, 334.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton[0]);

	m_pButton[1] = new Button;
	//m_pButton[1]->m_bSizeUp = true;
	m_pButton[1]->m_Sprite.LoadTextureFromFile("Texture/Rule.png");
	m_pButton[1]->m_Sprite.SetCustomVB();
	m_pButton[1]->m_Sprite.SetImageUV(0.f, 0.f, 422.f, 204.f);
	m_pButton[1]->m_Sprite.SetImageSize(422.f, 204.f);
	m_pButton[1]->m_Sprite.m_Position = Vector3(955.f, 537.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton[1]);

	m_pButton[2] = new Button;
	//m_pButton[2]->m_bSizeUp = true;
	m_pButton[2]->m_Sprite.LoadTextureFromFile("Texture/introButton.png");
	m_pButton[2]->m_Sprite.SetCustomVB();
	m_pButton[2]->m_Sprite.SetImageUV(0.f, 0.f, 422.f, 204.f);
	m_pButton[2]->m_Sprite.SetImageSize(422.f, 204.f);
	m_pButton[2]->m_Sprite.m_Position = Vector3(955.f, 741.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton[2]);

	m_pButton[3] = new Button;
	//m_pButton[3]->m_bSizeUp = true;
	m_pButton[3]->m_Sprite.LoadTextureFromFile("Texture/Exit.png");
	m_pButton[3]->m_Sprite.SetCustomVB();
	m_pButton[3]->m_Sprite.SetImageUV(0.f, 0.f, 422.f, 204.f);
	m_pButton[3]->m_Sprite.SetImageSize(422.f, 204.f);
	m_pButton[3]->m_Sprite.m_Position = Vector3(955.f, 947.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton[3]);

	BlackScreen * m_pBlackScreen = new BlackScreen;
	m_pBlackScreen->Init();
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pBlackScreen);
	
	m_pCursor = new Cursor;
	m_pCursor->Init();
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pCursor);
}

void SceneMenu::Render()
{
	m_pBackGround->m_Sprite.OnRender();
}

void SceneMenu::Update(float deltatime)
{
	for (int i = 0; i < 4; i++)
	{
		if (m_pButton[i]->m_bIn == true)
		{
			m_pButton[i]->m_Sprite.SetCustomVB();
			m_pButton[i]->m_Sprite.SetImageUV(422.f, 0.f, 422.f, 204.f);
			m_pButton[i]->m_Sprite.SetImageSize(422.f, 204.f);
		}
		else
		{
			m_pButton[i]->m_Sprite.SetCustomVB();
			m_pButton[i]->m_Sprite.SetImageUV(0.f, 0.f, 422.f, 204.f);
			m_pButton[i]->m_Sprite.SetImageSize(422.f, 204.f);
		}
	}



	if (m_pButton[0]->m_bIsDown == true)
	{
		SceneManager::GetInstance()->AddScene("Loading", new Loading);
		SceneManager::GetInstance()->ChangeScene("Loading", true);

		/*
		SceneManager::GetInstance()->AddScene("GameSetting", new GameSetting);
		SceneManager::GetInstance()->ChangeScene("GameSetting", true);
		*/
	}

	if (m_pButton[1]->m_bIsDown == true)
	{
		MenuTexture * m_pMenuTexture = new MenuTexture;
		m_pMenuTexture->m_pCursor = m_pCursor;
		m_pMenuTexture->m_Sprite.LoadTextureFromFile("Texture/RuleTexture.png");
		m_pMenuTexture->Init();
		m_pMenuTexture->m_Sprite.m_Position = Vector3(960.f, 540.f, 0.f);
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pMenuTexture);
	}


	if (m_pButton[2]->m_bIsDown == true)
	{
		MenuTexture * m_pMenuTexture = new MenuTexture;
		m_pMenuTexture->m_pCursor = m_pCursor;
		m_pMenuTexture->m_Sprite.LoadTextureFromFile("Texture/introTexture.png");
		m_pMenuTexture->Init();
		m_pMenuTexture->m_Sprite.m_Position = Vector3(960.f, 540.f, 0.f);
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pMenuTexture);
	}

	if (m_pButton[3]->m_bIsDown == true)
	{
		PostQuitMessage(0);
	}
}

void SceneMenu::Close()
{
	SAFE_DELETE(m_pBackGround);
}
