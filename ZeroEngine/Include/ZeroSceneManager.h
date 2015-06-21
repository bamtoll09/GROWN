#pragma once

#include "ZeroIScene.h"

#define ZeroSceneMgr ZeroSceneManager::Instance()

class ZeroSceneManager {
private:
	ZeroSceneManager();

	ZeroIScene *m_pNow;

public:
	~ZeroSceneManager();

	static ZeroSceneManager* Instance();

	void Update(float eTime);
	void Render();

	void ChangeScene(ZeroIScene *p, bool isErase = true);
	void Clear();
};
