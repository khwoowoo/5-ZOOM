#include "stdafx.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::SetupMatrices(float deltatime)
{
	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
	CDirect3D::GetInstance()->g_pd3dDevice->SetTransform(D3DTS_VIEW, &matView);

	DWORD  halfX = CDirect3D::GetInstance()->dScnX / 2;
	DWORD  halfY = CDirect3D::GetInstance()->dScnY / 2;

	RECT rect;
	rect.left   = (long)(halfX - halfX / fScale) + (450.f * m_iAtt * deltatime);
	rect.right  = (long)(halfX + halfX / fScale) - (450.f * m_iAtt * deltatime);
	rect.top    = (long)(halfY - halfY / fScale) + (450.f * m_iAtt * deltatime);
	rect.bottom = (long)(halfY + halfY / fScale) - (450.f * m_iAtt * deltatime);

	D3DXMatrixOrthoOffCenterLH(&matProj, rect.left , rect.right , rect.bottom, rect.top, 0.1f, 100.0f);
	CDirect3D::GetInstance()->g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}
