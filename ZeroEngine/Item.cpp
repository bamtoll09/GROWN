#include "stdafx.h"
#include "Item.h"
#include "GameScene.h"
#include "Player.h"

Item::Item(int no)
	:jumpOn(false), shootOn(false), reverseOn(false), smallOn(false)
{
	this -> itemNum = no;

	switch (itemNum)
	{
	case 1: // Jobject
		item = new ZeroSprite("Texture/Item/JumpBook.png");
		break;

	case 2: // Boject
		item = new ZeroSprite("exresource/GObject.jpg");
		break;

	case 3:
		item = new ZeroSprite("exresource/peanutMushroom.png");
		break;
	}

	this->SetWidth(item->Width());
	this->SetHeight(item->Height());
	this->SetScalingCenter(Width() / 2, Height() / 2);
	PushScene(item);
}

Item::~Item(void)
{
}

void Item::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	if (jumpOn || shootOn || reverseOn || smallOn)
		this->SetErase(true);
}

void Item::Render()
{
	ZeroIScene::Render();
	item->Render();
}

bool Item::isJumpOn()
{
	return this->jumpOn;
}

bool Item::isShootOn()
{
	return this->shootOn;
}

bool Item::isReverseOn()
{
	return this->reverseOn;
}

bool Item::isSmallOn()
{
	return this->smallOn;
}

void Item::isJumpOn(bool tf)
{
	jumpOn = tf;
}

void Item::isShootOn(bool tf)
{
	shootOn = tf;
}

void Item::isReverseOn(bool tf)
{
	reverseOn = tf;
}

void Item::isSmallOn(bool tf)
{
	smallOn = tf;
}