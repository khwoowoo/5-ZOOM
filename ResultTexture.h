#pragma once
class GameStart;
class Cursor;
class ResultTexture:public IObject
{
public:
	Sprite2D m_Sprite;
	Button * m_pButton;
	Math m_math;
	GameStart * m_pGameStart;
	Score *m_pScore[4];
	Score *m_pBestScore[4];
	ResultLoseAni * m_pResultLoseAni;
	ResultWinAni * m_pResultWinAni;
	Cursor * m_pCursor;
public:
	float m_fTime;
	bool m_bWin = true;
public:
	ResultTexture();
	virtual ~ResultTexture();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual bool CollisionTo(IObject * obj);
public:
	void Dissapear(float deltatime, float Delay);
};

