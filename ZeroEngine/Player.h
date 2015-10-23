#pragma once
#include <Zero.h>

class Player : public ZeroIScene
{
private:
	float scaleX, scaleY;
	bool moving, jumping, falling, shooting, reversing;
public:
	ZeroSprite *normal, *shoot;
	ZeroAnimation *move;
public:
	Player(void);
	~Player(void);

	virtual void Update(float eTime);
	virtual void Render();

	int JumpNum;
	float jumpH, JeTime, GeTime;
	bool left;

	void setScale(float X, float Y);

	void Move(float dx);
	void isJump(bool tr);
	void isFall(bool tr);
	void isShoot(bool tr);
	void isReverse(bool tr);
	bool isJump();
	bool isFall();
	bool isShoot();
	bool isReverse();
};

