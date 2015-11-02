#include "stdafx.h"
#include "Switch.h"


Switch::Switch(Player *_player, int no)
	:state(false)
{
	player = _player;
	this->switchNum = no;

	switch (switchNum)
	{
	case 1:
		body = new ZeroSprite("Texture/Switch/switch.png");
		pressed = new ZeroSprite("Texture/Switch/switch-pressed.png");
		PushScene(pressed);
		break;
		
	case 2:
		body = new ZeroSprite("Texture/Switch/switch2-body.png");
		stick = new ZeroSprite("Texture/Switch/switch2-stick.png");
		stick->SetRotCenter(stick->Width() / 2, stick->Height() + 34);
		PushScene(stick);
		break;
	}

	this->SetWidth(body->Width());
	this->SetHeight(body->Height());
	this->SetScalingCenter(Width() / 2, Height() / 2);
	PushScene(body);
}


Switch::~Switch()
{
}

void Switch::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	switch (switchNum)
	{
	case 1:
		if (rectangleCollision(player, this))
			state = true;
		break;

	case 2:
		stick->SetPos(body->Pos().x + body->Width() / 2 - stick->Width() / 2, body->Pos().y + 2); // 스위치 막대 위치 설정

		if (state) // 스위치 막대 각도 설정
			stick->SetRot(45);
		else
			stick->SetRot(-45);

		if (rectangleCollision(player, this))
			state = !state;
		break;
	}
}

void Switch::Render()
{
	ZeroIScene::Render();
	switch (switchNum)
	{
	case 1:
		if (state)
			pressed->Render();
		else
			body->Render();
		break;

	case 2:
		body->Render();
		stick->Render();
		break;
	}
}

void Switch::isOn(bool tr)
{
	this->state = tr;
}

bool Switch::isOn()
{
	return this->state;
}

bool Switch::rectangleCollision(Player *_r1, ZeroIScene *_r2) // 플레이어 충돌 판정
{
	if (_r1->isSmall()) // 작아졌을 때
	{
		R1.left = _r1->Pos().x + 50;
		R1.top = _r1->Pos().y + _r1->Height() / 2;
		R1.right = _r1->Pos().x + _r1->Width() - 50;
		R1.bottom = _r1->Pos().y + _r1->Height();
	}
	else // 원래대로 일 때
	{
		R1.left = _r1->Pos().x + 40;
		R1.top = _r1->Pos().y;
		R1.right = _r1->Pos().x + _r1->Width() - 40;
		R1.bottom = _r1->Pos().y + _r1->Height();
	}

	R2.left = _r2->Pos().x;
	R2.top = _r2->Pos().y;
	R2.right = _r2->Pos().x + _r2->Width();
	R2.bottom = _r2->Pos().y + _r2->Height();

	if (IntersectRect(&temp, &R1, &R2))
		return true;
	else
		return false;
}