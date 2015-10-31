#pragma once
#include <Zero.h>
#include "Çì´õ.h"

class Box : public ZeroIScene
{
private:
	float SeTime;
public:
	ZeroSprite *box;
	Player *player;
public:
	Box(Player *_player);
	~Box();

	virtual void Update(float eTime);
	virtual void Render();
};