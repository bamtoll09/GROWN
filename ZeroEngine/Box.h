#pragma once
#include <Zero.h>

class Box : public ZeroIScene
{
public:
	ZeroSprite *box;
	ZeroIScene *target;
public:
	Box(ZeroIScene *_target);
	~Box();

	virtual void Update(float eTime);
	virtual void Render();
};

