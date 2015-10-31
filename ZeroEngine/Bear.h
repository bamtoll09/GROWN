#pragma once
#include <Zero.h>

class Bear :
	public ZeroIScene
{
private:
	float speed;
	bool left, moving, shooting, dying;

	void Move(float _dx);
public:
	ZeroSprite *normal, *footPrint;
	ZeroAnimation *move, *down;
public:
	Bear();
	~Bear();

	virtual void Update(float eTime);
	virtual void Render();
};