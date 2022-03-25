#include "stdafx.h"


BitmapManager::BitmapManager()
{
}


BitmapManager::~BitmapManager()
{
}

void BitmapManager::RemoveAll()
{
	for (auto it : m_TextureMap)
	{
		SAFE_RELEASE(it.second->texture);
		SAFE_DELETE(it.second);
	}
	m_TextureMap.clear();
}

void BitmapManager::LoadBitmapFile(LPCSTR filename)
{
	if (m_TextureMap[filename] == NULL)
	{
		TextureData * temp = new TextureData;
		temp->texture = CDirect3D::GetInstance()->LoadTextureFromFile(filename, &temp->info);
		m_TextureMap[filename] = temp;
	}
}

TextureData * BitmapManager::GetBitmapFile(LPCSTR filename)
{
	if (m_TextureMap[filename] == NULL)
		LoadBitmapFile(filename);
	return m_TextureMap[filename];
}
