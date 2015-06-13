#pragma once
#include "ZeroIEffect.h"
#include <list>
using namespace std;

#define ZeroEffectMgr ZeroEffectManager::Instance()

class ZeroEffectManager{
private:
	typedef list<ZeroIEffect*> EFFECTLIST;
	EFFECTLIST m_Effects;

	ZeroEffectManager();
public:
	~ZeroEffectManager();

	static ZeroEffectManager* Instance();

	void PushEffect(ZeroIEffect* p,ZeroVec pos);
	void PushEffect(ZeroIEffect* p);
	void PopEffect(ZeroIEffect* p);
	void Clear();

	void Update(float eTime);
	void RenderPage(int page);
	void RenderPage();
};