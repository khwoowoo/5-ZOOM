#pragma once
class GameStart;
//class Cursor;
class AiMap:public IObject
{
public:
	Sprite2D m_Sprite;
	GameStart * m_pGameStart;
	Vector3  m_Random[5];
	//Cursor * m_pCursor;
public:
	//PlayerMap 각각의 고유 번호
	int m_iNumber = 0;

	//m_bAi == true이면 생선된 ai이다
	bool m_bAi = false;

	//중복 공격을 방지 하기 위해
	bool m_bAtt1 = true;

	bool m_bTileDestory = false;

	bool m_bDie = false;
public:
	AiMap();
	virtual ~AiMap();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual bool CollisionTo(IObject * obj);
public:
	void RandomPos(int num);
};

