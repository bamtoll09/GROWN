#pragma once
#include <Zero.h>
#include "Object.h"

class StartScene : public ZeroIScene
{
private:
	int i, _i, db, save[7];
	float bulletTime, r1_x, r1_y, r2_x, r2_y, l, theWorld;
	float speed;
	float SeTime;
	float jumpH;
	float maxJumpH;
	bool isTheWorlded;

	void PushBullet(float x, float y);
	bool rectangleCollision(Player *_r1, ZeroIScene *_r2);
	void tileCollision(Player *_r1, Tile *_r2);
private:
	ZeroInputManager *in;
	ZeroCameraManager *camera;
	ZeroSoundManager *sound;

	ZeroSprite *bg;

	Player *m_pPlayer;
	Bullet *bullet[5];
	Item *jItem;
	Ladder *ladder;
	Door *door[5];
	MapMaker *start;

	RECT R1, R2, temp, LEFT, RIGHT;
	FILE *f;
public:
	StartScene();
	~StartScene();

	virtual void Update(float eTime);
	virtual void Render();
};

