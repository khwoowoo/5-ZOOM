#pragma once
class ObjectManager
{
public:
	ObjectManager();
	virtual ~ObjectManager();

	list<IObject*> m_AddList;
	list<IObject*> m_RemoveList;
	list<IObject*> m_UpdateList;

	void AddObject(IObject * obj);
	void RemoveObject(IObject * obj);

	void RenderAll();
	void UpdateAll(float deltatime);

	void ObjectIO();
	void RemoveAll();
	void CollisionAll();

	bool operator()(IObject * layer1, IObject* layer2)
	{
		return layer1->Layer < layer2->Layer;
	}
};

