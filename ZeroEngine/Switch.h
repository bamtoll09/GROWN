#pragma once
#include <Zero.h>

class Switch : public ZeroIScene
{
private:
	int switchNum;
	bool state;
public:
	ZeroSprite *body, *pressed, *stick;
public:
	Switch(int no);
	~Switch();

	virtual void Update(float eTime);
	virtual void Render();

	void isOn(bool tr);
	bool isOn();
};