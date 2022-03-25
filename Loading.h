#pragma once
class Loading:public IScene
{
public:
	BackGround * m_pBackGround;
	LoadingBar * m_pLoadingBar;
public:
	Loading();
	virtual ~Loading();

	virtual void Open();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual void Close();
};

