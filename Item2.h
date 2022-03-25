#pragma once
class GameStart;
class Item2:public IObject
{
public:
	Sprite2D m_Sprite;
	GameStart * m_pGameStart;
public:
	float m_fCount = 0.f;
	int m_iFrame = 0;
	bool m_bDie = false;
public:
	Item2();
	virtual ~Item2();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual bool CollisionTo(IObject * obj);
public:
	void Sprite(float deltatime);
};

