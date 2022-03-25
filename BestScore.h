#pragma once
class BestScore :public IObject
{
public:
	Sprite2D m_Sprite;
	Button * m_pButton;
public:
	float m_fCount = 0.f;
	int m_iFrame = 0;
public:
	BestScore();
	virtual ~BestScore();


	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual bool CollisionTo(IObject * obj);
public:
	void Sprite(float deltatime);
};

