#include "stdafx.h"
#include "Tile.h"


Tile::Tile(Player *_player, int no)
{

	tileNum = no;
	player = _player;

	switch (tileNum)
	{
	case 1: // Tile
		tile = new ZeroSprite("");
		break;

	case 2: // Border
		tile = new ZeroSprite("Texture/Tile/border.jpg");
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

	if (isLeftPushed())
		player->SetPosX(this->Pos().x - player->Width());
	else if (isRightPushed())
		player->SetPosX(this->Pos().x + this->Width());
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