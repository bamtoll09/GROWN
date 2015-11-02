#pragma once
#include <Zero.h>
#include "Player.h"

class Switch : public ZeroIScene
{
private:
	int switchNum;
	bool state;

	bool rectangleCollision(Player *_r1, ZeroIScene *_r2);
public:
	ZeroSprite *body, *pressed, *stick;

	Player *player;

	RECT R1, R2, temp;
public:
	Switch(Player *_player, int no);
	~Switch();

	virtual void Update(float eTime);
	virtual void Render();

	void isOn(bool tr);
	bool isOn();
};