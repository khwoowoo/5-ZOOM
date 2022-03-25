#pragma once
class Penquin :public IObject
{
public:
	Sprite2D m_Sprite;
public:
	int m_iFrame = 0;
public:
	Penquin();
	virtual ~Penquin();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
};

