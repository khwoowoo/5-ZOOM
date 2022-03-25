#include "stdafx.h"


IScene::IScene()
{
}


IScene::~IScene()
{
}

void IScene::SceneOpen()
{
	Open();
}

void IScene::SceneUpdate(float deltatime)
{
	Update(deltatime);
	m_ObjectManager.UpdateAll(deltatime);
	m_ObjectManager.CollisionAll();
}

void IScene::SceneRender()
{
	Render();
	m_ObjectManager.RenderAll();
}

void IScene::SceneIO()
{
	m_ObjectManager.ObjectIO();
}

void IScene::SceneClose()
{
	Close();
	m_ObjectManager.RemoveAll();
}
