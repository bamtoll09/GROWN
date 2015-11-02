#pragma once
#include <Zero.h>
#include "Object.h"

class Stage1_2 : public ZeroIScene
{
private:
	int i, _i, db;
	int save[7];
	float bulletTime, r1_x, r1_y, r2_x, r2_y, l, theWorld;
	float speed;
	float SeTime;
	float jumpH;
	float maxJumpH;
	float playTime;
	bool isTheWorlded, play;

	void PushBullet(float x, float y);
	void tileCollision(Player *_r1, Tile *_r2);
	bool rectangleCollision(Player *_r1, ZeroIScene *_r2);
	bool rectangleCollision(Bullet *_r1, ZeroIScene *_r2);
public:
	ZeroApplication *app;
	ZeroInputManager *in;
	ZeroCameraManager *camera;
	ZeroSoundManager *sound;

	ZeroSprite *bg;

	Player *m_pPlayer;
	Bullet *bullet[5];
	Tile *tile0[21], *tile1[4], *tile2[3], *tile3[3], *tile4[2];
	Item *jItem;
	Monster *monster;
	Bear *bear;
	Ladder *ladder[4];
	Door *door[2];

	RECT R1, R2, temp, LEFT, RIGHT;
	FILE *f;
public:
	Stage1_2();
	~Stage1_2();

	virtual void Update(float eTime);
	virtual void Render();
};