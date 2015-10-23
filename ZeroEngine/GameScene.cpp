#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene(void)
	:bulletTime(0.f), theWorld(0.f), isTheWorlded(false), db(0)
{
	printf("start\n");

	app = ZeroApp;
	in = ZeroInputMgr;
	camera = ZeroCameraMgr;
	sound = ZeroSoundMgr;

	/*a = new ZeroSprite("%s", "exresource/a.jpg");
	b = new ZeroSprite("%s", "exresource/b.jpg");
	c = new ZeroSprite("%s", "exresource/c.jpg");
	gradient = new ZeroSprite("%s", "exresource/gradient.jpg");*/

	bg1 = new ZeroSprite("exresource/bg.jpg"); // 배경 초기 설정
	bg2 = new ZeroSprite("exresource/bg.jpg");
	bg3 = new ZeroSprite("exresource/bg.jpg");
	TW = new ZeroSprite("Texture/theWorld/TheWorldTimeStop.png");
	GRAY = new ZeroSprite("Texture/theWorld/gray.png");

	sound->PushSound("Sound/theWorld.wav", "ざわ?るど");
	sound->PushSound("Sound/count(1~3).mp3", "countdown");
	sound->PushSound("Sound/ORA.mp3", "ORA");

	/*PushScene(a);
	PushScene(b);
	PushScene(c);
	PushScene(gradient);*/
	PushScene(bg1);
	PushScene(bg2);
	PushScene(bg3);
	PushScene(TW);
	PushScene(GRAY);

	/*a -> SetPos(0, 0);
	b -> SetPos(690, 0);
	c -> SetPos(690, 334);*/
	bg1 -> SetPos(0, 0);
	bg2 -> SetPos(1024, 0);
	bg3 -> SetPos(2048, 0);
	TW->SetRotCenter(TW->Width() / 2, TW->Height() / 2);
	GRAY->SetScalingCenter(GRAY->Width() / 2, GRAY->Height() / 2);

	m_pPlayer = new Player(); // 플레이어 초기 설정
	m_pPlayer -> SetPos(447, 548);
	PushScene(m_pPlayer);

	jItem = new Item(1); // 아이템 초기 설정
	jItem -> SetPos(750, 600);
	PushScene(jItem);

	gItem = new Item(2);
	gItem -> SetPos(250, 600);
	PushScene(gItem);

	sItem = new Item(3);
	sItem->SetPos(1030, 600);
	PushScene(sItem);

	switcH = new Switch(1); // 스위치 초기 설정
	switcH->SetPos(10, app->GetWindowHeight() - switcH->Height());
	PushScene(switcH);

	box = new Box(m_pPlayer);
	box->SetPos(1080, app->GetWindowHeight() - box->Height());
	PushScene(box);

	camera -> SetCameraOn(); // 카메라 초기 설정
	camera -> SetScreen(3072, 768);
	camera -> SetTarget(m_pPlayer);

	/*player1 = new CXBOXController(1);
	if (player1 -> IsConnected())
		printf("XBOXControllerOne Connected\n");*/

	printf("Pos setting finish\n");  
}


GameScene::~GameScene(void)
{
}

void GameScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	bulletTime += eTime;

	//printf("Left Stick X : %f\n", state.Gamepad.sThumbLX);
	//printf("Left Stick Y : %f\n", state.Gamepad.sThumbLY);
	printf("%f\t%f\n", m_pPlayer->Width(), m_pPlayer->Scale().x);
	if (in->GetKey('A') == INPUTMGR_KEYDOWN || in->GetKey(VK_LEFT) == INPUTMGR_KEYDOWN) // 플레이어 '좌'이동
		m_pPlayer->move->Start();
	if (in->GetKey('A') == INPUTMGR_KEYON || in->GetKey(VK_LEFT) == INPUTMGR_KEYON/* || (player1 -> IsConnected() && player1 -> GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)*/)
	{
		//printf("left moving\n");
		if (!m_pPlayer->move->IsRunning())
			m_pPlayer->move->Start();
		m_pPlayer->Move(-300 * eTime);
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
		m_pPlayer->Move(300 * eTime);
	}
	if (in->GetKey('D') == INPUTMGR_KEYUP || in->GetKey(VK_RIGHT) == INPUTMGR_KEYUP)
		m_pPlayer->move->Stop();

	if (in->GetKey('R') == INPUTMGR_KEYDOWN && (m_pPlayer->Pos().y == 548 || m_pPlayer->Pos().y == 0)) // 중.력.변.환(?)
	{
		if (m_pPlayer->Rot() == 180)
		{
			m_pPlayer->isReverse(false);
			m_pPlayer->SetRot(0);
		}
		else
		{
			m_pPlayer->isReverse(true);
			m_pPlayer->SetRot(180);
		}
	}

	if (/*in->GetKey('M') == INPUTMGR_KEYDOWN && */sItem->isSmallOn())
	{
		m_pPlayer->setScale(0.5f, 0.5f);
		this->SetWidth(m_pPlayer->normal->Width() / 2);
		this->SetHeight(m_pPlayer->normal->Height() / 2);
	}

	if (in->GetKey('X') == INPUTMGR_KEYDOWN && gItem->isShootOn() && !isTheWorlded) // ときよ とまれ
	{
		isTheWorlded = true;
		sound->Play("ざわ?るど");
		//sound->Play("countdown");
	}

	if (isTheWorlded)
	{
		TW->SetPos(m_pPlayer->Pos().x - 130, m_pPlayer->Pos().y - 400);
		GRAY->SetPos(m_pPlayer->Pos().x + m_pPlayer->Width() / 2, m_pPlayer->Pos().y);
		GRAY->SetScale(theWorld * 7);
		for (int i = 0; i < 5; i++)
		{
			if (IsExistScene(bullet[i]))
				bullet[i]->update = false;
		}
		theWorld += eTime;
		if (TW->Rot() < 360)
			TW->SetRot(theWorld * 100);
		else
			TW->SetRot(360);
	}

	if (theWorld > 6.f)
	{
		for (int i = 0; i < 5; i++)
		{
			if (IsExistScene(bullet[i]))
				bullet[i]->update = true;
		}
		isTheWorlded = false;
		theWorld = 0.f;
		TW->SetRot(0);
	}

	//printf("%f\n", m_pPlayer -> ScalingCenter().x);

	if (gItem->isShootOn()) // 총 아이템을 먹었을 경우
	{
		if (in->GetKey(VK_SHIFT) == INPUTMGR_KEYDOWN || in->GetKey(VK_SHIFT) == INPUTMGR_KEYON) // 플레이어 총 쏘기
		{
			if (bulletTime > 0.2f)
			{
				if (m_pPlayer->isReverse())
				{
					if (m_pPlayer->left)
						PushBullet(m_pPlayer->Pos().x - 25, m_pPlayer->Pos().y + 140);
					else
						PushBullet(m_pPlayer->Pos().x + 130, m_pPlayer->Pos().y + 140);
				}
				else
				{
					if (m_pPlayer->left)
						PushBullet(m_pPlayer->Pos().x - 25, m_pPlayer->Pos().y + 70);
					else
						PushBullet(m_pPlayer->Pos().x + 130, m_pPlayer->Pos().y + 70);
				}
				bulletTime = 0.0f;
				//printf("shooting\n");
				//printf("i = %d\n", i);
			}
		}
	}

	if (jItem->isJumpOn()) // 점프 아이템을 먹었을 경우
	{
		if (m_pPlayer->JumpNum < 2) // 점프를 할 수 있을 경우
		{
			if (in->GetKey(VK_SPACE) == INPUTMGR_KEYDOWN/* || (player1 -> IsConnected() && player1 -> GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)*/) // 플레이어 점프 하기
			{
				/*if (m_pPlayer->JumpNum == 0)
					m_pPlayer->JumpNum = 1;
				else if (m_pPlayer->JumpNum == 1)
					m_pPlayer->JumpNum = 2;
				else
					m_pPlayer->JumpNum = 3;*/
				m_pPlayer->JumpNum++;

				if (m_pPlayer->JeTime != 0)
					m_pPlayer->JeTime = 0;

				m_pPlayer->isJump(true);
				m_pPlayer->isFall(false);
			}
			if (in->GetKey(VK_SPACE) == INPUTMGR_KEYON)
				if (!(m_pPlayer->isFall()))
					m_pPlayer->isJump(true);

			if (in->GetKey(VK_SPACE) == INPUTMGR_KEYUP)
			{
				m_pPlayer->isJump(false);
				m_pPlayer->isFall(true);
			}
		}
	}

	//여기서 부턴 충돌 판정들

	if (circleCollision(m_pPlayer, jItem)) // 플레이어와 점프 아이템 충돌
	{
		jItem->isJumpOn(true);
		//printf("BOOM\n");
	}

	if (circleCollision(m_pPlayer, gItem)) // 플레이어와 총 아이템 충돌
	{
		gItem->isShootOn(true);
	}

	if (circleCollision(m_pPlayer, sItem)) // 플레이어와 땅콩 아이템 충돌
	{
		sItem->isSmallOn(true);
	}

	if (circleCollision(m_pPlayer, switcH)) // 플레이어와 스위치 아이템 충돌
	{
		switcH->isOn(true);
	}
}

