#include "stdafx.h"


Score::Score()
{
	m_eScoreType = ESCORE_ZERO;
}


Score::~Score()
{
}

void Score::Init()
{
	switch (m_eScoreType)
	{
	case ESCORE_ZERO:
		m_Sprite.LoadTextureFromFile("Texture/0.png");
		break;
	case ESCORE_ONE:
		m_Sprite.LoadTextureFromFile("Texture/1.png");
		break;
	case ESCORE_TWO:
		m_Sprite.LoadTextureFromFile("Texture/2.png");
		break;
	case ESCORE_THREE:
		m_Sprite.LoadTextureFromFile("Texture/3.png");
		break;
	case ESCORE_FOUR:
		m_Sprite.LoadTextureFromFile("Texture/4.png");
		break;
	case ESCORE_FIVE:
		m_Sprite.LoadTextureFromFile("Texture/5.png");
		break;
	case ESCORE_SIX:
		m_Sprite.LoadTextureFromFile("Texture/6.png");
		break;
	case ESCORE_SEVEN:
		m_Sprite.LoadTextureFromFile("Texture/7.png");
		break;
	case ESCORE_EIGHT:
		m_Sprite.LoadTextureFromFile("Texture/8.png");
		break;
	case ESCORE_NINE:
		m_Sprite.LoadTextureFromFile("Texture/9.png");
		break;
	default:
		break;
	}
}

void Score::Render()
{
	Init();
	m_Sprite.OnRender();
}

void Score::Update(float deltatime)
{
	ScoreUpdate();
	BestScoreUpdate();
	TernUpdate();
}

void Score::ScoreUpdate()
{
	int num = 3;
	m_iScore = m_pGameStart->m_iScore;
	for (int i = 0; i < 4; i++)
		m_aScore[i] = 0;

	while (true)
	{
		if (num < 0)
			break;

		if (m_iScore == 0)
			break;

		m_aScore[num] = m_iScore % 10;
		m_iScore /= 10;
		num--;
	}
}

void Score::BestScoreUpdate()
{
	int num = 3;

	m_iBestScore = m_pGameStart->m_iBestScore;
	for (int i = 0; i < 4; i++)
		m_aBestScore[i] = 0;

	while (true)
	{
		if (num < 0)
			break;

		if (m_iBestScore == 0)
			break;

		m_aBestScore[num] = m_iBestScore % 10;
		m_iBestScore /= 10;
		num--;
	}
}

void Score::TernUpdate()
{
	int num = 1;

	m_iTern = m_pGameStart->m_iTern;
	for (int i = 0; i < 2; i++)
		m_aTernScore[i] = 0;

	while (true)
	{
		if (num < 0)
			break;

		if (m_iTern == 0)
			break;

		m_aTernScore[num] = m_iTern % 10;
		m_iTern /= 10;
		num--;
	}
}
