#pragma once
#include <Zero.h>
#include "Çì´õ.h"

class Tile :
	public ZeroIScene
{
private:
	int tileNum;
public:
	ZeroSprite *tile, * border;
public:
	Tile(Player player, int no);
	~Tile();

	virtual void Update(float eTime);
	virtual void Render();
};