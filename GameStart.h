#pragma once
class GameStart:public IScene
{
public:
	BackGround * m_pBackGround;
	PlayerMap * m_pPlayerMap[10][10];
	AiMap * m_pAiMap[10][10];
	Player2 * m_pPlayer2[2];
	Player3 * m_pPlayer3[2];
	Player4 * m_pPlayer4;
	GameStart * m_pGameStart;
	Penquin * m_pPenquin;

	Score *m_pScore[4];
	Score *m_pBestScore[4];
	Score *m_pTern[4];
	Cursor * m_pCursor;
	BestScore *m_pBestScore_;
public:
	//player의 충돌된 번호를 얻어오기 위해
	int m_aPlayerPosNumber[15] = { 0, };
	int m_iPlayerPosNumberCount = 0;

	//각각의 맵에 고유번호를 만든다
	int m_iPlayerMapNumber = 0;
	int m_iAiMapNumber = 0;

	bool bCheckAi[10][10] = { false, };
	int m_aAiPos[15] = { 0, };

	bool m_bAiAtt = false;
	bool bCheckAiAtt[10][10] = { false, };
	float m_fAiAttCount = 0.f;
	int m_iAiAttCount = 0;

	//Score
	int m_iScore = 0;
	int m_iBestScore = 0;
	int m_iTern = 0;
	int m_iNextAtt = 0;
	int m_iBonurse = 0;

	//item
	bool m_bItem1 = false;
	bool m_bItem2 = false;
	int  m_iItem2Num = -1;
	bool m_bItem3 = false;
	bool bCheckAiAllkill[10][10] = { false, };
	float m_fAiAllkillCount = 0.f;
	int   m_iAiAllkillCount = 0;
	int   m_iItem3Count = 0;

	int m_iWinCount = 0;
	int m_iLoseCount = 0;

	//최고점수을 표현하기 위해 얘는 초기화 x
	int m_TotalScore = 0;
public:
	GameStart();
	virtual ~GameStart();

	virtual void Open();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual void Close();
public:
	void CreateAi();
	void AiAutoAtt(float deltatime);
	void AiDie();
	void Item2Att_();
	void Item3AllKill(float deltatime);
	void ResultWin();
	void ResultLose();
};

