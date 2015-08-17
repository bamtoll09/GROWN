#pragma once

#include <list>
#include "ZeroIEffect.h"

#pragma warning(disable: 4996)

#define ZeroEffectMgr ZeroEffectManager::Instance()

using namespace std;

class ZeroEffectManager {

private:
	ZeroEffectManager();

	list<ZeroIEffect*> effectList;

public:
	~ZeroEffectManager();

	static ZeroEffectManager* Instance();

	void PushEffect(ZeroIEffect* _p, ZeroVec _pos);
	void PushEffect(ZeroIEffect* _p);
	void PopEffect(ZeroIEffect* _p);
	void Clear();

	void Update(float _eTime);
	void RenderPage(int _page);
	void RenderPage();
};
