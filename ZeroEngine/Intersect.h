#pragma once
#include <Zero.h>
#include <Windows.h>

class Intersect : public ZeroIScene
{
private:
	float r1_x, r1_y, r2_x, r2_y, l;
	bool state, circle;
public:
	ZeroIScene *r1, *r2;
	ZeroInputManager *cursor;
public:
	Intersect(ZeroIScene *_r1, ZeroIScene *_r2, bool _Circle = false, ZeroInputManager *_in = NULL);
	~Intersect(void);

	virtual void Update(float eTime);
	virtual void Render();

	bool isIntersected();

	RECT R1, R2, CURSOR, temp;

	bool rectangleCollision(ZeroIScene *_r1, ZeroIScene *_r2);
	bool circleCollision(ZeroIScene *_r1, ZeroIScene *_r2);
	bool cursorCollision(RECT _r1, ZeroIScene *_r2);
};