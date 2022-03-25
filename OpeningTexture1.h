#pragma once
class OpeningTexture1 :public IObject
{
public:
	Sprite2D m_Sprite;
public:
	float m_fCount = 0.f;
	int m_iFrame = 0;
	int m_iMove = 0;
public:
	OpeningTexture1();
	virtual ~OpeningTexture1();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
public:
	void Sprite(float deltatime);
};

