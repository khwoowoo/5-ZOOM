#pragma once
//class Cursor;
class DestoryTile :public IObject
{
public:
	Sprite2D m_Sprite;
	//Cursor * m_pCursor;
public:
	DestoryTile();
	virtual ~DestoryTile();

	virtual void Render();
};

