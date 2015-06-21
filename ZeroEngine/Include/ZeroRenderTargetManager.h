#pragma once

#include <map>
#include <stdarg.h>
#include <string>
#include "ZeroRenderTarget.h"

#define ZeroRTMgr ZeroRenderTargetManager::Instance()->LoadRenderTarget

using namespace std;

class ZeroRenderTargetManager {
private:
	typedef map<string, ZeroRenderTarget*> RT;
	RT m_RenderTargets;
	ZeroRenderTargetManager();

public:
	~ZeroRenderTargetManager();
	static ZeroRenderTargetManager* Instance();
	ZeroRenderTarget* LoadRenderTarget(char* page, ...);
	void ClearAllShaders();
};
