#pragma once
#include <Zero.h>
#include "헤더.h"

//#include "CXBOXController.h"

class GameScene : public ZeroIScene
{
private:
	int i, _i, db;
	float bulletTime, r1_x, r1_y, r2_x, r2_y, l, theWorld;
	float SeTime;
	float jumpH;
	float maxJumpH;
	bool isTheWorlded;

	void PushBullet(float x, float y);
	bool circleCollision(ZeroIScene *r1, ZeroIScene *r2);
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
	Item *jItem, *gItem, *rItem, *sItem;
	Switch *switcH;
	Box *box;

	//RECT jItemRect, playerRect, tempRect;

	//CXBOXController *player1;
public:
	GameScene(void);
	~GameScene(void);

	virtual void Update(float eTime);
	virtual void Render();

	//여기도!
};
