#include "stdafx.h"
#include "Intersect.h"
#include <math.h>

Intersect::Intersect(ZeroIScene *_r1, ZeroIScene *_r2)
{
}


Intersect::~Intersect(void)
{
}

void Intersect::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}

void Intersect::Render()
{
	ZeroIScene::Render();
}

bool Intersect::isIntersected()
{
	return true;
}

void Intersect::circleCollision(ZeroIScene *_r1, ZeroIScene *_r2)
{
}