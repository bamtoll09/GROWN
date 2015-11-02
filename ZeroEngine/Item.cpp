#include "stdafx.h"
#include "Item.h"
#include "GameScene.h"
#include "Player.h"

Item::Item(int no)
	:itemNum(0), jumpOn(false), shootOn(false), reverseOn(false), doubleJumpOn(false), smallOn(false)
{
	f = fopen("Save\\save.dat", "r");

	for (int i = 0; i < 6; i++)
		fscanf(f, "%d", &save[i]);

	fclose(f);

	loadSaveFile();

	this -> itemNum = no;

	switch (itemNum)
	{
	case 1: // Jobject
		item = new ZeroSprite("Texture/Item/bookS1.png");
		break;

	case 2: // Bobject
		item = new ZeroSprite("Texture/Item/bookS2.png");
		break;

	case 3: // Robject
		item = new ZeroSprite("Texture/Item/bookS3.png");
		break;

	case 4: // DJobject
		item = new ZeroSprite("Texture/Item/bookS4.png");
		break;

	case 5: // Sobject
		item = new ZeroSprite("Texture/Item/bookS5.png");
		break;

	case 6:
		item = new ZeroSprite("");
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

	if (jumpOn || shootOn || reverseOn || doubleJumpOn || smallOn || theWorldOn)
		this->SetErase(true);

	loadSaveFile();
	saveFile();
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

bool Item::isTheWorldOn()
{
	return this->theWorldOn;
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

void Item::isTheWorldOn(bool tf)
{
	theWorldOn = tf;
}

void Item::loadSaveFile()
{
	if (save[0] == 1)
		jumpOn = true;
	if (save[1] == 1)
		shootOn = true;
	if (save[2] == 1)
		reverseOn = true;
	if (save[3] == 1)
		doubleJumpOn = true;
	if (save[4] == 1)
		smallOn = true;
	if (save[5] == 1)
		theWorldOn = true;
}

void Item::saveFile()
{
	if (jumpOn)
		save[0] = 1;
	if (shootOn)
		save[1] = 1;
	if (reverseOn)
		save[2] = 1;
	if (doubleJumpOn)
		save[3] = 1;
	if (smallOn)
		save[4] = 1;
	if (theWorldOn)
		save[5] = 1;
}