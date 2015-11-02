#include "stdafx.h"
#include "GameScene.h"
#include "BlankSceneExit.h"

GameScene::GameScene(void)
	:bulletTime(0.f), theWorld(0.f), isTheWorlded(false), db(0), speed(300)
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

	bg1 = new ZeroSprite("exresource/bg.jpg"); // ��� �ʱ� ����
	bg2 = new ZeroSprite("exresource/bg.jpg");
	bg3 = new ZeroSprite("exresource/bg.jpg");
	TW = new ZeroSprite("Texture/theWorld/TheWorldTimeStop.png");
	GRAY = new ZeroSprite("Texture/theWorld/gray.png");

	sound->PushSound("Sound/zawarudo.wav", "����?���");
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

	m_pPlayer = new Player(); // �÷��̾� �ʱ� ����
	m_pPlayer -> SetPos(447, 548);
	PushScene(m_pPlayer);

	monster = new Monster(m_pPlayer, 3); // ���� �ʱ� ����
	monster->SetPos(100, 100);
	PushScene(monster);

	jItem = new Item(1); // ������ �ʱ� ����
	jItem -> SetPos(750, 600);
	PushScene(jItem);

	gItem = new Item(2);
	gItem -> SetPos(250, 600);
	PushScene(gItem);

	rItem = new Item(3);
	rItem->SetPos(900, 600);
	PushScene(rItem);

	djItem = new Item(4);
	djItem->SetPos(1000, 600);
	PushScene(djItem);

	sItem = new Item(5);
	sItem->SetPos(1100, 600);
	PushScene(sItem);

	switcH = new Switch(m_pPlayer, 1); // ����ġ �ʱ� ����
	switcH->SetPos(10, app->GetWindowHeight() - switcH->body->Height());
	PushScene(switcH);

	box1 = new Box(m_pPlayer); // �ڽ� �ʱ� ����
	box1->SetPos(900, 20);
	PushScene(box1);

	box2 = new Box(m_pPlayer); // �ڽ� �ʱ� ����
	box2->SetPos(1300, 20);
	PushScene(box2);

	//playerAndMonster = new Intersect(m_pPlayer, monster); // �÷��̾� <-> ���� �浹 ���� �ʱ� ����
	//playerAndJItem = new Intersect(m_pPlayer, jItem); // �÷��̾� <-> ���� ������ �浹 ���� �ʱ� ����
	//playerAndGItem = new Intersect(m_pPlayer, gItem); // �÷��̾� <-> �� ������ �浹 ���� �ʱ� ����
	//playerAndRItem = new Intersect(m_pPlayer, rItem); // �÷��̾� <-> ������ ������ �浹 ���� �ʱ� ����
	//playerAndDJItem = new Intersect(m_pPlayer, djItem); // �÷��̾� <-> ���� ���� ������ �浹 ���� �ʱ� ����
	//playerAndSItem = new Intersect(m_pPlayer, sItem); // �÷��̾� <-> ���� ������ �浹 ���� �ʱ� ����
	//playerAndSwitch = new Intersect(m_pPlayer, switcH); // �÷��̾� <-> ����ġ �浹 ���� �ʱ� ����
	//playerAndLadder = new Intersect(m_pPlayer, ladder, true); // �÷��̾� <-> ��ٸ� �浹 ���� �ʱ� ����

	//PushScene(playerAndMonster);
	//PushScene(playerAndJItem);
	//PushScene(playerAndGItem);
	//PushScene(playerAndRItem);
	//PushScene(playerAndDJItem);
	//PushScene(playerAndSItem);
	//PushScene(playerAndSwitch);
	//PushScene(playerAndLadder);

	camera -> SetCameraOn(); // ī�޶� �ʱ� ����
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
	if (!m_pPlayer->isChange()) // �߷��� �ٲ�� ���� �ƴ� ��
	{
		if (in->GetKey('A') == INPUTMGR_KEYDOWN || in->GetKey(VK_LEFT) == INPUTMGR_KEYDOWN) // �÷��̾� '��'�̵�
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

		if (in->GetKey('D') == INPUTMGR_KEYDOWN || in->GetKey(VK_RIGHT) == INPUTMGR_KEYDOWN) // �÷��̾� '��'�̵�
			m_pPlayer->move->Start();
		if (in->GetKey('D') == INPUTMGR_KEYON || in->GetKey(VK_RIGHT) == INPUTMGR_KEYON/* || (player1 -> IsConnected() && player1 -> GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)*/)
		{
			//printf("right moving\n");
			if (!m_pPlayer->move->IsRunning())
				m_pPlayer->move->Start();
			m_pPlayer->Move(speed * eTime);
		}
		if (in->GetKey('D') == INPUTMGR_KEYUP || in->GetKey(VK_RIGHT) == INPUTMGR_KEYUP)
			m_pPlayer->move->Stop();

		if (in->GetKey('W') == INPUTMGR_KEYDOWN || in->GetKey('W') == INPUTMGR_KEYON || in->GetKey(VK_UP) == INPUTMGR_KEYDOWN || in->GetKey(VK_UP) == INPUTMGR_KEYON/* || (player1 -> IsConnected() && player1 -> GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)*/)
		{
			m_pPlayer->Climb((speed - 100) * eTime);
		}

		if (in->GetKey('S') == INPUTMGR_KEYDOWN || in->GetKey('S') == INPUTMGR_KEYON || in->GetKey(VK_DOWN) == INPUTMGR_KEYDOWN || in->GetKey(VK_DOWN) == INPUTMGR_KEYON/* || (player1 -> IsConnected() && player1 -> GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)*/)
		{
			m_pPlayer->Climb(-1 * (speed - 100) * eTime);
		}
	}

	if (in->GetKey('R') == INPUTMGR_KEYDOWN && (m_pPlayer->Pos().y == app->GetWindowHeight()-m_pPlayer->Height() || m_pPlayer->Pos().y == 0) && (box1->Pos().y == app->GetWindowHeight() - box1->Height() || box1->Pos().y == 0)) // ��.��.��.ȯ(?)
	{
		if (rItem -> isReverseOn())
		{
			if (m_pPlayer->Rot() == 180)
				m_pPlayer->isReverse(false);
			else
				m_pPlayer->isReverse(true);
		}
	}

	if (in->GetKey('M') == INPUTMGR_KEYDOWN && sItem->isSmallOn())
	{
		if (m_pPlayer->isSmall())
			m_pPlayer->isSmall(false);
		else
			m_pPlayer->isSmall(true);
	}

	if (in->GetKey('X') == INPUTMGR_KEYDOWN && gItem->isShootOn() && !isTheWorlded) // �Ȫ��� �Ȫު�
	{
		isTheWorlded = true;
		//sound->Play("����?���");
		sound->Play("countdown");
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

	if (gItem->isShootOn()) // �� �������� �Ծ��� ���
	{
		if (in->GetKey(VK_SHIFT) == INPUTMGR_KEYDOWN || in->GetKey(VK_SHIFT) == INPUTMGR_KEYON) // �÷��̾� �� ���
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

	if (jItem->isJumpOn()) // ���� �������� �Ծ��� ���
	{
		if ((!m_pPlayer->isDoubleJump() && m_pPlayer->JumpNum < 1) || (m_pPlayer->isDoubleJump() && m_pPlayer->JumpNum < 2)) // ������ �� �� ���� ���
		{
			if (in->GetKey(VK_SPACE) == INPUTMGR_KEYDOWN/* || (player1 -> IsConnected() && player1 -> GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)*/) // �÷��̾� ���� �ϱ�
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

	if (djItem->isDoubleJumpOn()) // ���� ���� �������� �Ծ��� ���
		m_pPlayer->isDoubleJump(true);

	//���⼭ ���� �浹 ������

	if (rectangleCollision(m_pPlayer, jItem)) // �÷��̾�� ���� ������ �浹
		jItem->isJumpOn(true);

	if (rectangleCollision(m_pPlayer, gItem)) // �÷��̾�� �� ������ �浹
		gItem->isShootOn(true);

	if (rectangleCollision(m_pPlayer, rItem)) // �÷��̾�� ������ ������ �浹
		rItem->isReverseOn(true);

	if (rectangleCollision(m_pPlayer, djItem)) // �÷��̾�� ���� ���� ������ �浹
		djItem->isDoubleJumpOn(true);

	if (rectangleCollision(m_pPlayer, sItem)) // �÷��̾�� ���� ������ �浹
		sItem->isSmallOn(true);

	if (rectangleCollision(m_pPlayer, switcH)) // �÷��̾�� ����ġ ������ �浹
		switcH->isOn(true);

	if (IsExistScene(monster))
	{
		if (rectangleCollision(m_pPlayer, monster)) // �÷��̾�� ���� �浹
			monster->isContacted(true);
		else
			monster->isContacted(false);

		for (int i = 0; i < 5; i++)
		{
			if (IsExistScene(bullet[i])) // �Ѿ��� �����ϴ��� �˻�
			{
				if (rectangleCollision(bullet[i], monster)) // �Ѿ˰� ���� �浹
				{
					PopScene(monster);
					PopScene(bullet[i]);
				}
			}
		}
	}

	//if (playerAndLadder->isIntersected()) // �÷��̾�� ��ٸ� �浹
	//{
	//	m_pPlayer->isClimb(true);
	//}


	//if (IntersectRect(&t, &r1, &r2) && in->GetKey(MK_LBUTTON) == INPUTMGR_KEYDOWN) // �� ���콺 Ŭ���̿���!
	//{
	//	gItem->isShootOn(true);
	//	ZeroSceneMgr->ChangeScene(new BlankSceneExit(), TR::Fade, 1);
	//}
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


	monster->Render();


	for (int j=0; j<5; j++)
		if (IsExistScene(bullet[j]))
			bullet[j] -> Render();

	if (IsExistScene(jItem))
		jItem->Render();

	if (IsExistScene(gItem))
		gItem->Render();

	if (IsExistScene(rItem))
		rItem->Render();

	if (IsExistScene(djItem))
		djItem->Render();

	if (IsExistScene(sItem))
		sItem->Render();

	switcH->Render();

	box1->Render();
	box2->Render();

	if (theWorld)
	{
		GRAY->Render();
		TW->Render();
	}

	m_pPlayer->Render();
}

void GameScene::PushBullet(float x, float y)
{
	if (m_pPlayer->isSmall()) // �۾����� �� �Ѿ� �߻� ��ǥ
	{
		if (x > m_pPlayer->Pos().x) // ���������� �߻� �ɶ�
			x -= 20.f;
		else
			x += 20.f;
		y += 70.f;
	}
	for (int i = 0; i < 5; i++) // �Ѿ� ���� �������� ����    m��� �� ��  �� ������ �Ѿ��� �� �� ����
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
				bullet[i]->speed = -600.f; // �Ѿ� �ӵ�
			else
				bullet[i]->speed = 600.f; // �Ѿ� �ӵ�
			bullet[i]->SetPos(x, y);
			break;
		}
	}
}

bool GameScene::rectangleCollision(Player *_r1, ZeroIScene *_r2) // �÷��̾� �浹 ����
{
	if (_r1->isSmall()) // �۾����� ��
	{
		R1.left = _r1->Pos().x + 50;
		R1.top = _r1->Pos().y + _r1->Height() / 2;
		R1.right = _r1->Pos().x + _r1->Width() - 50;
		R1.bottom = _r1->Pos().y + _r1->Height();
	}
	else // ������� �� ��
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

bool GameScene::rectangleCollision(Bullet *_r1, ZeroIScene *_r2) // �Ѿ� �浹 ����
{
	R1.left = _r1->Pos().x;
	R1.top = _r1->Pos().y;
	R1.right = _r1->Pos().x + _r1->Width();
	R1.bottom = _r1->Pos().y + _r1->Height();

	R2.left = _r2->Pos().x;
	R2.top = _r2->Pos().y;
	R2.right = _r2->Pos().x + _r2->Width();
	R2.bottom = _r2->Pos().y + _r2->Height();

	if (IntersectRect(&temp, &R1, &R2))
		return true;
	else
		return false;
}

void GameScene::boxCollision(Player *_r1, Box *_r2) // �÷��̾�� ���� �浹 ����
{
	if (_r1->isSmall()) // �۾����� ��
	{
		LEFT.left = _r1->Pos().x + 50; // ���� RECT
		LEFT.top = _r1->Pos().y + _r1->Height() / 2;
		LEFT.right = _r1->Pos().x + _r1->Width() / 2;
		LEFT.bottom = _r1->Pos().y + _r1->Height();

		RIGHT.left = _r1->Pos().x + _r1->Width() / 2; // ������ RECT
		RIGHT.top = _r1->Pos().y + _r1->Height() / 2;
		RIGHT.right = _r1->Pos().x + _r1->Width() - 50;
		RIGHT.bottom = _r1->Pos().y + _r1->Height();
	}
	else // ������� �� ��
	{
		LEFT.left = _r1->Pos().x + 40; // ���� RECT
		LEFT.top = _r1->Pos().y;
		LEFT.right = _r1->Pos().x + _r1->Width() / 2;
		LEFT.bottom = _r1->Pos().y + _r1->Height();

		RIGHT.left = _r1->Pos().x + _r1->Width() / 2; // ������ RECT
		RIGHT.top = _r1->Pos().y;
		RIGHT.right = _r1->Pos().x + _r1->Width() - 40;
		RIGHT.bottom = _r1->Pos().y + _r1->Height();
	}

	R2.left = _r2->Pos().x;
	R2.top = _r2->Pos().y;
	R2.right = _r2->Pos().x + _r2->Width();
	R2.bottom = _r2->Pos().y + _r2->Height();

	if (IntersectRect(&temp, &LEFT, &R2))
		return _r2->isLeftPushed(true);
	else if (IntersectRect(&temp, &RIGHT, &R2))
		return _r2->isRightPushed(true);
	else
	{
		_r2->isLeftPushed(false);
		_r2->isRightPushed(false);
		return;
	}
}

void GameScene::tileCollision(Player *_r1, Tile *_r2) // �÷��̾�� Ÿ�� �浹 ����
{
	if (_r1->isSmall()) // �۾����� ��
	{
		LEFT.left = _r1->Pos().x + 50; // ���� RECT
		LEFT.top = _r1->Pos().y + _r1->Height() / 2;
		LEFT.right = _r1->Pos().x + _r1->Width() / 2;
		LEFT.bottom = _r1->Pos().y + _r1->Height();

		RIGHT.left = _r1->Pos().x + _r1->Width() / 2; // ������ RECT
		RIGHT.top = _r1->Pos().y + _r1->Height() / 2;
		RIGHT.right = _r1->Pos().x + _r1->Width() - 50;
		RIGHT.bottom = _r1->Pos().y + _r1->Height();
	}
	else // ������� �� ��
	{
		LEFT.left = _r1->Pos().x + 40; // ���� RECT
		LEFT.top = _r1->Pos().y;
		LEFT.right = _r1->Pos().x + _r1->Width() / 2;
		LEFT.bottom = _r1->Pos().y + _r1->Height();

		RIGHT.left = _r1->Pos().x + _r1->Width() / 2; // ������ RECT
		RIGHT.top = _r1->Pos().y;
		RIGHT.right = _r1->Pos().x + _r1->Width() - 40;
		RIGHT.bottom = _r1->Pos().y + _r1->Height();
	}

	R2.left = _r2->Pos().x;
	R2.top = _r2->Pos().y;
	R2.right = _r2->Pos().x + _r2->Width();
	R2.bottom = _r2->Pos().y + _r2->Height();

	if (IntersectRect(&temp, &LEFT, &R2))
		return _r2->isLeftPushed(true);
	else if (IntersectRect(&temp, &RIGHT, &R2))
		return _r2->isRightPushed(true);
	else
	{
		_r2->isLeftPushed(false);
		_r2->isRightPushed(false);
		return;
	}
}

//bool GameScene::circleCollision(Player *r1, ZeroIScene *r2)
//{
//	r1_x = r1->Pos().x + r1->Width()/2;
//	r1_y = r1->Pos().y + r1->Height()/2;
//	r2_x = r2->Pos().x + r2->Width() / 2;
//	r2_y = r2->Pos().y +Height r2->() / 2;
//
//	//printf("r1_x : %f\tr1_y : %f\nr2_x : %f\tr2_y : %f\nl : %f\n", r1_x, r1_y, r2_x, r2_y, l);
//
//	l = sqrtf(powf((r2_x - r1_x), 2) + pow((r2_y - r1_y), 2));
//
//	if (l < 0)
//		l *= -1;
//	
//	if (r1->Width() / 2 - 20 + r2->Width() / 2 >= l)
//		return true;
//	else
//		return false;
//}