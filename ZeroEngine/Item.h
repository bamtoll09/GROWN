#pragma once
#include <Zero.h>

class Item : public ZeroIScene
{
private:
	int itemNum;
	bool jumpOn, shootOn, reverseOn, doubleJumpOn, smallOn;
public:
	ZeroSprite *item;
public:
	Item(int no);
	~Item(void);

	virtual void Update(float eTime);
	virtual void Render();

	bool isJumpOn();
	void isJumpOn(bool tf);

	bool isShootOn();
	void isShootOn(bool tf);

	bool isReverseOn();
	void isReverseOn(bool tf);

	bool isDoubleJumpOn();
	void isDoubleJumpOn(bool tf);

	bool isSmallOn();
	void isSmallOn(bool tf);
};