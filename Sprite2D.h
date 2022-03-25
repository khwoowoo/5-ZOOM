#pragma once
class Sprite2D
{
public:
	Sprite2D();
	Sprite2D(LPCSTR filename);
	virtual ~Sprite2D();

	bool bEnable;

	Vector3 m_Position, m_Rotate;
	Vector2 m_Scale, m_ScalePivot, m_RotatePivot, m_Posset;
	D3DXCOLOR m_Color;
	D3DXMATRIX m_matWorld;
	CUSTOMVERTEX VertexData[4];
	TextureData m_Texture;

	void OnRender();
	void SetCustomVB();
	void TransformUpdate();
	void LoadTextureFromFile(LPCSTR filename);

	void SetColor(int r, int g, int b, int a);
	void SetImageUV(float sx, float sy, float width, float height);
	void SetImageSize(float width, float height);
};

