#pragma once
#include <Zero.h>

class Door : public ZeroIScene
{
private:
	int doorNum;
	bool entered;
public:
	ZeroSprite *door;
public:
	Door(int no);
	~Door();

	virtual void Update(float eTime);
	virtual void Render();

	void isEntered(bool tr);
	bool isEntered();
};

