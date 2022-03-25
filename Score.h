#pragma once
enum ESCORE_TYPE
{
	ESCORE_ZERO,
	ESCORE_ONE,
	ESCORE_TWO,
	ESCORE_THREE,
	ESCORE_FOUR,
	ESCORE_FIVE,
	ESCORE_SIX,
	ESCORE_SEVEN,
	ESCORE_EIGHT,
	ESCORE_NINE
};
class GameStart;
class Score:public IObject
{
public:
	Sprite2D m_Sprite;
	GameStart * m_pGameStart;
	ESCORE_TYPE m_eScoreType;
public:
	int m_aScore[4] = { 0, };
	int m_iScore = 0;

	int m_aBestScore[4] = { 0, };
	int m_iBestScore = 0;

	int m_aTernScore[2] = { 0, };
	int m_iTern = 0;
public:
	Score();
	virtual ~Score();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
public:
	void ScoreUpdate();
	void BestScoreUpdate();
	void TernUpdate();
};

