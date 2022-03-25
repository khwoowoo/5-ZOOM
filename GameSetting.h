#pragma once
class GameSetting:public IScene
{
public:
	BackGround * m_pBackGround;
	Button * m_pButton;
	PlayerMap * m_pPlayerMap[10][10];
	Player2 * m_pPlayer2[2];
	Player3 * m_pPlayer3[2];
	Player4 * m_pPlayer4;
	GameStart * m_pGameStart;
public:
	int m_iPlayerMapNumber = 0;
	bool m_bCol[5] = { false, };
	int m_iSetting = 0;
public:
	GameSetting();
	virtual ~GameSetting();

	virtual void Open();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual void Close();
public:
	void GetPlayerPosNum(int num);
};

