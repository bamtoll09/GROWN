#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet(void)
	:available(true), speed(500.f), update(true)
{
	bullet = new ZeroSprite("%s", "exresource/bullet.png");
	PushScene(bullet);
}


Bullet::~Bullet(void)
{
}

void Bullet::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	if (update)
	{
		if (this->Pos().x >= 3072 || this->Pos().x <= -25)
			SetErase(true);
		 
		this->AddPosX(speed * eTime);
	}
}

void Bullet::Render()
{
	ZeroIScene::Render();

	bullet -> Render();
}