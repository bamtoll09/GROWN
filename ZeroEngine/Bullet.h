#pragma once
#include <Zero.h>

class Bullet : public ZeroIScene
{
public:
	ZeroSprite *bullet;
public:
	Bullet(void);
	~Bullet(void);

	virtual void Update(float eTime);
	virtual void Render();

	bool available, update;
	float speed;
};