#pragma once
#include <Zero.h>
#include "Object.h"

class Stage1_1 : public ZeroIScene
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
	Tile *tile0[21], *tile1[5], *tile2[4], *tile3[4], *tile4[4], *tile5[4];
	Item *jItem;
	Switch *switcH;
	Ladder *ladder[4];
	Door *door[2];

	RECT R1, R2, temp, LEFT, RIGHT;
	FILE *f;
public:
	Stage1_1();
	~Stage1_1();

	virtual void Update(float eTime);
	virtual void Render();
};

