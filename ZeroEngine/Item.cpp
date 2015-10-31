#include "stdafx.h"
#include "Item.h"
#include "GameScene.h"
#include "Player.h"

Item::Item(int no)
	:itemNum(0), jumpOn(false), shootOn(false), reverseOn(false), doubleJumpOn(false), smallOn(false)
{
	this -> itemNum = no;

	switch (itemNum)
	{
	case 1: // Jobject
		item = new ZeroSprite("Texture/Item/JumpBook.png");
		break;

	case 2: // Bobject
		item = new ZeroSprite("exresource/GObject.jpg");
		break;

	case 3: // Robject
		item = new ZeroSprite("exresource/RObject.jpg");
		break;

	case 4: // DJobject
		item = new ZeroSprite("exresource/DJObject.jpg");
		break;

	case 5: // Sobject
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

	if (jumpOn || shootOn || reverseOn || doubleJumpOn || smallOn)
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

bool Item::isDoubleJumpOn()
{
	return this->doubleJumpOn;
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

void Item::isDoubleJumpOn(bool tf)
{
	doubleJumpOn = tf;
}


void Item::isSmallOn(bool tf)
{
	smallOn = tf;
}