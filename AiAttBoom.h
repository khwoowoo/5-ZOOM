#pragma once
class AiAttBoom :public IObject
{
public:
	Sprite2D m_Sprite;
	Vector3 m_GetAiPos;

public:
	float m_fCount = 0.f;
	int m_iFrame = 0;
	bool m_bAi = false;
public:
	AiAttBoom();
	virtual ~AiAttBoom();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual bool CollisionTo(IObject * obj);
public:
	void Sprite(float deltatime);
};

