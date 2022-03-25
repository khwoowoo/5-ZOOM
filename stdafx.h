#pragma once

#include <Windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#pragma warning( default : 4996 )

#define SAFE_DELETE(p)       {if(p){delete p;} (p) = NULL;}
#define SAFE_DELETE_ARRAY(p) {if(p){delete[] p;} (p) = NULL;}
#define SAFE_RELEASE(p)      {if(p){p->Release();} (p) = NULL;}

typedef D3DXVECTOR3 Vector3;
typedef D3DXVECTOR2 Vector2;

#include <iostream>
#include <map>
#include <list>
#include <cstring>
#include <ctime>
using namespace std;

#include "TextureData.h"
#include "SingleInstance.h"
#include "Camera.h"
#include "Direct3D.h"
#include "Time.h"
#include "BitmapManager.h"
#include "KeyManager.h"
#include "IObject.h"
#include "ObjectManager.h"
#include "Sprite2D.h"
#include "IScene.h"
#include "SceneManager.h"

#include "Math.h"
#include "Button.h"
#include "BlackScreen.h"
#include "Score.h"
#include "BackGround.h"
#include "Penquin.h"
#include "UiTexture.h"
#include "ItemUseTexture.h"
#include "DestoryTile.h"
#include "BGAni.h"
#include "MonsterDie1.h"
#include "MonsterDie2.h"
#include "MonsterDie3.h"
#include "MonsterDie4.h"
#include "LoadingBar.h"
#include "LoadingTexture.h"
#include "Whale.h"
#include "MenuTexture.h"
#include "Text.h"

#include "Item2Att.h"
#include "Item2.h"
#include "Item3.h"
#include "Item3Start.h"
#include "ItemSlot.h"
#include "BestScore.h"
#include "ResultLoseAni.h"
#include "ResultWinAni.h"
#include "ResultTexture.h"
#include "OpeningBG.h"
#include "OpeningTexture1.h"
#include "OpeningTexture2.h"
#include "OpeningTexture3.h"

#include "PlayerAttBoom.h"
#include "PlayerAtt.h"
#include "Player2.h"
#include "Player3.h"
#include "Player4.h"
#include "PlayerMap.h"

#include "AiAttBoom.h"
#include "AiAtt.h"
#include "Ai2.h"
#include "Ai3.h"
#include "Ai4.h"
#include "AiMap.h"
#include "Cursor.h"

#include "GameStart.h"
#include "GameSetting.h"
#include "Loading.h"
#include "SceneMenu.h"
#include "Opening.h"


/*
virtual void Open();
virtual void Render();
virtual void Update(float deltatime);
virtual void Close();

virtual void Init();
virtual void Render();
virtual void Update(float deltatime);
virtual bool CollisionTo(IObject * obj);
virtual bool CollisionFrom(IObject * obj);

D3DXMATRIXA16 matWorld;
D3DXMatrixIdentity( &matWorld );
D3DXMatrixRotationX( &matWorld, timeGetTime() / 500.0f );
g_pd3dDevice->SetTransform( D3DTS_WORLD, &matWorld );

// Render the vertex buffer contents
g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2 * 50 - 2);
*/
