﻿#pragma once

#include <map>
#include <string>
#include <d3d9.h>
#include <d3dx9core.h>

using namespace std;

#define ZeroTexMgr ZeroTextureManager::Instance()

class ZeroTextureManager {
private:
	ZeroTextureManager();

	typedef map<string, LPDIRECT3DTEXTURE9> TEXTURE;
	TEXTURE m_TexMap;

public:
	~ZeroTextureManager();

	static ZeroTextureManager* Instance();
	LPDIRECT3DTEXTURE9 LoadTextureFromFile(char* path);
	void ReloadResource();
};
