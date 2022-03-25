#pragma once
class Cursor:public IObject
{
public:
	Sprite2D m_Sprite;
public:
	Cursor();
	virtual ~Cursor();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
};

