#pragma once
#include <Zero.h>
#include <Windows.h>

class Intersect : public ZeroIScene
{
private:
	float r1_x, r1_y, r2_x, r2_y;
	bool state;
public:
	ZeroIScene *r1, *r2;
public:
	Intersect(ZeroIScene *_r1, ZeroIScene *_r2);
	~Intersect(void);

	virtual void Update(float eTime);
	virtual void Render();

	void isIntersected(bool tr);
	bool isIntersected();

	RECT R1, R2, temp;

	void circleCollision(ZeroIScene *_r1, ZeroIScene *_r2);
};