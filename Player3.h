#pragma once
class Player3 :public IObject
{
public:
	Sprite2D m_Sprite;
public:
	bool m_bIsDown = false;
	bool m_bRotate = false;
	bool m_bGameStart = false;
	bool m_bSetting = false;

	float m_fCount = 0.f;
	int m_iFrame = 0;

	int m_iColPosNum = -1;
	bool m_bAttSprite = false;
	float m_fAttCount = 0.f;
	int m_iAttFrame = 0;
public:
	Player3();
	virtual ~Player3();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual bool CollisionTo(IObject * obj);
public:
	void Sprite(float deltatime);
	void AttSprite(float deltatime);
};

