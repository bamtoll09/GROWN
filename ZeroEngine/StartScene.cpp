#include "stdafx.h"
#include "StartScene.h"


StartScene::StartScene()
	:bulletTime(0.f), theWorld(0.f), isTheWorlded(false), db(0), speed(300)
{
	f = fopen("Save\\save.dat", "r");

	for (int i = 0; i < 7; i++)
		fscanf(f, "%d", &save[i]);

	if (save[6] != 00)
	{
		save[6] = 00;
		
		fclose(f);

		f = fopen("Save\\save.dat", "w");

		fprintf(f, "%d %d %d %d %d %d %d", save[0], save[1], save[2], save[3], save[4], save[5], save[6]);
	}
	fclose(f);

	in = ZeroInputMgr;
	camera = ZeroCameraMgr;
	sound = ZeroSoundMgr;
	sound->PushSound("Sound/jump.mp3", "jumpSound");
	sound->PushSound("Sound/doublejump.mp3", "djumpSound");

	bg = new ZeroSprite("Texture/BackGround/all_floor1.png"); // 배경 초기 설정

	m_pPlayer = new Player();

	m_pPlayer->MaxLeft = 11;
	m_pPlayer->MaxRight = 880;
	
	jItem = new Item(1);

	ladder = new Ladder(0);

	for (int i = 0; i < 5; i++)
	{
		door[i] = new Door(i + 2);
	}

	start = new MapMaker(00, 93, 290, m_pPlayer, ladder, door);

	m_pPlayer->AddPosY(4);
	door[1]->AddPosX(-6);
	door[2]->AddPosX(-5);
	door[2]->AddPosY(22);
	door[3]->AddPosX(3);
	door[3]->AddPosY(10);
	door[4]->AddPosX(2);
	door[4]->AddPosY(11);

	PushScene(bg);
	PushScene(m_pPlayer);
	PushScene(jItem);
	PushScene(ladder);
	for (int i = 0; i < 5; i++)
		PushScene(door[i]);
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

	bulletTime += eTime;

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
		if (in->GetKey('D') == INPUTMGR_KEYUP || in->GetKey(VK_RIGHT) == INPUTMGR_KEYUP)
		{
			m_pPlayer->move->Stop();
			m_pPlayer->isMove(false);
		}
	}

	if (in->GetKey('W') == INPUTMGR_KEYDOWN || in->GetKey('W') == INPUTMGR_KEYON || in->GetKey(VK_UP) == INPUTMGR_KEYDOWN || in->GetKey(VK_UP) == INPUTMGR_KEYON/* || (player1 -> IsConnected() && player1 -> GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)*/)
	{
		if (m_pPlayer->Pos().y + m_pPlayer->Height() > ladder->Pos().y + 10)
			m_pPlayer->Climb(-1 * (speed - 100) * eTime);
		else
			m_pPlayer->SetPosY(ladder->Pos().y + 10 - m_pPlayer->Height());
	}

	if (!m_pPlayer->isOnGround() && in->GetKey('S') == INPUTMGR_KEYDOWN || in->GetKey('S') == INPUTMGR_KEYON || in->GetKey(VK_DOWN) == INPUTMGR_KEYDOWN || in->GetKey(VK_DOWN) == INPUTMGR_KEYON/* || (player1 -> IsConnected() && player1 -> GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)*/)
	{
		m_pPlayer->Climb((speed - 100) * eTime);
	}

	if (jItem->isJumpOn()) // 점프 아이템을 먹었을 경우
	{
		if ((m_pPlayer->Pos().x == 11 && m_pPlayer->Pos().y + m_pPlayer->Height() == 1490)/* || (m_pPlayer->Pos().x == 880 && m_pPlayer->Pos().y + m_pPlayer->Height() == 2190)*/) // 3층 왼쪽 끝에 있을 때
		{
			if (m_pPlayer->JumpNum < 1) // 점프를 할 수 있을 경우
			{
				if ((in->GetKey('S') == INPUTMGR_KEYON || in->GetKey(VK_DOWN) == INPUTMGR_KEYON) && (in->GetKey(VK_SPACE) == INPUTMGR_KEYDOWN)/* || (player1 -> IsConnected() && player1 -> GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)*/) // 플레이어 점프 하기
				{
 					m_pPlayer->JumpNum++;
					 
					if (m_pPlayer->JeTime != 0)
						m_pPlayer->JeTime = 0;

					m_pPlayer->isOnGround(false);
 					m_pPlayer->isDownJump(true);
					m_pPlayer->isJump(false);
					m_pPlayer->isFall(true);

					if (m_pPlayer->JumpNum == 1)
						sound->Play("jumpSound");
					else if (m_pPlayer->JumpNum == 2)
						sound->Play("djumpSound");
				}
			}
		}

		else if ((!m_pPlayer->isDoubleJump() && m_pPlayer->JumpNum < 1) || (m_pPlayer->isDoubleJump() && m_pPlayer->JumpNum < 2)) // 점프를 할 수 있을 경우
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
				if (!m_pPlayer->isFall())
					m_pPlayer->isJump(true);

			if (!m_pPlayer->isClimb() && in->GetKey(VK_SPACE) == INPUTMGR_KEYUP)
			{
				m_pPlayer->isJump(false);
				m_pPlayer->isFall(true);
			}
		}
	}

	if (jItem->isDoubleJumpOn()) // 더블 점프 아이템을 먹었을 경우
		m_pPlayer->isDoubleJump(true);

	//여기서 부턴 충돌 판정

	//4층 바닥
	if (!m_pPlayer->isClimb() && m_pPlayer->Pos().y + m_pPlayer->Height() >= 792 && m_pPlayer->Pos().y + m_pPlayer->Height() < 812)
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(792 - m_pPlayer->Height());
	}

	//3층 바닥
	else if (!m_pPlayer->isDownJump() && m_pPlayer->Pos().y + m_pPlayer->Height() >= 1490 && m_pPlayer->Pos().y + m_pPlayer->Height() < 1512)
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(1490 - m_pPlayer->Height());
	}

	//3층 계단
	else if (m_pPlayer->Pos().y + m_pPlayer->Height() >= 1685 && m_pPlayer->Pos().y + m_pPlayer->Height() < 1710 && m_pPlayer->Pos().x + 40 < 85) // 위에서 2번째 계단
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(1685 - m_pPlayer->Height());
	}
	else if (m_pPlayer->Pos().y + m_pPlayer->Height() >= 1755 && m_pPlayer->Pos().y + m_pPlayer->Height() < 1780 && m_pPlayer->Pos().x + 40 < 155) // 위에서 3번째 계단
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(1755 - m_pPlayer->Height());
		if (m_pPlayer->Pos().x + 40 <= 85 && m_pPlayer->Pos().y + m_pPlayer->Height() >= 1710)
			m_pPlayer->SetPosX(45);
	}
	else if (m_pPlayer->Pos().y + m_pPlayer->Height() >= 1835 && m_pPlayer->Pos().y + m_pPlayer->Height() < 1860 && (m_pPlayer->Pos().x + 40 >= 75 && m_pPlayer->Pos().x + 40 < 220)) // 위에서 4번째 계단
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(1835 - m_pPlayer->Height());
		if (m_pPlayer->Pos().x + 40 <= 155 && m_pPlayer->Pos().y + m_pPlayer->Height() >= 1780)
			m_pPlayer->SetPosX(115);
	}
	else if (m_pPlayer->Pos().y + m_pPlayer->Height() >= 1912 && m_pPlayer->Pos().y + m_pPlayer->Height() < 1937 && (m_pPlayer->Pos().x + 40 >= 145 && m_pPlayer->Pos().x + 40 < 295)) // 위에서 5번째 계단
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(1912 - m_pPlayer->Height());
		if (m_pPlayer->Pos().x + 40 <= 220 && m_pPlayer->Pos().y + m_pPlayer->Height() >= 1860)
			m_pPlayer->SetPosX(180);
	}
	else if (m_pPlayer->Pos().y + m_pPlayer->Height() >= 1990 && m_pPlayer->Pos().y + m_pPlayer->Height() < 2015 && (m_pPlayer->Pos().x + 40 >= 210 && m_pPlayer->Pos().x + 40 < 365)) // 위에서 6번째 계단
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(1990 - m_pPlayer->Height());
		if (m_pPlayer->Pos().x + 40 <= 295 && m_pPlayer->Pos().y + m_pPlayer->Height() >= 1937)
			m_pPlayer->SetPosX(255);
	}
	else if (m_pPlayer->Pos().y + m_pPlayer->Height() >= 2060 && m_pPlayer->Pos().y + m_pPlayer->Height() < 2085 && (m_pPlayer->Pos().x + 40 >= 285 && m_pPlayer->Pos().x + 40 < 440)) // 위에서 7번째 계단
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(2060 - m_pPlayer->Height());
		if (m_pPlayer->Pos().x + 40 <= 365 && m_pPlayer->Pos().y + m_pPlayer->Height() >= 1755)
			m_pPlayer->SetPosX(325);
	}

	//2층 바닥
	else if (!m_pPlayer->isDownJump() && m_pPlayer->Pos().y + m_pPlayer->Height() >= 2190 && m_pPlayer->Pos().y + m_pPlayer->Height() < 2212)
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(2190 - m_pPlayer->Height());
	}

	//2층 계단
	else if (m_pPlayer->Pos().y + m_pPlayer->Height() >= 2440 && m_pPlayer->Pos().y + m_pPlayer->Height() < 2465 && m_pPlayer->Pos().x + m_pPlayer->Width() - 40 > 975) // 위에서 1번째 계단
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(2440 - m_pPlayer->Height());
	}
	else if (m_pPlayer->Pos().y + m_pPlayer->Height() >= 2520 && m_pPlayer->Pos().y + m_pPlayer->Height() < 2545 && m_pPlayer->Pos().x + m_pPlayer->Width() - 40 >= 905) // 위에서 2번째 계단
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(2520 - m_pPlayer->Height());
		if (m_pPlayer->Pos().x + m_pPlayer->Width() - 40 >= 975 && m_pPlayer->Pos().y + m_pPlayer->Height() >= 2440)
			m_pPlayer->SetPosX(1015 - m_pPlayer->Width());
	}
	else if (m_pPlayer->Pos().y + m_pPlayer->Height() >= 2598 && m_pPlayer->Pos().y + m_pPlayer->Height() < 2623 && (m_pPlayer->Pos().x + m_pPlayer->Width() - 40 < 975 && m_pPlayer->Pos().x + m_pPlayer->Width() - 40 >= 835)) // 위에서 3번째 계단
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(2598 - m_pPlayer->Height());
		if (m_pPlayer->Pos().x + m_pPlayer->Width() - 40 >= 905 && m_pPlayer->Pos().y + m_pPlayer->Height() >= 2520)
			m_pPlayer->SetPosX(945 - m_pPlayer->Width());
	}
	else if (m_pPlayer->Pos().y + m_pPlayer->Height() >= 2675 && m_pPlayer->Pos().y + m_pPlayer->Height() < 2700 && (m_pPlayer->Pos().x + m_pPlayer->Width() - 40 < 905 && m_pPlayer->Pos().x + m_pPlayer->Width() - 40 >= 765)) // 위에서 4번째 계단
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(2675 - m_pPlayer->Height());
		if (m_pPlayer->Pos().x + m_pPlayer->Width() - 40 >= 835 && m_pPlayer->Pos().y + m_pPlayer->Height() >= 2598)
			m_pPlayer->SetPosX(875 - m_pPlayer->Width());
	}
	else if (m_pPlayer->Pos().y + m_pPlayer->Height() >= 2746 && m_pPlayer->Pos().y + m_pPlayer->Height() < 2771 && (m_pPlayer->Pos().x + m_pPlayer->Width() - 40 < 835 && m_pPlayer->Pos().x + m_pPlayer->Width() - 40 >= 690)) // 위에서 5번째 계단
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(2746 - m_pPlayer->Height());
		if (m_pPlayer->Pos().x + m_pPlayer->Width() - 40 >= 765 && m_pPlayer->Pos().y + m_pPlayer->Height() >= 2675)
			m_pPlayer->SetPosX(805 - m_pPlayer->Width());
	}

	//1층 바닥
	else if (m_pPlayer->Pos().y + m_pPlayer->Height() >= 2890)
	{
		m_pPlayer->isOnGround(true);
		m_pPlayer->SetPosY(2890 - m_pPlayer->Height());
	}

	else
		m_pPlayer->isOnGround(false);

	if (m_pPlayer->Pos().x + 40 < ladder->Pos().x || m_pPlayer->Pos().x + m_pPlayer->Width() - 40 > ladder->Pos().x + ladder->Width()) // 사다리 타고 3층 천장에 부딪힐 때
	{
		if (m_pPlayer->Pos().y <= 812 && m_pPlayer->Pos().y > 802)
			m_pPlayer->SetPosY(812);
		else if (m_pPlayer->Pos().y + m_pPlayer->Height() > 792 && m_pPlayer->Pos().y + m_pPlayer->Height() < 802)
			m_pPlayer->SetPosY(792 - m_pPlayer->Height());
	}

	if (m_pPlayer->Pos().y < 812 && m_pPlayer->Pos().y + m_pPlayer->Height() > 792) // 사다리에서 좌우로 움직이는 도중 바닥과 겹칠 때
	{
		if (m_pPlayer->Pos().x + 40 <= ladder->Pos().x && m_pPlayer->Pos().x + 40 > ladder->Pos().x - 10)
		{
			m_pPlayer->SetPosX(ladder->Pos().x - 40);
		}
		else if (m_pPlayer->Pos().x + m_pPlayer->Width() - 40 >= ladder->Pos().x + ladder->Width() && m_pPlayer->Pos().x + m_pPlayer->Width() - 40 < ladder->Pos().x + ladder->Width() + 10)
		{
			m_pPlayer->SetPosX((ladder->Pos().x + ladder->Width()) - m_pPlayer->Width() + 40);
		}
	}

	if (rectangleCollision(m_pPlayer, ladder)) // 플레이어와 사다리 충돌
		m_pPlayer->isClimb(true);
	else
	{
		m_pPlayer->isClimb(false);
	}

	for (int i = 0; i < 5; i++)
	{
		if (rectangleCollision(m_pPlayer, door[i]))
		{
			if (in->GetKey('W') == INPUTMGR_KEYDOWN || in->GetKey(VK_UP) == INPUTMGR_KEYDOWN)
			{
				door[i]->isEntered(true);
			}
		}
	}

	//for (int i = 0; IsExistScene(border[i]); i++)
	//{
	//	//플레이어와 타일이 충돌 했을 때
	//	if (rectangleCollision(m_pPlayer, border[i]))
	//	{
	//		// 타일 위에 올라섰을 때
	//		if (m_pPlayer->Pos().y + m_pPlayer->Height() > border[i]->Pos().y && m_pPlayer->Pos().y + m_pPlayer->Height() < border[i]->Pos().y + border[i]->Height())
	//		{
	//			m_pPlayer->isOnGround(true);
	//			m_pPlayer->SetPosY(border[i]->Pos().y - m_pPlayer->Height());
	//		}
	//		// 타일 아래에 머리를 부딪혔을 때
	//		else if (m_pPlayer->Pos().y > border[i]->Pos().y && m_pPlayer->Pos().y < border[i]->Pos().y + border[i]->Height())
	//		{
	//			m_pPlayer->isOnGround(false);
	//			m_pPlayer->SetPosY(border[i]->Pos().y + border[i]->Height());
	//		}
	//	}

	//	//플레이어가 땅에 있고 타일과 접촉 했을 떄
	//	tileCollision(m_pPlayer, border[i]);
	//}
}

void StartScene::Render()
{
	ZeroIScene::Render();

	bg->Render();

	ladder->Render();

	for (int i = 0; i < 5; i++)
		door[i]->Render();

	m_pPlayer->Render();
}

bool StartScene::rectangleCollision(Player *_r1, ZeroIScene *_r2) // 플레이어 충돌 판정
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

	if (IntersectRect(&temp, &LEFT, &R2) && _r1->isOnGround())
	{
		return _r2->isLeftPushed(true);
	}
	else if (IntersectRect(&temp, &RIGHT, &R2) && _r1->isOnGround())
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