#include "stdafx.h"


ResultTexture::ResultTexture()
{
}


ResultTexture::~ResultTexture()
{
}

void ResultTexture::Init()
{
	m_fTime = 0.f;

	m_pButton = new Button;
	m_pButton->m_Sprite.LoadTextureFromFile("Texture/ResultButton.png");
	m_pButton->m_Sprite.SetCustomVB();
	m_pButton->m_Sprite.SetImageUV(0.f, 0.f, 173.f, 184.f);
	m_pButton->m_Sprite.SetImageSize(173.f, 184.f);
	m_pButton->m_Sprite.m_Position = Vector3(965.f, 885.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton);

	if (m_bWin == true)
	{
		m_pResultWinAni = new ResultWinAni;
		m_pResultWinAni->Init();
		m_pResultWinAni->m_Sprite.m_Position = Vector3(960.f, 540.f, 0.f);
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pResultWinAni);
	}
	else
	{ 
		m_pResultLoseAni = new ResultLoseAni;
		m_pResultLoseAni->Init();
		m_pResultLoseAni->m_Sprite.m_Position = Vector3(960.f, 540.f, 0.f);
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pResultLoseAni);
	}

	for (int i = 0; i < 4; i++)
	{
		m_pScore[i] = new Score;
		m_pScore[i]->Init();
		m_pScore[i]->m_pGameStart = m_pGameStart;
		m_pScore[i]->m_Sprite.m_Position = Vector3(600.f + (27 * i), 820.f, 0.f);
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pScore[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		m_pBestScore[i] = new Score;
		m_pBestScore[i]->Init();
		m_pBestScore[i]->m_pGameStart = m_pGameStart;
		m_pBestScore[i]->m_Sprite.m_Position = Vector3(1250.f + (27 * i), 820.f, 0.f);
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pBestScore[i]);
	}
}

void ResultTexture::Render()
{
	m_Sprite.OnRender();
	m_pButton->m_Sprite.OnRender();

	for (int i = 0; i < 4; i++)
	{
		m_pScore[i]->m_eScoreType = (ESCORE_TYPE)m_pScore[i]->m_aScore[i];
		m_pScore[i]->Render();
	}
		
	for (int i = 0; i < 4; i++)
	{
		m_pBestScore[i]->m_eScoreType = (ESCORE_TYPE)m_pBestScore[i]->m_aBestScore[i];
		m_pBestScore[i]->Render();
	}

	if (m_bWin == true)
	{
		m_pResultWinAni->m_Sprite.OnRender();
	}
	else
	{
		m_pResultLoseAni->m_Sprite.OnRender();
	}
	m_pCursor->m_Sprite.OnRender();
}

void ResultTexture::Update(float deltatime)
{
	Dissapear(deltatime, 2.f);

	if (m_pButton->m_bIn == true)
	{
		m_pButton->m_Sprite.SetCustomVB();
		m_pButton->m_Sprite.SetImageUV(173.f, 0.f, 173.f, 184.f);
		m_pButton->m_Sprite.SetImageSize(173.f, 184.f);
	}
	else
	{
		m_pButton->m_Sprite.SetCustomVB();
		m_pButton->m_Sprite.SetImageUV(0.f, 0.f, 173.f, 184.f);
		m_pButton->m_Sprite.SetImageSize(173.f, 184.f);
	}


	if (m_pButton->m_bIsDown == true)
	{
		SceneManager::GetInstance()->ChangeScene("SceneMenu", true);
	}

}

bool ResultTexture::CollisionTo(IObject * obj)
{
	return false;
}

void ResultTexture::Dissapear(float deltatime, float Delay)
{
	if (m_fTime >= 255)
	{
		m_fTime = 255;
	}
	else
	{
		m_fTime += deltatime / Delay * 150;
	}
	m_Sprite.SetColor(255, 255, 255, (int)m_math.lerp(0, 255, m_fTime));
}
