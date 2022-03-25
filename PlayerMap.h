#pragma once
class Player2;
class Player3;
class Player4;
class PlayerMap:public IObject
{
public:
	Sprite2D m_Sprite;
	Player2 * m_pPlayer2[2];
	Player3 * m_pPlayer3[2];
	Player4 * m_pPlayer4;
public:
	//PlayerMap 각각의 고유 번호
	int m_iNumber = 0;

	//m_bPlayerPos == true 이면 player가 있는 타일
	bool m_bPlayerPos = false;

	bool m_bGameStart = false;

	bool m_bDestroy = false;
public://Tag 하기
	PlayerMap();
	virtual ~PlayerMap();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual bool CollisionTo(IObject * obj);

};

