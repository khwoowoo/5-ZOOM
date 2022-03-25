#include "stdafx.h"


Sprite2D::Sprite2D()
{
	bEnable = TRUE;

	m_Position = Vector3(0.f, 0.f, 0.f);
	m_Rotate = Vector3(0.f, 0.f, 0.f);
	m_RotatePivot = Vector2(0.f, 0.f);
	m_Scale = Vector2(1.f, 1.f);
	m_ScalePivot = Vector2(0.f, 0.f);
	m_Posset = Vector2(0.5f, 0.5f);

	m_Color = 0xFFFFFFFF;

	D3DXMatrixIdentity(&m_matWorld);
}

Sprite2D::Sprite2D(LPCSTR filename)
{
	this->Sprite2D::Sprite2D();
	LoadTextureFromFile(filename);
}


Sprite2D::~Sprite2D()
{
}

void Sprite2D::OnRender()
{
	if (!bEnable)
		return;

	TransformUpdate();

	CDirect3D::GetInstance()->g_pd3dDevice->SetTexture(0, m_Texture.texture);
	CDirect3D::GetInstance()->g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	CDirect3D::GetInstance()->g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, (void*)VertexData , sizeof(CUSTOMVERTEX));
}

void Sprite2D::SetCustomVB()
{
	VertexData[0].SetVtx(0.f, 0.f, 0.f);
	VertexData[1].SetVtx(0.f, (float)m_Texture.info.Height, 0.f);
	VertexData[2].SetVtx((float)m_Texture.info.Width, 0.f, 0.f);
	VertexData[3].SetVtx((float)m_Texture.info.Width, (float)m_Texture.info.Height, 0.f);

	VertexData[0].SetColor(255, 255, 255, 255);
	VertexData[1].SetColor(255, 255, 255, 255);
	VertexData[2].SetColor(255, 255, 255, 255);
	VertexData[3].SetColor(255, 255, 255, 255);

	VertexData[0].SetUV(0.f, 0.f);
	VertexData[1].SetUV(0.f, 1.f);
	VertexData[2].SetUV(1.f, 0.f);
	VertexData[3].SetUV(1.f, 1.f);
}

void Sprite2D::TransformUpdate()
{
	float fPX = VertexData[3].x;
	float fPY = VertexData[3].y;

	float fX = m_Position.x;
	float fY = m_Position.y;
	float fZ = m_Position.z;

	float fRZ = m_Rotate.z;

	D3DXMATRIX matPos, matTrans;
	D3DXMatrixTranslation(&matTrans, fX, fY, fZ);
	D3DXMatrixTranslation(&matPos, -fPX * m_Posset.x, -fPY * m_Posset.y, 0.f);


	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixTransformation2D(&matWorld, &m_ScalePivot, 0.f, &m_Scale, &m_RotatePivot, D3DXToRadian(fRZ), NULL);

	D3DXMatrixMultiply(&matWorld, &matWorld, &matPos);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matTrans);

	m_matWorld = matWorld;
	CDirect3D::GetInstance()->g_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);

}

void Sprite2D::LoadTextureFromFile(LPCSTR filename)
{
	TextureData * temp = BitmapManager::GetInstance()->GetBitmapFile(filename);
	m_Texture.info = temp->info;
	m_Texture.texture = temp->texture;

	SetCustomVB();
}

void Sprite2D::SetColor(int r, int g, int b, int a)
{
	m_Color = a << 24 | r << 16 | g << 8 | b;

	VertexData[0].SetColor(r, g, b, a);
	VertexData[1].SetColor(r, g, b, a);
	VertexData[2].SetColor(r, g, b, a);
	VertexData[3].SetColor(r, g, b, a);
}

void Sprite2D::SetImageUV(float sx, float sy, float width, float height)
{
	float fX = m_Texture.info.Width;
	float fY = m_Texture.info.Height;

	VertexData[0].SetUV(sx /fX, sy / fY);
	VertexData[1].SetUV(sx /fX, (sy + height) / fY);
	VertexData[2].SetUV((sx + width) /fX, sy / fY);
	VertexData[3].SetUV((sx + width) /fX, (sy + height) / fY);
}

void Sprite2D::SetImageSize(float width, float height)
{
	VertexData[0].SetVtx(0.f, 0.f, 0.f);
	VertexData[1].SetVtx(0.f, height, 0.f);
	VertexData[2].SetVtx(width, 0.f, 0.f);
	VertexData[3].SetVtx(width, height, 0.f);
}
