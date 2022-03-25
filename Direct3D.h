#pragma once
struct CUSTOMVERTEX
{
	float x, y, z;
	DWORD color;
	float uv, ux;

	void SetVtx(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	void SetColor(int r, int g, int b, int a)
	{
		//color = a << 24 | r << 16 | g << 8 | b;
		color = a << 24 | r << 16 | g << 8 | b;
	}

	void SetUV(float _uv, float _ux)
	{
		uv = _uv;
		ux = _ux;
	}
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_TEX2)
class CDirect3D:public CSingleInstance<CDirect3D>
{
public:
	LPDIRECT3D9             g_pD3D = NULL; // Used to create the D3DDevice
	LPDIRECT3DDEVICE9       g_pd3dDevice = NULL; // Our rendering device
	const bool isWindowed = TRUE;
	const DWORD dScnX = 1920, dScnY = 1080;
public:
	CDirect3D();
	virtual ~CDirect3D();

	HRESULT InitD3D(HWND hWnd);
	VOID Cleanup();
	VOID SetupMatrices();
	VOID Render();
	LPDIRECT3DTEXTURE9 LoadTextureFromFile(LPCSTR filename, D3DXIMAGE_INFO * info);
};

