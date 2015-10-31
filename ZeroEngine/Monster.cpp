#include "stdafx.h"
#include "Monster.h"

Monster::Monster(Player *_player, int no)
	:scaleX(1.f), scaleY(1.f), monsterNum(0), speed(200), chasing(false), contacting(false), SeTime(0)
{
	player = _player;

	monsterNum = no;
	switch (monsterNum)
	{
	case 1:
		normal = new ZeroSprite("Texture/Monster/1/monster1_1_1.png");
		move = new ZeroAnimation(3.f);
		move->PushSprite("Texture/Monster/1/monster1_1_2.png");
		move->PushSprite("Texture/Monster/1/monster1_1_1.png");
		senseMove = new ZeroAnimation(3.f);
		senseMove->PushSprite("Texture/Monster/1/monster1_2_2.png");
		senseMove->PushSprite("Texture/Monster/1/monster1_2_1.png");
		attack = new ZeroSprite("Texture/Monster/1/monster1_3.png");
		break;

	case 2:
		normal = new ZeroSprite("Texture/Monster/2/monster2_1_1.png");
		move = new ZeroAnimation(3.f);
		move->PushSprite("Texture/Monster/2/monster2_1_2.png");
		move->PushSprite("Texture/Monster/2/monster2_1_1.png");
		senseMove = new ZeroAnimation(3.f);
		senseMove->PushSprite("Texture/Monster/2/monster2_2_2.png");
		senseMove->PushSprite("Texture/Monster/2/monster2_2_1.png");
		attack = new ZeroSprite("Texture/Monster/2/monster2_3.png");
		break;

	case 3:
		normal = new ZeroSprite("Texture/Monster/3/monster3_1_1.png");
		move = new ZeroAnimation(3.f);
		move->PushSprite("Texture/Monster/3/monster3_1_2.png");
		move->PushSprite("Texture/Monster/3/monster3_1_1.png");
		senseMove = new ZeroAnimation(3.f);
		senseMove->PushSprite("Texture/Monster/3/monster3_2_2.png");
		senseMove->PushSprite("Texture/Monster/3/monster3_2_1.png");
		attack = new ZeroSprite("Texture/Monster/3/monster3_3.png");
		break;
	}
	this->SetWidth(normal->Width());
	this->SetHeight(normal->Height());
	this->SetScalingCenter(Width() / 2, Height() / 2);
	this->SetRotCenter(normal->Width() / 2, normal->Height() / 2);
	PushScene(normal);
	PushScene(move);
	PushScene(senseMove);
	PushScene(attack);
}

Monster::~Monster()
{
}

void Monster::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	perceive(player);

	if (chasing && player->isChange())
		chasing = false;
	
	if (player->isReverse()) // 중력이 바꼈을 때
	{

		if (right)
		{
			if (scaleX < 0)
				scaleX *= -1;
			this->SetScale(scaleX, scaleY);
		}
		else
		{
			if (scaleX > 0)
				scaleX *= -1;
			this->SetScale(scaleX, scaleY);
		}

		if (this->Rot() != 180) // 뒤집혔는지 여부
			this->SetRot(180);

		if (Pos().y > 0)
		{
			this->AddPosY(SeTime * eTime);
			SeTime -= 30.f;
		}

		if (Pos().y <= 0)
		{
			this->SetPosY(0);
			SeTime = 0.f;
			isChased(eTime);
		}
	}
	else // 중력이 정상일 때
	{
		if (right)
		{
			if (scaleX > 0)
				scaleX *= -1;
			this->SetScale(scaleX, scaleY);
		}
		else
		{
			if (scaleX < 0)
				scaleX *= -1;
			this->SetScale(scaleX, scaleY);
		}

		if (this->Rot() != 0) // 원래대로 돌아왔는지 여부
			this->SetRot(0);

		if (Pos().y < ZeroApplication::Instance()->GetWindowHeight() - this->Height())
		{
			this->AddPosY(SeTime * eTime);
			SeTime += 30.f;
		}

		if (Pos().y >= ZeroApplication::Instance()->GetWindowHeight() - this->Height())
		{
			this->SetPosY(ZeroApplication::Instance()->GetWindowHeight() - this->Height());
			SeTime = 0.f;
			isChased(eTime);
		}
	}
}

void Monster::Render()
{
	ZeroIScene::Render();

	if (contacting)
		attack->Render();

	else if (chasing)
		senseMove->Render();

	else if (moving)
		move->Render();
	
	else
		normal->Render();
}

void Monster::isChased(float _eTime, bool _2d/* = false*/)
{
	if (chasing && !contacting)
	{
		if (_2d)
		{
			moveX = r2_x - r1_x; // 2차원 이동 (괜히 함 은 아니였음)
			moveY = r2_y - r1_y;

			if (moveX < 0)
				moveX *= -1;
			if (moveY < 0)
				moveY *= -1;

			moveX /= speed;
			moveY /= speed;


			if (r2_x - r1_x < 0 && r2_y - r1_y < 0) // 몬스터가 플레이어 왼쪽 위에 있을 때 (즉 오른쪽 아래로 움직일 때)
			{
				this->AddPos(moveX, moveY);
				if (!right)
					right = true;
			}
			else if (r2_x - r1_x < 0) // 몬스터가 플레이어 왼쪽 아래에 있을 때 (즉 오른쪽 위로 움직일 때)
			{
				this->AddPos(moveX, -1 * moveY);
				if (!right)
					right = true;
			}
			else if (r2_y - r1_y < 0) // 몬스터가 플레이어 오른쪽 위에 있을 때 (즉 왼쪽 아래로 움직일 때)
			{
				this->AddPos(-1 * moveX, moveY);
				if (right)
					right = false;
			}
			else // 몬스터가 플레이어 오른쪽 아래에 있을 때 (즉 왼쪽 위로 움직일 때)
			{
				this->AddPos(-1 * moveX, -1 * moveY);
				if (right)
					right = false;
			}
		}
		else
		{
			if (r2_x - r1_x < 0)
			{
				this->AddPosX(speed * _eTime);
				right = true;
			}
			else
			{
				this->AddPosX(-1 * speed * _eTime);
				right = false;
			}
		}
	}
}

void Monster::perceive(Player *_player)
{
	r1_x = _player->Pos().x + _player->Width() / 2;
	r1_y = _player->Pos().y + _player->Height() / 2;
	r2_x = this->Pos().x + this->Width() / 2;
	r2_y = this->Pos().y + this->Height() / 2;

	l = sqrtf(powf((r2_x - r1_x), 2) + pow((r2_y - r1_y), 2));

	if (l < 0)
		l *= -1;

	if (_player->Width() / 2 + this->Width() / 2 + 200 >= l)
		chasing = true;
	else
		chasing = false;
}

void Monster::isContacted(bool tr)
{
	this->contacting = tr;
}

bool Monster::isContacted()
{
	return this->contacting;
}