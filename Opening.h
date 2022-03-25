#pragma once
class Opening:public IScene
{
public:
	OpeningTexture1 * m_pOpeningTexture1;
	OpeningTexture2 * m_pOpeningTexture2;
	OpeningTexture3 * m_pOpeningTexture3;
public:
	int m_iMove = 0;
	float m_fCount = 0.f;

public:
	Opening();
	virtual ~Opening();

	virtual void Open();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual void Close();
};

