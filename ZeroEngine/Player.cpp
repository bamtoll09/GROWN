#include "stdafx.h"
#include "Player.h"

Player::Player(void)
	:scaleX(1.f), scaleY(1.f), moving(false), left(false), jumping(false), shooting(false), reversing(false),
	doubleJumping(false), smalling(false), changing(false), climbing(false), reading(false), downJumping(false),
	onBox(false), onGround(false), jumpH(600.f), JeTime(0.f), GeTime(0.f), JumpNum(0), MaxLeft(0), MaxRight(0)
{
	f = fopen("Save\\save.dat", "r");
	
	for (int i = 0; i < 7; i++)
		fscanf(f, "%d", &save[i]);

	fclose(f);

	sound = ZeroSoundMgr;
	sound->PushSound("Sound/jump.mp3", "jumpSound");
	sound->PushSound("Sound/doublejump.mp3", "djumpSound");

	normal = new ZeroSprite("Texture/Player/0.png");
	PushScene(normal);

	shoot = new ZeroSprite("Texture/Player/shooting.png");
	PushScene(shoot);

	move = new ZeroAnimation(6.0f);
	move->PushSprite("Texture/Player/1.png");
	move->PushSprite("Texture/Player/2.png");
	move->PushSprite("Texture/Player/3.png");
	move->PushSprite("Texture/Player/4.png");
	move->PushSprite("Texture/Player/5.png");
	move->PushSprite("Texture/Player/6.png");
	PushScene(move);

	fall = new ZeroSprite("Texture/Player/fall.png");
	PushScene(fall);

	jump = new ZeroSprite("Texture/Player/jump.png");
	PushScene(jump);

	jump2 = new ZeroSprite("Texture/Player/jump2.png");
	PushScene(jump2);

	read = new ZeroSprite("Texture/Player/reading.png");
	PushScene(read);

	this->SetWidth(normal->Width());
	this->SetHeight(normal->Height());
	this->SetScalingCenter(Width() / 2, Height());
	this->SetRotCenter(Width() / 2, Height() / 2);
}


Player::~Player(void)
{
}

