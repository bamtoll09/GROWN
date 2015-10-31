#include "stdafx.h"
#include "Bear.h"

Bear::Bear()
	:speed(150.f), left(false), moving(false), shooting(false), dying(false)
{
	normal = new ZeroSprite("Texture/Bear/bear_1");

	footPrint = new ZeroSprite("Texture/Bear/footprint");

	move = new ZeroAnimation(1.f);
	move->PushSprite("Texture/Bear/bear1");
	move->PushSprite("Texture/Bear/bear2");
	move->PushSprite("Texture/Bear/bear3");

	down = new ZeroAnimation(3.f);
	down->PushSprite("Texture/Bear/bear_2");
	down->PushSprite("Texture/Bear/bear_3");
	down->PushSprite("Texture/Bear/bear_4");

	PushScene(normal);
	PushScene(move);
	PushScene(down);
	PushScene(footPrint);
}

Bear::~Bear()
{
}

void Bear::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}

void Bear::Render()
{
	ZeroIScene::Render();

	if (moving)
		move->Render();

	else if (dying)
		down->Render();

	else
		normal->Render();
}

void Bear::Move(float _dx)
{
	left = (bool)(_dx <= 0);
	this->AddPosX(_dx);
	moving = true;
}