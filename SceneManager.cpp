#include "stdafx.h"


SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::AddScene(LPCSTR key, IScene * scene)
{
	if (m_SceneMap[key] == nullptr)
	{
		m_SceneMap[key] = scene;
	}
}

void SceneManager::ChangeScene(LPCSTR key, bool _closeNowScene)
{
	if (m_SceneMap[key] != nullptr)
	{
		nextScene = m_SceneMap[key];
		closeNowScene = _closeNowScene;
	}
}

void SceneManager::CheckChangeScene()
{
	if (nextScene)
	{
		if (closeNowScene && nowScene)
			nowScene->SceneClose();

		nowScene = nextScene;
		nowScene->SceneOpen();
		nextScene = nullptr;
	}
}

void SceneManager::RemoveAll()
{
	for (auto it : m_SceneMap)
	{
		it.second->SceneClose();
		SAFE_DELETE(it.second);
	}
	m_SceneMap.clear();
}

IScene * SceneManager::GetScene(LPCSTR key)
{
	return m_SceneMap[key];
}

IScene * SceneManager::GetNowScene()
{
	return nowScene;
}
