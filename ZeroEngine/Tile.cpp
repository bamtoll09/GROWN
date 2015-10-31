#include "stdafx.h"
#include "Tile.h"


Tile::Tile(Player player, int no)
{
	tileNum = no;

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
}

void Tile::Render()
{
	ZeroIScene::Render();
	tile->Render();
}