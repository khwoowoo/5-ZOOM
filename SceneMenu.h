#pragma once
class SceneMenu:public IScene
{
public:
	BackGround * m_pBackGround;
	Button * m_pButton[4];
	Cursor * m_pCursor;
public:
	SceneMenu();
	virtual ~SceneMenu();

	virtual void Open();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual void Close();
};

