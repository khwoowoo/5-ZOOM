#include "stdafx.h"


Loading::Loading()
{
}


Loading::~Loading()
{
}

void Loading::Open()
{
	m_pBackGround = new BackGround;
	m_pBackGround->m_Sprite.m_Posset = Vector2(0.f, 0.f);
	m_pBackGround->m_Sprite.LoadTextureFromFile("Texture/LoadingBG.png");


	LoadingTexture * m_pLoadingTexture = new LoadingTexture;
	m_pLoadingTexture->Init();
	m_pLoadingTexture->m_Sprite.m_Position = Vector3(959.f + 110.f, 313.5f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pLoadingTexture);

	m_pLoadingBar = new LoadingBar;
	m_pLoadingBar->Init();
	m_pLoadingBar->m_Sprite.m_Position = Vector3(230.f, 800.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pLoadingBar);

	//254.f  821.f  1716.f
	Whale * m_pWhale = new Whale;
	m_pWhale->Init();
	m_pWhale->m_Sprite.m_Position = Vector3(254.f, 821.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pWhale);

	BlackScreen * m_pBlackScreen = new BlackScreen;
	m_pBlackScreen->Init();
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pBlackScreen);

	Cursor * m_pCursor = new Cursor;
	m_pCursor->Init();
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pCursor);
}

void Loading::Render()
{
	m_pBackGround->m_Sprite.OnRender();
}

void Loading::Update(float deltatime)
{
}

void Loading::Close()
{
	SAFE_DELETE(m_pBackGround);
}
