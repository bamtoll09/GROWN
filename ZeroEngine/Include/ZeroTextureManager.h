#pragma once
#include "DXUT.h"
#include <map>
#include <string>
#include "ZeroResource.h"
using namespace std;

#define ZeroTexMgr ZeroTextureManager::Instance()

class ZeroTextureManager {
private:
	typedef map<string, LPDIRECT3DTEXTURE9> TEXTURE;
	TEXTURE m_TexMap;

	ZeroTextureManager();
public:
	~ZeroTextureManager();

	static ZeroTextureManager* Instance();
	LPDIRECT3DTEXTURE9 LoadTextureFromFile(char* path);
	void ReloadResource() ;
};