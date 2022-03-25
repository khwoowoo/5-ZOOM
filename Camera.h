#pragma once
class Camera:public CSingleInstance <Camera>
{
	D3DXVECTOR3 vEyePt    = Vector3(0.0f, 0.0f, -5.0f);
	D3DXVECTOR3 vLookatPt = Vector3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vUpVec    = Vector3(0.0f, 1.0f, 0.0f);
	D3DXMATRIX matView;
	D3DXMATRIX matProj;
public:
	float fScale = 1.f;
	int m_iAtt = 0;
public:
	Camera();
	virtual ~Camera();


	void SetupMatrices(float deltatime);
	void SetPos(Vector3 pos)
	{
		vLookatPt = pos;
		vEyePt.x = pos.x;
		vEyePt.y = pos.y;
	}
	Vector3 GetPos()const {
		return vLookatPt;
	}
};