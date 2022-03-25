#pragma once
class GameStart;
class ItemSlot:public  IObject
{
public:
	Sprite2D m_Sprite;
	//1 = 화살표, 2 ~ 3 = Item3개
	Button * m_pButton[4];
	GameStart * m_pGameStart;
public:
	bool m_bIsDown = false;

	bool m_bControl[3] = { false, };
public:
	ItemSlot();
	virtual ~ItemSlot();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
};

