#pragma once
class Item3 :public IObject
{
public:
	Sprite2D m_Sprite;
	Vector3 m_GetAiPos;
public:
	float m_fCount = 0.f;
	int m_iFrame = 0;
public:
	Item3();
	virtual ~Item3();


	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual bool CollisionTo(IObject * obj);
public:
	void Sprite(float deltatime);
};

