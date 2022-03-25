#pragma once
class Button:public IObject
{
public:
	Sprite2D m_Sprite;
public:
	bool m_bIsDown = false;
	bool m_bIn = false;
	bool m_bSizeUp = false;
	float m_fDataSize = 50.f;
public:
	Button();
	virtual ~Button();

	virtual void Render();
	virtual void Update(float deltatime);
};

