#pragma once
class Cursor;
class MenuTexture :public IObject
{
public:
	Sprite2D m_Sprite;
	Button * m_pButton;
	Cursor * m_pCursor;
public:
	MenuTexture();
	virtual ~MenuTexture();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual bool CollisionTo(IObject * obj);
};

