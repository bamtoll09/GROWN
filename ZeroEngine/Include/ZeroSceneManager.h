#pragma once
#include "ZeroIScene.h"

#define ZeroSceneMgr ZeroSceneManager::Instance()

class ZeroSceneManager{
private:
	ZeroIScene *m_pNow;

	ZeroSceneManager();
public:
	~ZeroSceneManager();

	static ZeroSceneManager* Instance();

	void Update(float eTime);
	void Render();

	void ChangeScene(ZeroIScene *p,bool isErase=true);
	void Clear();
};
