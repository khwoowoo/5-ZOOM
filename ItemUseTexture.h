#pragma once
class ItemUseTexture:public IObject
{
public:
	Sprite2D m_Sprite;
	Math m_math;
public:
	float m_fTime;
public:
	ItemUseTexture();
	virtual ~ItemUseTexture();

	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual bool CollisionTo(IObject * obj);
public:
	void Dissapear(float deltatime, float Delay);
};

