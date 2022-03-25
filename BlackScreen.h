#pragma once
class BlackScreen:public IObject
{
public:
	Sprite2D m_Sprite;
	Math m_math;
public:
	float m_fTime;
	int m_iStart;
	int m_iEnd;
public:
	BlackScreen();
	virtual ~BlackScreen();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual bool CollisionTo(IObject * obj);
public:
	void Dissapear(float deltatime, float Delay);
};

