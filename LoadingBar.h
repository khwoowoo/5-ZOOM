#pragma once
class LoadingBar:public IObject
{
public:
	Sprite2D m_Sprite;
public:
	float Width = 0.f;
public:
	LoadingBar();
	virtual ~LoadingBar();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
};

