#pragma once
class SceneManager:public CSingleInstance<SceneManager>
{
	bool closeNowScene = false;
	IScene * nowScene = nullptr;
public:
	IScene * nextScene = nullptr;
	map<string, IScene*> m_SceneMap;
public:
	SceneManager();
	virtual ~SceneManager();

	void AddScene(LPCSTR key, IScene * scene);
	void ChangeScene(LPCSTR key, bool _closeNowScene);
	void CheckChangeScene();
	void RemoveAll();

	IScene * GetScene(LPCSTR key);
	IScene * GetNowScene();
};

