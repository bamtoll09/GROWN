#pragma once
#include <Zero.h>
#include "Object.h"

//#include "CXBOXController.h"

class GameScene : public ZeroIScene
{
private:
	int i, _i, db;
	float bulletTime, r1_x, r1_y, r2_x, r2_y, l, theWorld;
	float speed;
	float SeTime;
	float jumpH;
	float maxJumpH;
	bool isTheWorlded;

	void PushBullet(float x, float y);
	void boxCollision(Player *_r1, Box *_r2);
	void tileCollision(Player *_r1, Tile *_r2);
	//bool circleCollision(Player *r1, ZeroIScene *r2);
	bool rectangleCollision(Player *_r1, ZeroIScene *_r2);
	bool rectangleCollision(Bullet *_r1, ZeroIScene *_r2);
private:
	ZeroApplication *app;
	ZeroInputManager *in;
	ZeroCameraManager *camera;
	ZeroSoundManager *sound;

	//ZeroSprite *a, *b, *c;
	//ZeroSprite *gradient;
	ZeroSprite *bg1, *bg2, *bg3, *TW, *GRAY;
	
	Player *m_pPlayer;
	Bullet *bullet[5];
	Monster *monster;
	Item *jItem, *gItem, *rItem, *djItem, *sItem;
	Switch *switcH;
	Box *box1, *box2;
	Ladder *ladder;

	RECT R1, R2, temp, LEFT, RIGHT;

	//CXBOXController *player1;
public:
	GameScene(void);
	~GameScene(void);

	virtual void Update(float eTime);
	virtual void Render();

	//¿©±âµµ!
};
