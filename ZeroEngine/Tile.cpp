#include "stdafx.h"
#include "Tile.h"


Tile::Tile(Player *_player, int no)
	:leftPushed(false), rightPushed(false)
{

	tileNum = no;
	player = _player;

	switch (tileNum)
	{
	case 1: // Tile1
		tile = new ZeroSprite("Texture/Tile/tile1.png");
		break;

	case 2: // Tile2
		tile = new ZeroSprite("Texture/Tile/tile2.png");
		break;

	case 3: // Tile3
		tile = new ZeroSprite("Texture/Tile/tile3.png");
		break;
	}
	SetWidth(tile->Width());
	SetHeight(tile->Height());
	PushScene(tile);
}

Tile::~Tile()
{
}

void Tile::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	/*if (isLeftPushed())
		player->SetPosX(this->Pos().x - player->Width());
	else if (isRightPushed())
		player->SetPosX(this->Pos().x + this->Width());*/

	/*if (player->Pos().x + player->Width() - 40 >= this->Pos().x && player->Pos().x + 40 <= this->Pos().x + this->Width())
	{
		if (player->Pos().y + player->Height() >= this->Pos().y && player->Pos().y + player->Height() < this->Pos().y + this->Height() / 2)
		{
			player->isOnGround(true);
			player->SetPosY(this->Pos().y - player->Height());
		}
		else if (!rectangleCollision(player, this))
			player->isOnGround(false);
	}*/
}

void Tile::Render()
{
	ZeroIScene::Render();
	tile->Render();
}

void Tile::isLeftPushed(bool tr)
{
	this->leftPushed = tr;
}
void Tile::isRightPushed(bool tr)
{
	this->rightPushed = tr;
}

bool Tile::isLeftPushed()
{
	return this->leftPushed;
}

bool Tile::isRightPushed()
{
	return this->rightPushed;
}

bool Tile::rectangleCollision(Player *_r1, ZeroIScene *_r2) // 플레이어 충돌 판정
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
		R1.top = _r1->Pos().y + _r1->Height() - 10;
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