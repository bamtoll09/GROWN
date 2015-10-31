#pragma once
#include <Zero.h>
#include "Çì´õ.h"

class Ladder : public ZeroIScene
{
public:
	ZeroSprite *ladder;
	Player player;
public:
	Ladder(Player _player);
	~Ladder();

	virtual void Update(float eTime);
	virtual void Render();
};

