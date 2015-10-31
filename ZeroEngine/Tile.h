#pragma once
#include <Zero.h>
#include "Player.h"

class Tile :
	public ZeroIScene
{
private:
	int tileNum;
	bool leftPushed, rightPushed;
public:
	ZeroSprite *tile, * border;

	Player *player;
public:
	Tile(Player *_player, int no);
	~Tile();

	virtual void Update(float eTime);
	virtual void Render();

	void isLeftPushed(bool tr);
	void isRightPushed(bool tr);

	bool isLeftPushed();
	bool isRightPushed();
};