void Player::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	if (!reading)
	{

		if (smalling)
		{
			if (this->scaleY == 1.f)
			{
				this->scaleX = 0.5f;
				this->scaleY = 0.5f;
			}
		}
		else
		{
			if (this->scaleY == 0.5f)
			{
				this->scaleX = 1.f;
				this->scaleY = 1.f;
			}
		}


		if (this->Pos().x <= MaxLeft) // 플레이어가 맵 끝에 도달 했을 때 못나오게 유지
			SetPosX(MaxLeft);
		if (this->Pos().x >= MaxRight)
			SetPosX(MaxRight);

		if (shooting) // 플레이어가 총을 쏠 시 반동같지 않은 반동에 의해 살짝 멈춤
		{
			GeTime += eTime;
			if (GeTime >= 0.5f)
			{
				shooting = false;
				GeTime = 0.f;
			}
		}

		if (reversing) // 중력이 뒤집혔을 때
		{
			if (this->Rot() != 180) // 뒤집혔는지 여부
				this->SetRot(180);

			if (left)
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

			if (jumping)
			{
				if (JumpNum == 1) // 플레이어가 점프했을 때
				{
					if ((jumpH - JeTime) >= 0.f && JeTime < 650.f)
					{
						this->AddPosY((jumpH - JeTime) * eTime);
						JeTime += 30.f;
					}
					else
					{
						jumping = false;
						falling = true;
					}
				}

				if (JumpNum == 2) // 더블 점프 시
				{
					if ((jumpH - JeTime) >= 0.f && JeTime < 650.f)
					{
						this->AddPosY((jumpH - JeTime) * eTime);
						JeTime += 30.f;
					}
					else
					{
						jumping = false;
						falling = true;
					}
				}
			}

			else if (falling)
			{
				if (Pos().y > 0)
				{
					this->AddPosY(-1 * (jumpH - JeTime) * eTime);
					JeTime -= 30.f;
				}
			}

			else if (Pos().y > 0) // 공중에 있을 시 바닥으로 슈우우웅
			{
				if (!changing && !onBox)
					changing = true;
				this->AddPosY(JeTime * eTime);
				JeTime -= 30.f;
			}

			if (this->Pos().y <= 0) // 플레이어가 점프시 바닥에 착지
			{
				this->SetPosY(0);
				if (jumping)
					jumping = false;
				falling = false;
				JeTime = 0.f;
				JumpNum = 0;
				if (changing)
					changing = false;
			}
		}

		else // 중력이 정상일 때
		{
		if (this->Rot() != 0) // 원래대로 돌아왔는지 여부
			this->SetRot(0);

			if (left)
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

			if (climbing)
			{
				jumping = false;
				JumpNum = 0;
				JeTime = 0.f;
			}

			if (jumping && !climbing)
			{
				onGround = false;
				if (JumpNum == 1) // 플레이어가 점프했을 때
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

				if (doubleJumping && JumpNum == 2) // 더블 점프 시
				{
					onGround = false;
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
			}

			else if (falling && !climbing && !downJumping)
			{
				if (save[6] == 00)
				{
					if (this->Pos().y < 792 - this->Height())
					{
						this->AddPosY((jumpH - JeTime) * eTime);
						JeTime -= 30.f;
					}
					else if (this->Pos().y < 1490 - this->Height() && this->Pos().y + this->Height() > 812)
					{
						this->AddPosY((jumpH - JeTime) * eTime);
						JeTime -= 30.f;
					}
					else if (this->Pos().y < 2190 - this->Height() && this->Pos().y + this->Height() > 1512)
					{
						this->AddPosY((jumpH - JeTime) * eTime);
						JeTime -= 30.f;
					}
					else if (this->Pos().y < 2890 - this->Height() && this->Pos().y + this->Height() > 2212)
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
			}

			else if (!onGround && (!climbing || downJumping)) // 공중에 있을 시 바닥으로 슈우우웅
			{/*
				if (!changing && !onBox)
					changing = true;*/
				this->AddPosY(JeTime * eTime);
				JeTime += 30.f;
			}

			if (onGround) // 플레이어가 바닥에 착지
			{
				falling = false;
				jumping = false;
				changing = false;
				downJumping = false;
				JeTime = 0.f;
				JumpNum = 0;
			}

			if (shooting)
			{
				GeTime += eTime;
				if (GeTime >= 0.5f)
				{
					shooting = false;
					GeTime = 0.f;
				}
			}
		}
	}
}

void Player::Render()
{
	ZeroIScene::Render();
	
	if (reading)
		read->Render();

	else if (shooting)
		shoot->Render();

	else if (jumping && JumpNum == 1 && !falling)
		jump->Render();

	else if (doubleJumping && JumpNum == 2 && !falling)
		jump2->Render();

	else if (falling && !onBox && !onGround && !climbing)
		fall->Render();

	else if (moving || climbing)
	{
		move->Render();
		moving = false;
	}

	else
	{
		normal->Render();
	}
}

void Player::setScale(float X, float Y)
{
	this->scaleX = X;
	this->scaleY = Y;
}

void Player::Move(float _dx)
{
	if (!shooting)
	{
		left = (bool)(_dx <= 0);
		this->AddPosX(_dx);
		moving = true;
	}
}

void Player::Climb(float _dx)
{
	if (climbing)
	{
		this->AddPosY(_dx);
	}
}

void Player::isMove(bool tr)
{
	this->moving = tr;
}

void Player::isJump(bool tr)
{
	this->jumping = tr;
}

void Player::isFall(bool tr)
{
	this->falling = tr;
}

void Player::isShoot(bool tr)
{
	this->shooting = tr;
}

void Player::isReverse(bool tr)
{
	this->reversing = tr;
}

void Player::isDoubleJump(bool tr)
{
	this->doubleJumping = tr;
}

void Player::isSmall(bool tr)
{
	this->smalling = tr;
}

void Player::isChange(bool tr)
{
	this->changing = tr;
}

void Player::isClimb(bool tr)
{
	this->climbing = tr;
}

void Player::isRead(bool tr)
{
	this->reading = tr;
}

void Player::isDownJump(bool tr)
{
	this->downJumping = tr;
}

void Player::isOnBox(bool tr)
{
	this->onBox = tr;
}

void Player::isOnGround(bool tr)
{
	this->onGround = tr;
}




bool Player::isMove()
{
	return this->moving;
}

bool Player::isJump()
{
	return this->jumping;
}

bool Player::isFall()
{
	return this->falling;
}

bool Player::isShoot()
{
	return this->shooting;
}

bool Player::isReverse()
{
	return this->reversing;
}

bool Player::isDoubleJump()
{
	return this->doubleJumping;
}

bool Player::isSmall()
{
	return this->smalling;
}

bool Player::isChange()
{
	return this->changing;
}

bool Player::isClimb()
{
	return this->climbing;
}

bool Player::isRead()
{
	return this->reading;
}

bool Player::isDownJump()
{
	return this->downJumping;
}

bool Player::isOnBox()
{
	return this->onBox;
}

bool Player::isOnGround()
{
	return this->onGround;
}