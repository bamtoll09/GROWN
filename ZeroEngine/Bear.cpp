#include "stdafx.h"
#include "Bear.h"

Bear::Bear()
	:speed(150.f), left(false), moving(false), jumping(false), shooting(false), dying(false), JeTime(0), GeTime(0), jumpH(600)
{
	f = fopen("Save\\save.dat", "r");

	for (int i = 0; i < 7; i++)
		fscanf(f, "%d", &save[i]);

	fclose(f);

	normal = new ZeroSprite("Texture/Bear/bear_1.png");

	footPrint = new ZeroSprite("Texture/Bear/footprint.png");

	move = new ZeroAnimation(1.f);
	move->PushSprite("Texture/Bear/bear1.png");
	move->PushSprite("Texture/Bear/bear2.png");
	move->PushSprite("Texture/Bear/bear3.png");

	down = new ZeroAnimation(3.f);
	down->PushSprite("Texture/Bear/bear_2.png");
	down->PushSprite("Texture/Bear/bear_3.png");
	down->PushSprite("Texture/Bear/bear_4.png");

	PushScene(normal);
	PushScene(move);
	PushScene(down);
	PushScene(footPrint);
}

Bear::~Bear()
{
}

void Bear::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	if (left)
		this->SetScale(-1, 1);
	else
		this->SetScale(1, 1);

	time += eTime;

	if (time > 1.f && !shooting)
		shooting = true;

	if (shooting)
	{
		GeTime += eTime;
		if (GeTime >= 0.5f)
		{
			shooting = false;
			GeTime = 0.f;
		}
	}

	if (this->Pos().x <= 1110 && this->Pos().y == 985)
		this->AddPosX(speed * eTime);
	else if (this->Pos().y >= 704 - this->Height())
		this->AddPosY((speed - 100) * eTime);
	else if (!left)
		left = true;

	if (this->Pos().x > 20 && this->Pos().y <= 704)
		this->AddPosX(-1 * speed * eTime);
	else if (this->Pos().x <= 20 && this->Pos().y == 704)
	{
		if (time > 7.f)
			SetErase(true);
	}

	if (!jumping && (this->Pos().x <= 949 || this->Pos().x <= 597 || this->Pos().x <= 261))
	{
		if ((jumpH - JeTime) >= 0.f && JeTime < 650.f)
		{
			this->AddPosY(-1 * (jumpH - JeTime) * eTime);
			JeTime += 30.f;
		}
		else
		{
			jumping = false;
			falling = true;
		}

	}

	if (falling)
	{
		if (save[6] == 12)
		{
			if (this->Pos().y < 704 - this->Height())
			{
				this->AddPosY((jumpH - JeTime) * eTime);
				JeTime -= 30.f;
			}
		}
		else if (save[6] == 11)
		{
			if (this->Pos().y < 1152 - 80 - this->Height())
			{
				this->AddPosY((jumpH - JeTime) * eTime);
				JeTime -= 30.f;
			}
		}

		if (this->Pos().y >= 704)
		{
			falling = false;
			this->SetPosY(704);
		}

	}
}

void Bear::Render()
{
	ZeroIScene::Render();

	if (moving)
		move->Render();

	else if (dying)
		down->Render();

	else
		normal->Render();
}

void Bear::Move(float _dx)
{
	left = (bool)(_dx <= 0);
	this->AddPosX(_dx);
	moving = true;
}