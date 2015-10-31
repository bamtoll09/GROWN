#pragma once
#include <Zero.h>
#include "Door.h"
#include "Player.h"
#include "Tile.h"

class MapMaker : public ZeroIScene
{
private:
	FILE *map;
	int stage;
	int w, h;
	int n, o;
public:
	Player *player;
	Tile *border[1500];
	Door *door[5];
public:
	MapMaker(int _stage, int _w, int _h, Player *_player, Door *_door[5], Tile *_border[1500] = NULL);
	~MapMaker();

	int stages[500][500];

	virtual void Update(float eTime);
	virtual void Render();
};

