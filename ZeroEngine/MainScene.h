#pragma once
#include <Zero.h>
#include "Object.h"
#include "BlankScene.h"
#include "BlankSceneExit.h"
#include "StartScene.h"

class MainScene : public ZeroIScene
{
private:
	int save[7];
private:
	ZeroInputManager *in;

	ZeroSprite *bg, *start, *exit;

	//Intersect *cursorAndStart, *cursorAndExit;

	RECT cursor, startRect, exitRect, temp;

	FILE *f;
public:
	MainScene();
	~MainScene();

	virtual void Update(float eTime);
	virtual void Render();
};

