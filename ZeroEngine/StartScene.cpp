#include "stdafx.h"
#include "StartScene.h"


StartScene::StartScene()
	:bulletTime(0.f), theWorld(0.f), isTheWorlded(false), db(0), speed(300)
{
	in = ZeroInputMgr;
	camera = ZeroCameraMgr;
	sound = ZeroSoundMgr;

	bg = new ZeroSprite("Texture/BackGround/all_floor1.png"); // 배경 초기 설정

	m_pPlayer = new Player();

	for (int i = 0; i < 2; i++)
		door[i] = new Door(i + 2);

	for (int i = 0; i < 1308; i++)
		border[i] = new Tile(m_pPlayer, 2);

	start = new MapMaker(00, 93, 290, m_pPlayer, door, border);

	PushScene(bg);
	PushScene(m_pPlayer);
	for (int i = 0; i < 2; i++)
		PushScene(door[i]);
	for (int i = 0; i < 1308; i++)
		PushScene(border[i]);
	PushScene(start);

	camera->SetCameraOn(); // 카메라 초기 설정
	camera->SetScreen(1024, 2900);
	camera->SetTarget(m_pPlayer);
}


StartScene::~StartScene()
{
}

void StartScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}

void StartScene::Render()
{
	ZeroIScene::Render();

	bg->Render();

	m_pPlayer->Render();

	for (int i = 0; IsExistScene(door[i]); i++)
		door[i]->Render();

	for (int i = 0; IsExistScene(border[i]); i++)
		border[i]->Render();
}

void StartScene::tileCollision(Player *_r1, Tile *_r2) // 플레이어와 타일 충돌 판정
{
	if (_r1->isSmall()) // 작아졌을 때
	{
		LEFT.left = _r1->Pos().x + 50; // 왼쪽 RECT
		LEFT.top = _r1->Pos().y + _r1->Height() / 2;
		LEFT.right = _r1->Pos().x + _r1->Width() / 2;
		LEFT.bottom = _r1->Pos().y + _r1->Height();

		RIGHT.left = _r1->Pos().x + _r1->Width() / 2; // 오른쪽 RECT
		RIGHT.top = _r1->Pos().y + _r1->Height() / 2;
		RIGHT.right = _r1->Pos().x + _r1->Width() - 50;
		RIGHT.bottom = _r1->Pos().y + _r1->Height();
	}
	else // 원래대로 일 때
	{
		LEFT.left = _r1->Pos().x + 40; // 왼쪽 RECT
		LEFT.top = _r1->Pos().y;
		LEFT.right = _r1->Pos().x + _r1->Width() / 2;
		LEFT.bottom = _r1->Pos().y + _r1->Height();

		RIGHT.left = _r1->Pos().x + _r1->Width() / 2; // 오른쪽 RECT
		RIGHT.top = _r1->Pos().y;
		RIGHT.right = _r1->Pos().x + _r1->Width() - 40;
		RIGHT.bottom = _r1->Pos().y + _r1->Height();
	}

	R2.left = _r2->Pos().x;
	R2.top = _r2->Pos().y;
	R2.right = _r2->Pos().x + _r2->Width();
	R2.bottom = _r2->Pos().y + _r2->Height();

	if (IntersectRect(&temp, &LEFT, &R2))
	{
		return _r2->isLeftPushed(true);
	}
	else if (IntersectRect(&temp, &RIGHT, &R2))
	{
		return _r2->isRightPushed(true);
	}
	else
	{
		_r2->isLeftPushed(false);
		_r2->isRightPushed(false);
		return;
	}
}