void GameScene::Render()
{
	ZeroIScene::Render();
	 
	/*a -> Render();
	b -> Render();
	c -> Render();
	gradient -> Render();*/
	bg1 -> Render();
	bg2 -> Render();
	bg3 -> Render();

	for (int j=0; j<5; j++)
		if (IsExistScene(bullet[j]))
			bullet[j] -> Render();

	if (IsExistScene(jItem))
		jItem->Render();

	if (IsExistScene(gItem))
		gItem->Render();

	if (IsExistScene(sItem))
		sItem->Render();

	switcH->Render();

	box->Render();

	if (theWorld)
	{
		GRAY->Render();
		TW->Render();
	}

	m_pPlayer->Render();
}

void GameScene::PushBullet(float x, float y)
{
	for (int i = 0; i < 5; i++) // 총알 씬이 존재하지 않을 경우 그 배열 순서의 총알을 쏠 수 있음
	{
		if (!(IsExistScene(bullet[i])))
		{
			sound->Play("ORA");
			if (!(m_pPlayer->isShoot()))
				m_pPlayer->isShoot(true);
			_i++;
			bullet[i] = new Bullet();
			PushScene(bullet[i]);

			if (m_pPlayer->left)
				bullet[i]->speed = -600.f; // 총알 속도
			else
				bullet[i]->speed = 600.f; // 총알 속도
			bullet[i]->SetPos(x, y);
			break;
		}
	}
}

bool GameScene::circleCollision(ZeroIScene *r1, ZeroIScene *r2)
{
	r1_x = r1->Pos().x + r1->ScalingCenter().x;
	r1_y = r1->Pos().y + r1->ScalingCenter().y;
	r2_x = r2->Pos().x + r2->ScalingCenter().x;
	r2_y = r2->Pos().y + r2->ScalingCenter().y;

	//printf("r1_x : %f\tr1_y : %f\nr2_x : %f\tr2_y : %f\nl : %f\n", r1_x, r1_y, r2_x, r2_y, l);

	l = sqrtf(powf((r2_x - r1_x), 2) + pow((r2_y - r1_y), 2));

	if (l < 0)
		l *= -1;
	
	if (r1->ScalingCenter().x + r2->ScalingCenter().x >= l)
		return true;
	else
		return false;
}