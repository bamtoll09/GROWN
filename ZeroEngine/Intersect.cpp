#include "stdafx.h"
#include "Intersect.h"
#include <math.h>

Intersect::Intersect(ZeroIScene *_r1/* = NULL*/, ZeroIScene *_r2/* = NULL*/, ZeroSprite *_r3/* = NULL*/, bool _Circle/* = false*/, ZeroInputManager *_in/* = NULL*/)
	: state(false)
{
	r1 = _r1;
	r2 = _r2;
	r3 = _r3;
	circle = _Circle;
	cursor = _in;
	CURSOR = cursor->GetClientRect();
}

Intersect::~Intersect(void)
{
}

void Intersect::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	if (circle)
		circleCollision(r1, r2);
	else if (cursor == NULL)
		rectangleCollision(r1, r2);
	else
		cursorCollision(&CURSOR, r3);
}

void Intersect::Render()
{
	ZeroIScene::Render();
}

bool Intersect::isIntersected()
{
	return this->state;
}

bool Intersect::rectangleCollision(ZeroIScene *_r1, ZeroIScene *_r2)
{
	R1.left = _r1->Pos().x + 40;
	R1.top = _r1->Pos().y;
	R1.right = _r1->Pos().x + _r1->Width() - 40;
	R1.bottom = _r1->Pos().y + _r1->Height();

	R2.left = _r2->Pos().x;
	R2.top = _r2->Pos().y;
	R2.right = _r2->Pos().x + _r2->Width();
	R2.bottom = _r2->Pos().y + _r2->Height();

	if (IntersectRect(&temp, &R1, &R2))
		return state = true;
	else
		return state = false;
}

bool Intersect::circleCollision(ZeroIScene *_r1, ZeroIScene *_r2)
{
	r1_x = r1->Pos().x + r1->Width() / 2;
	r1_y = r1->Pos().y + r1->Height() / 2;
	r2_x = r2->Pos().x + r2->Width() / 2;
	r2_y = r2->Pos().y + r2->Height() / 2;

	//printf("r1_x : %f\tr1_y : %f\nr2_x : %f\tr2_y : %f\nl : %f\n", r1_x, r1_y, r2_x, r2_y, l);

	l = sqrtf(powf((r2_x - r1_x), 2) + pow((r2_y - r1_y), 2));

	if (l < 0)
		l *= -1;

	if (r1->Width() / 2 - 20 + r2->Width() / 2 >= l)
		return state = true;
	else
		return state = false;
}

bool Intersect::cursorCollision(RECT *_r1, ZeroSprite *_r2)
{
	R1 = *_r1;

	R2.left = _r2->Pos().x;
	R2.top = _r2->Pos().y;
	R2.right = _r2->Pos().x + _r2->Width();
	R2.bottom = _r2->Pos().y + _r2->Height();

	if (IntersectRect(&temp, &R1, &R2))
		return state = true;
	else
		return state = false;
}