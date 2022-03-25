#pragma once
class OpeningTexture3 :public IObject
{
public:
	Sprite2D m_Sprite;
public:
	int m_iMove = 0;
public:
	OpeningTexture3();
	virtual ~OpeningTexture3();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
};

