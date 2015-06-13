#pragma once
#include "Zero.h"

class SceneManagerExample : public ZeroIScene {
private:
	ZeroFont* m_pFont;
public:
	SceneManagerExample();
	~SceneManagerExample();

	void Update(float eTime);
	void Render();
};