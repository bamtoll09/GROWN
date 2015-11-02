#pragma once
#include <Zero.h>
#include "Player.h"

class Ladder : public ZeroIScene
{
private:
	int ladderNum;
public:
	ZeroSprite *ladder;
public:
	Ladder(int no);
	~Ladder();

	virtual void Update(float eTime);
	virtual void Render();
};