#pragma once

#include <list>
#include "ZeroIEffect.h"

#pragma warning(disable: 4996)

#define ZeroEffectMgr ZeroEffectManager::Instance()

using namespace std;

class ZeroEffectManager {
private:
	ZeroEffectManager();

	typedef list<ZeroIEffect*> EFFECTLIST;
	EFFECTLIST m_Effects;

public:
	~ZeroEffectManager();

	static ZeroEffectManager* Instance();

	void PushEffect(ZeroIEffect* p, ZeroVec pos);
	void PushEffect(ZeroIEffect* p);
	void PopEffect(ZeroIEffect* p);
	void Clear();

	void Update(float eTime);
	void RenderPage(int page);
	void RenderPage();
};
