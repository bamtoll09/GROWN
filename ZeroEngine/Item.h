#pragma once
#include <Zero.h>

class Item : public ZeroIScene
{
private:
	int itemNum;
	int save[10];
	bool jumpOn, shootOn, reverseOn, doubleJumpOn, smallOn, theWorldOn;

	void loadSaveFile();
	void saveFile();
public:
	ZeroSprite *item;

	FILE *f;
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

	bool isTheWorldOn();
	void isTheWorldOn(bool tf);
};