#include "stdafx.h"
#include "Switch.h"


Switch::Switch(int no)
	:state(false)
{
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
	if (switchNum == 2)
	{
		stick->SetPos(body->Pos().x + body->Width() / 2 - stick->Width() / 2, body->Pos().y + 2); // 스위치 막대 위치 설정

		if (state) // 스위치 막대 각도 설정
			stick->SetRot(45);
		else
			stick->SetRot(-45);
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