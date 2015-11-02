#pragma once
#include <Zero.h>

class Player : public ZeroIScene
{
private:
	int save[7];
	float scaleX, scaleY;
	bool onBox, onGround;
	bool moving, jumping, falling, shooting, reversing, doubleJumping, smalling, changing, climbing, reading, downJumping;
public:
	ZeroSoundManager *sound;

	ZeroSprite *normal, *shoot, *fall, *jump, *jump2, *read;
	ZeroAnimation *move;

	FILE *f;
public:
	Player(void);
	~Player(void);

	virtual void Update(float eTime);
	virtual void Render();

	int JumpNum, MaxLeft, MaxRight;
	float jumpH, JeTime, GeTime;
	bool left;

	void setScale(float X, float Y);

	void Move(float dx);
	void Climb(float dx);
	void isMove(bool tr);
	void isJump(bool tr);
	void isDoubleJump(bool tr);
	void isFall(bool tr);
	void isShoot(bool tr);
	void isReverse(bool tr);
	void isSmall(bool tr);
	void isChange(bool tr);
	void isClimb(bool tr);
	void isRead(bool tr);
	void isDownJump(bool tr);
	void isOnBox(bool tr);
	void isOnGround(bool tr);

	bool isMove();
	bool isJump();
	bool isFall();
	bool isShoot();
	bool isReverse();
	bool isDoubleJump();
	bool isSmall();
	bool isChange();
	bool isClimb();
	bool isRead();
	bool isDownJump();
	bool isOnBox();
	bool isOnGround();
};

