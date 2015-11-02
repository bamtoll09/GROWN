#pragma once
#include <Zero.h>

class Bear :
	public ZeroIScene
{
private:
	int save[7];
	float speed, time, JeTime, GeTime, jumpH;
	bool left, moving, jumping, shooting, dying, falling;

	void Move(float _dx);
public:
	ZeroSprite *normal, *footPrint;
	ZeroAnimation *move, *down;

	FILE *f;
public:
	Bear();
	~Bear();

	virtual void Update(float eTime);
	virtual void Render();
};