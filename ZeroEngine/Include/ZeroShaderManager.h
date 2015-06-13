#pragma once
#include "DXUT.h"
#include <map>
using namespace std;

#define ZeroShaderMgr ZeroShaderManager::Instance()

class ZeroShaderManager{
private:
	typedef map<char*,LPD3DXEFFECT> SHADER;
	SHADER m_Shaders;

	ZeroShaderManager();
public:
	~ZeroShaderManager();

	static ZeroShaderManager* Instance();

	LPD3DXEFFECT LoadShaderFromFile(char *path);
	void ReloadResource() ;
};