#pragma once
#include <Zero.h>
#include "Player.h"

class Box : public ZeroIScene
{
private:
	float SeTime;
	bool leftPushed, rightPushed, onGround;
public:
	ZeroSprite *box;
	Player *player;
public:
	Box(Player *_player);
	~Box();

	virtual void Update(float eTime);
	virtual void Render();

	void isLeftPushed(bool tr);
	void isRightPushed(bool tr);
	void isOnGround(bool tr);

	bool isLeftPushed();
	bool isRightPushed();
	bool isOnGround();
};