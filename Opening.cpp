#include "stdafx.h"


Opening::Opening()
{
}


Opening::~Opening()
{
}

void Opening::Open()
{
	PlaySound("Texture/sound/song2.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

	OpeningBG * m_pOpeningBG = new OpeningBG;
	m_pOpeningBG->Init();
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pOpeningBG);

	m_pOpeningTexture1 = new OpeningTexture1;
	m_pOpeningTexture1->Init();
	m_pOpeningTexture1->m_Sprite.m_Position = Vector3(-460.f , 696.f , 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pOpeningTexture1);

	m_pOpeningTexture2 = new OpeningTexture2;
	m_pOpeningTexture2->Init();
	m_pOpeningTexture2->m_Sprite.m_Position = Vector3(980.f, -126.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pOpeningTexture2);

	m_pOpeningTexture3 = new OpeningTexture3;
	m_pOpeningTexture3->Init();
	m_pOpeningTexture3->m_Sprite.m_Position = Vector3(1440.f, 1484.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pOpeningTexture3);

	Text * m_pText = new Text;
	m_pText->Init();
	m_pText->m_Sprite.LoadTextureFromFile("Texture/scene'.png");
	m_pText->m_Sprite.m_Position = Vector3(0.f, 950.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pText);

	BlackScreen * m_pBlackScreen = new BlackScreen;
	m_pBlackScreen->Init();
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pBlackScreen);

	Cursor * m_pCursor = new Cursor;
	m_pCursor->Init();
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pCursor);
}

void Opening::Render()
{
;
}

void Opening::Update(float deltatime)
{
	if (KeyManager::GetInstance()->GetKeyState(VK_SPACE) == EKEY_DOWN)
	{
		m_iMove++;
	}
	if (m_iMove == 1)
	{
		m_pOpeningTexture1->m_iMove = 1;
	}

	if (m_iMove == 2)
	{
		m_pOpeningTexture2->m_iMove = 1;
	}

	if (m_iMove == 3)
	{
		m_pOpeningTexture3->m_iMove = 1;
	}

	if (m_iMove >= 4)
	{
		//여기서 개많이 많들어내고 있음
		BlackScreen * m_pBlackScreen = new BlackScreen;
		m_pBlackScreen->Init();
		m_pBlackScreen->m_iStart = 0;
		m_pBlackScreen->m_iEnd = 255;
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pBlackScreen);

		m_fCount += deltatime;
		if (m_fCount >= 1.f)
		{
			SceneManager::GetInstance()->AddScene("SceneMenu", new SceneMenu);
			SceneManager::GetInstance()->ChangeScene("SceneMenu", true);
		}
	}
}

void Opening::Close()
{
}
