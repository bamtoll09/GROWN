#pragma once

#include "ZeroIScene.h"

#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=0; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=0; } }
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=0; } }

#define ZeroSceneMgr ZeroSceneManager::Instance()

struct TR {
	enum {
		None = -1,
		BandedSwirl = 0,
		CircleReveal = 1,
		CircleStretch = 2,
		CloudReveal = 3,
		Crumble = 4,
		DropFade = 5,
		Fade = 6,
		Pixelate = 7,
		RadialBlur = 8,
		RadialWiggle = 9,
		RandomCircleReveal = 10,
		Ripple = 11,
		RotateCrumble = 12,
		Saturate = 13,
		SlideIn = 14,
		SmoothSwirlGrid = 15,
	};
};

class ZeroSceneManager {
private:
	ZeroSceneManager();

	ZeroIScene *m_pNow;
	ZeroIScene *m_pTemp;
	ZeroIScene *m_pShader;
	float m_fChangeTime;
	bool m_bErase;

public:
	~ZeroSceneManager();

	static ZeroSceneManager* Instance();

	void Update(float eTime);
	void Render();

	void ChangeScene(ZeroIScene *p, int kindTr = -1, float time = 2.0f, bool isErase = true);
	void Clear();
};
