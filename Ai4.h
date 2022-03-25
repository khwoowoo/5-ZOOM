#pragma once
class Ai4 :public IObject
{
public:
	Sprite2D m_Sprite;
public:
	float m_fCount = 0.f;
	int m_iFrame = 0;
public:
	Ai4();
	virtual ~Ai4();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
public:
	void Sprite(float deltatime);
};

