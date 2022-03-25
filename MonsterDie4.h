#pragma once
class MonsterDie4 :public IObject
{
public:
	Sprite2D m_Sprite;
public:
	float m_fCount = 0.f;
	int m_iFrame = 0;
	float m_fCount1 = 0.f;
public:
	MonsterDie4();
	virtual ~MonsterDie4();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
public:
	void Sprite(float deltatime);
};

