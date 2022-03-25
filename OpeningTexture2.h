#pragma once
class OpeningTexture2 :public IObject
{
public:
	Sprite2D m_Sprite;
public:
	int m_iMove = 0;
public:
	OpeningTexture2();
	virtual ~OpeningTexture2();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
};

