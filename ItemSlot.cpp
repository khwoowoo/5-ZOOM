#include "stdafx.h"


ItemSlot::ItemSlot()
{
}


ItemSlot::~ItemSlot()
{
}

void ItemSlot::Init()
{
	m_Sprite.LoadTextureFromFile("Texture/ItemSlot.png");

	m_pButton[0] = new Button;
	m_pButton[0]->m_bSizeUp = true;
	m_pButton[0]->m_Sprite.LoadTextureFromFile("Texture/Arrow.png");
	m_pButton[0]->m_Sprite.m_Position = Vector3(1505.f, 1056.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton[0]);

	m_pButton[1] = new Button;
	m_pButton[1]->m_bSizeUp = true;
	m_pButton[1]->m_Sprite.LoadTextureFromFile("Texture/Item1Button.png");
	m_pButton[1]->m_Sprite.m_Position = Vector3(1334.f, 1004.f + 177.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton[1]);

	m_pButton[2] = new Button;
	m_pButton[2]->m_bSizeUp = true;
	m_pButton[2]->m_Sprite.LoadTextureFromFile("Texture/Item2Button.png");
	m_pButton[2]->m_Sprite.m_Position = Vector3(1500.f, 1004.f + 177.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton[2]);

	m_pButton[3] = new Button;
	m_pButton[3]->m_bSizeUp = true;
	m_pButton[3]->m_Sprite.LoadTextureFromFile("Texture/Item3Button.png");
	m_pButton[3]->m_Sprite.m_Position = Vector3(1670.f, 1004.f + 177.f, 0.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton[3]);
}

void ItemSlot::Render()
{
	m_Sprite.OnRender();
	m_pButton[1]->m_Sprite.OnRender();
	m_pButton[2]->m_Sprite.OnRender();
	m_pButton[3]->m_Sprite.OnRender();
}

void ItemSlot::Update(float deltatime)
{
	if (KeyManager::GetInstance()->GetKeyState(VK_F1) == EKEY_DOWN)
	{
		m_pGameStart->m_iScore += 200;
		m_pGameStart->m_iNextAtt = 3;
	}

	if (KeyManager::GetInstance()->GetKeyState(VK_F2) == EKEY_DOWN)
	{
		m_pGameStart->m_iScore -= 50;
	}

	if (m_pGameStart->m_iScore >= 200.f && m_pGameStart->m_bAiAtt == false && m_bControl[0] == false)
	{
		m_pButton[1]->m_Sprite.SetColor(255, 255, 255, 255);

		if (m_pButton[1]->m_bIsDown == true)
		{
			ItemUseTexture * m_pItemUseTexture = new ItemUseTexture;
			m_pItemUseTexture->m_Sprite.LoadTextureFromFile("Texture/Item1Button.png");
			m_pItemUseTexture->Init();
			m_pItemUseTexture->m_Sprite.m_Position = Vector3(1500.f, 1080.f, 0.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pItemUseTexture);
			m_bControl[0] = true;
			m_pGameStart->m_bItem1 = true;
		}
	}
	else
	{
		m_pButton[1]->m_Sprite.SetColor(25, 25, 25, 255);
	}

	if (m_pGameStart->m_iScore >= 350.f && m_pGameStart->m_bAiAtt == false && m_bControl[1] == false)
	{
		m_pButton[2]->m_Sprite.SetColor(255, 255, 255, 255);

		if (m_pButton[2]->m_bIsDown == true)
		{
			ItemUseTexture * m_pItemUseTexture = new ItemUseTexture;
			m_pItemUseTexture->m_Sprite.LoadTextureFromFile("Texture/Item2Button.png");
			m_pItemUseTexture->Init();
			m_pItemUseTexture->m_Sprite.m_Position = Vector3(1500.f, 1080.f, 0.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pItemUseTexture);

			Item2 * m_pItem2 = new Item2;
			m_pItem2->m_pGameStart = m_pGameStart;
			m_pItem2->Init();
			m_pItem2->m_Sprite.m_Position = Vector3(1150.f, 1080.f + 202.f, 0.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pItem2);
			m_bControl[1] = true;
			m_pGameStart->m_bItem2 = true;
		}
	}
	else
	{
		m_pButton[2]->m_Sprite.SetColor(25, 25, 25, 255);
	}

	if (m_pGameStart->m_iNextAtt >= 3 && m_pGameStart->m_bAiAtt == false && m_bControl[2] == false)
	{
		m_pButton[3]->m_Sprite.SetColor(255, 255, 255, 255);

		if (m_pButton[3]->m_bIsDown == true)
		{
			ItemUseTexture * m_pItemUseTexture = new ItemUseTexture;
			m_pItemUseTexture->m_Sprite.LoadTextureFromFile("Texture/Item3Button.png");
			m_pItemUseTexture->Init();
			m_pItemUseTexture->m_Sprite.m_Position = Vector3(1500.f, 1080.f, 0.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pItemUseTexture);
			m_bControl[2] = true;
			m_pGameStart->m_bItem3 = true;
		}
	}
	else
	{
		m_pButton[3]->m_Sprite.SetColor(25, 25, 25, 255);
	}

	if (m_pButton[0]->m_bIsDown == true)
	{
		if (m_bIsDown == false)
			m_bIsDown = true;
		else
			m_bIsDown = false;
	}

	if (m_bIsDown == true)
	{
		m_Sprite.m_Position.y -= deltatime * 300.f;
		m_pButton[0]->m_Sprite.m_Position.y -= deltatime * 300.f;
		m_pButton[1]->m_Sprite.m_Position.y -= deltatime * 300.f;
		m_pButton[2]->m_Sprite.m_Position.y -= deltatime * 300.f;
		m_pButton[3]->m_Sprite.m_Position.y -= deltatime * 300.f;

		if (m_Sprite.m_Position.y < 1004.f)
		{
			m_Sprite.m_Position.y = 1004.f;
			m_pButton[0]->m_Sprite.m_Position.y = 1004.f - 128.f;
			m_pButton[1]->m_Sprite.m_Position.y = 1020.f;
			m_pButton[2]->m_Sprite.m_Position.y = 1020.f;
			m_pButton[3]->m_Sprite.m_Position.y = 1020.f;
		}
	}

	if (m_bIsDown == false)
	{
		m_Sprite.m_Position.y += deltatime * 300.f;
		m_pButton[0]->m_Sprite.m_Position.y += deltatime * 300.f;
		m_pButton[1]->m_Sprite.m_Position.y += deltatime * 300.f;
		m_pButton[2]->m_Sprite.m_Position.y += deltatime * 300.f;
		m_pButton[3]->m_Sprite.m_Position.y += deltatime * 300.f;
		if (m_Sprite.m_Position.y > 1004.f + 177.f)
		{
			m_Sprite.m_Position.y = 1004.f + 177.f;
			m_pButton[0]->m_Sprite.m_Position.y = 1056.f;
			m_pButton[1]->m_Sprite.m_Position.y = 1004.f + 177.f;
			m_pButton[2]->m_Sprite.m_Position.y = 1004.f + 177.f;
			m_pButton[3]->m_Sprite.m_Position.y = 1004.f + 177.f;
		}
	}
}
