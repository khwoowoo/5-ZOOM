#pragma once
class IScene
{
public:
	ObjectManager m_ObjectManager;
public:
	IScene();
	virtual ~IScene();

	void SceneOpen();
	void SceneUpdate(float deltatime);
	void SceneRender();
	void SceneIO();
	void SceneClose();

	virtual void Open() {};
	virtual void Render() {};
	virtual void Update(float deltatime) {};
	virtual void Close() {};
};

