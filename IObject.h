#pragma once
class IObject
{
public:
	float Layer;
	string Tag;
public:
	IObject();
	virtual ~IObject();

	virtual void Init() {};
	virtual void Render() {};
	virtual void Update(float deltatime) {};
	virtual bool CollisionTo(IObject * obj) { return false; }
	virtual bool CollisionFrom(IObject * obj) { return false; }
};

