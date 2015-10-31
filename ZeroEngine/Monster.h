#pragma once
#include <Zero.h>
#include "Çì´õ.h"

class Monster : public ZeroIScene
{
private:
	int monsterNum;
	float scaleX, scaleY;
	float speed, r1_x, r1_y, r2_x, r2_y, l, dis, moveX, moveY, SeTime;
	bool right, moving, chasing, contacting;
	void perceive(Player *_player);
	void isChased(float _eTime, bool _2d = false);
public:
	ZeroSprite *normal, *attack;
	ZeroAnimation *move, *senseMove;
	Player *player;
public:
	Monster(Player *_player, int no);
	~Monster();

	virtual void Update(float eTime);
	virtual void Render();

	void isContacted(bool tr);
	bool isContacted();
};