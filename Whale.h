#pragma once
class Whale :public IObject
{
public:
	Sprite2D m_Sprite;
public:
	Whale();
	virtual ~Whale();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
};

