#pragma once
class Ai3 :public IObject
{
public:
	Sprite2D m_Sprite;
public:
	float m_fCount = 0.f;
	int m_iFrame = 0;
public:
	Ai3();
	virtual ~Ai3();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
public:
	void Sprite(float deltatime);
};

