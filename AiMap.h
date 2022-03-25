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
	//PlayerMap ������ ���� ��ȣ
	int m_iNumber = 0;

	//m_bAi == true�̸� ������ ai�̴�
	bool m_bAi = false;

	//�ߺ� ������ ���� �ϱ� ����
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

