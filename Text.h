#pragma once
class Text :public IObject
{
public:
	Sprite2D m_Sprite;
	Math m_math;
public:
	float m_fTime;
public:
	Text();
	virtual ~Text();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
public:
	void Dissapear(float deltatime, float Delay);
};

