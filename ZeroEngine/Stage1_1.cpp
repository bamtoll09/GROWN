#include "stdafx.h"
#include "Stage1_1.h"

Stage1_1::Stage1_1()
	:bulletTime(0.f), theWorld(0.f), isTheWorlded(false), db(0), speed(300), play(true), playTime(0.f)
{
	f = fopen("Save\\save.dat", "r");

	for (int i = 0; i < 7; i++)
		fscanf(f, "%d", &save[i]);

	if (save[6] != 11)
	{
		save[6] = 11;

		fclose(f);

		f = fopen("Save\\save.dat", "w");

		fprintf(f, "%d %d %d %d %d %d %d", save[0], save[1], save[2], save[3], save[4], save[5], save[6]);
	}
	fclose(f);

	app = ZeroApp;
	in = ZeroInputMgr;
	camera = ZeroCameraMgr;
	sound = ZeroSoundMgr;
	sound->PushSound("Sound/jump.mp3", "jumpSound");
	sound->PushSound("Sound/doublejump.mp3", "djumpSound");
	sound->PushSound("Sound/stage1.mp3", "bgm");
	sound->Play("bgm");

	bg = new ZeroSprite("Texture/BackGround/stage1.png");

	m_pPlayer = new Player();
	m_pPlayer->MaxLeft = 0;
	m_pPlayer->MaxRight = bg->Width() - m_pPlayer->Width();
	m_pPlayer->SetPos(46, 814);

	jItem = new Item(1);

	for (int i = 0; i < 21; i++)
	{
		tile0[i] = new Tile(m_pPlayer, 1);
		tile0[i]->SetPos(i * 80, bg->Height() - 80);
		PushScene(tile0[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		tile1[i] = new Tile(m_pPlayer, 1);
		tile1[i]->SetPos(i * 80, 616);
		PushScene(tile1[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		tile2[i] = new Tile(m_pPlayer, 1);
		tile2[i]->SetPos(416 + i * 80, 488);
		PushScene(tile2[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		tile3[i] = new Tile(m_pPlayer, 1);
		tile3[i]->SetPos(432 + i * 80, 709);
		PushScene(tile3[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		tile4[i] = new Tile(m_pPlayer, 1);
		tile4[i]->SetPos(832 + i * 80, 408);
		PushScene(tile4[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		tile5[i] = new Tile(m_pPlayer, 1);
		tile5[i]->SetPos(1214 + i * 80, 304);
		PushScene(tile5[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		ladder[i] = new Ladder(1);
		ladder[i]->SetPos(689, 709 + i * 80);
		PushScene(ladder[i]);
	}

	door[0] = new Door(1);
	door[0]->SetPos(46, 814);

	door[1] = new Door(3);
	door[1]->SetPos(1368, tile5[0]->Pos().y - door[1]->Height());

	switcH = new Switch(m_pPlayer, 1);
	switcH->SetPos(1248, bg->Height() - 80 - switcH->Height());

	PushScene(bg);
	PushScene(m_pPlayer);
	PushScene(jItem);
	PushScene(door[0]);
	PushScene(door[1]);
	PushScene(switcH);

	camera->SetCameraOn();
	camera->SetScreen(bg->Width(), bg->Height());
	camera->SetTarget(m_pPlayer);
}


Stage1_1::~Stage1_1()
{
}

void Stage1_1::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	bulletTime += eTime;
	playTime += eTime;

	if (play && playTime > 35.f)
	{
		sound->Play("bgm");
		playTime = 0.f;
	}

	if (!m_pPlayer->isChange()) // 중력이 바뀌는 중이 아닐 때
	{
		if (in->GetKey('A') == INPUTMGR_KEYDOWN || in->GetKey(VK_LEFT) == INPUTMGR_KEYDOWN) // 플레이어 '좌'이동
			m_pPlayer->move->Start();
		if (in->GetKey('A') == INPUTMGR_KEYON || in->GetKey(VK_LEFT) == INPUTMGR_KEYON/* || (player1 -> IsConnected() && player1 -> GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)*/)
		{
			//printf("left moving\n");
			if (!m_pPlayer->move->IsRunning())
				m_pPlayer->move->Start();
			m_pPlayer->Move(-1 * speed * eTime);
		}
		if (in->GetKey('A') == INPUTMGR_KEYUP || in->GetKey(VK_LEFT) == INPUTMGR_KEYUP)
			m_pPlayer->move->Stop();

		if (in->GetKey('D') == INPUTMGR_KEYDOWN || in->GetKey(VK_RIGHT) == INPUTMGR_KEYDOWN) // 플레이어 '우'이동
			m_pPlayer->move->Start();
		if (in->GetKey('D') == INPUTMGR_KEYON || in->GetKey(VK_RIGHT) == INPUTMGR_KEYON/* || (player1 -> IsConnected() && player1 -> GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)*/)
		{
			//printf("right moving\n");
			if (!m_pPlayer->move->IsRunning())
				m_pPlayer->move->Start();
			m_pPlayer->Move(speed * eTime);
		}
	}

	if (in->GetKey('W') == INPUTMGR_KEYDOWN || in->GetKey('W') == INPUTMGR_KEYON || in->GetKey(VK_UP) == INPUTMGR_KEYDOWN || in->GetKey(VK_UP) == INPUTMGR_KEYON/* || (player1 -> IsConnected() && player1 -> GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)*/)
	{
		if (m_pPlayer->Pos().y + m_pPlayer->Height() > ladder[0]->Pos().y + 10)
			m_pPlayer->Climb(-1 * (speed - 100) * eTime);
	}

	if (!m_pPlayer->isOnGround() && in->GetKey('S') == INPUTMGR_KEYDOWN || in->GetKey('S') == INPUTMGR_KEYON || in->GetKey(VK_DOWN) == INPUTMGR_KEYDOWN || in->GetKey(VK_DOWN) == INPUTMGR_KEYON/* || (player1 -> IsConnected() && player1 -> GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)*/)
	{
		m_pPlayer->Climb((speed - 100) * eTime);
	}

	if (jItem->isJumpOn()) // 점프 아이템을 먹었을 경우
	{
		if ((!m_pPlayer->isDoubleJump() && m_pPlayer->JumpNum < 1) || (m_pPlayer->isDoubleJump() && m_pPlayer->JumpNum < 2)) // 점프를 할 수 있을 경우
		{
			if (!m_pPlayer->isClimb() && in->GetKey(VK_SPACE) == INPUTMGR_KEYDOWN/* || (player1 -> IsConnected() && player1 -> GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)*/) // 플레이어 점프 하기
			{
				m_pPlayer->JumpNum++;

				if (m_pPlayer->JeTime != 0)
					m_pPlayer->JeTime = 0;

				m_pPlayer->isJump(true);
				m_pPlayer->isFall(false);

				if (m_pPlayer->JumpNum == 1)
					sound->Play("jumpSound");
				else if (m_pPlayer->JumpNum == 2)
					sound->Play("djumpSound");
			}
			if (!m_pPlayer->isClimb() && in->GetKey(VK_SPACE) == INPUTMGR_KEYON)
			{
				if (!m_pPlayer->isFall())
					m_pPlayer->isJump(true);
			}

			if (!m_pPlayer->isClimb() && in->GetKey(VK_SPACE) == INPUTMGR_KEYUP)
			{ 			m_pPlayer->isJump(false);
				m_pPlayer->isFall(true);
			}
		}
	}

	if (jItem->isDoubleJumpOn()) // 더블 점프 아이템을 먹었을 경우
		m_pPlayer->isDoubleJump(true);

	if (rectangleCollision(m_pPlayer, ladder[0]) || rectangleCollision(m_pPlayer, ladder[1]) || rectangleCollision(m_pPlayer, ladder[2]) || rectangleCollision(m_pPlayer, ladder[3])) // 플레이어와 사다리 충돌
		m_pPlayer->isClimb(true);
	else
		m_pPlayer->isClimb(false);

	if (m_pPlayer->Pos().x + m_pPlayer->Width() - 40 >= tile5[0]->Pos().x && m_pPlayer->Pos().x + 40 <= tile5[3]->Pos().x + tile5[0]->Width()
		&& m_pPlayer->Pos().y + m_pPlayer->Height() >= tile5[0]->Pos().y && m_pPlayer->Pos().y + m_pPlayer->Height() < tile5[0]->Pos().y + tile5[0]->Height() / 2) // 5
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(tile5[0]->Pos().y - m_pPlayer->Height());
	}
	else if (m_pPlayer->Pos().x + m_pPlayer->Width() - 40 >= tile4[0]->Pos().x && m_pPlayer->Pos().x + 40 <= tile4[3]->Pos().x + tile4[0]->Width()
		&& m_pPlayer->Pos().y + m_pPlayer->Height() >= tile4[0]->Pos().y && m_pPlayer->Pos().y + m_pPlayer->Height() < tile4[0]->Pos().y + tile4[0]->Height() / 2) // 4
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(tile4[0]->Pos().y - m_pPlayer->Height());
	}
	else if (m_pPlayer->Pos().x + m_pPlayer->Width() - 40 >= tile3[0]->Pos().x && m_pPlayer->Pos().x + 40 <= tile3[3]->Pos().x + tile3[0]->Width()
		&& m_pPlayer->Pos().y + m_pPlayer->Height() >= tile3[0]->Pos().y && m_pPlayer->Pos().y + m_pPlayer->Height() < tile3[0]->Pos().y + tile3[0]->Height() / 2) // 3
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(tile3[0]->Pos().y - m_pPlayer->Height());
	}
	else if (m_pPlayer->Pos().x + m_pPlayer->Width() - 40 >= tile2[0]->Pos().x && m_pPlayer->Pos().x + 40 <= tile2[3]->Pos().x + tile2[0]->Width()
		&& m_pPlayer->Pos().y + m_pPlayer->Height() >= tile2[0]->Pos().y && m_pPlayer->Pos().y + m_pPlayer->Height() < tile2[0]->Pos().y + tile2[0]->Height() / 2) // 2
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(tile2[0]->Pos().y - m_pPlayer->Height());
	}
	else if (m_pPlayer->Pos().x + m_pPlayer->Width() - 40 >= tile1[0]->Pos().x && m_pPlayer->Pos().x + 40 <= tile1[4]->Pos().x + tile1[0]->Width()
		&& m_pPlayer->Pos().y + m_pPlayer->Height() >= tile1[0]->Pos().y && m_pPlayer->Pos().y + m_pPlayer->Height() < tile1[0]->Pos().y + tile1[0]->Height() / 2) // 1
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(tile1[0]->Pos().y - m_pPlayer->Height());
	}
	else if (m_pPlayer->Pos().x + m_pPlayer->Width() - 40 >= tile0[0]->Pos().x && m_pPlayer->Pos().x + 40 <= tile0[20]->Pos().x + tile0[0]->Width()
		&& m_pPlayer->Pos().y + m_pPlayer->Height() >= tile0[0]->Pos().y && m_pPlayer->Pos().y + m_pPlayer->Height() < tile0[0]->Pos().y + tile0[0]->Height() / 2) // 바닥
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(tile0[0]->Pos().y - m_pPlayer->Height());
	}
	else
		m_pPlayer->isOnGround(false);

	for (int i = 0; i < 2; i++)
	{
		if (rectangleCollision(m_pPlayer, door[i]))
		{
			if (in->GetKey('W') == INPUTMGR_KEYDOWN || in->GetKey(VK_UP) == INPUTMGR_KEYDOWN)
			{
				door[i]->isEntered(true);
				sound->Stop("jumpSound");
				sound->Stop("djumpSound");
				sound->Stop("bgm");
			}
		}
	}
}

void Stage1_1::Render()
{
	ZeroIScene::Render();
	
	bg->Render();

	for (int i = 0; i < 21; i++)
		tile0[i]->Render();
	for (int i = 0; i < 5; i++)
		tile1[i]->Render();
	for (int i = 0; i < 4; i++)
		tile2[i]->Render();
	for (int i = 0; i < 4; i++)
		tile3[i]->Render();
	for (int i = 0; i < 4; i++)
		tile4[i]->Render();
	for (int i = 0; i < 4; i++)
		tile5[i]->Render();

	for (int i = 0; i < 4; i++)
		ladder[i]->Render();

	for (int i = 0; i < 2; i++)
		door[i]->Render();

	switcH->Render();

	m_pPlayer->Render();
}

bool Stage1_1::rectangleCollision(Player *_r1, ZeroIScene *_r2) // 플레이어 충돌 판정
{
	if (_r1->isSmall()) // 작아졌을 때
	{
		R1.left = _r1->Pos().x + 50;
		R1.top = _r1->Pos().y + _r1->Height() / 2;
		R1.right = _r1->Pos().x + _r1->Width() - 50;
		R1.bottom = _r1->Pos().y + _r1->Height();
	}
	else // 원래대로 일 때
	{
		R1.left = _r1->Pos().x + 40;
		R1.top = _r1->Pos().y;
		R1.right = _r1->Pos().x + _r1->Width() - 40;
		R1.bottom = _r1->Pos().y + _r1->Height();
	}

	R2.left = _r2->Pos().x;
	R2.top = _r2->Pos().y;
	R2.right = _r2->Pos().x + _r2->Width();
	R2.bottom = _r2->Pos().y + _r2->Height();

	if (IntersectRect(&temp, &R1, &R2))
		return true;
	else
		return false;
}