#pragma once
class UiTexture:public IObject
{
public:
	Sprite2D m_Sprite;
public:
	UiTexture();
	virtual ~UiTexture();

	virtual void Render();
};

