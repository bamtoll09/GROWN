#include "stdafx.h"
#include "Player.h"

Player::Player(void)
	:scaleX(1.f), scaleY(1.f), moving(false), left(false), jumping(false), shooting(false), reversing(false), jumpH(600.f), JeTime(0.f), GeTime(0.f), JumpNum(0)
{
	normal = new ZeroSprite("Texture/Player/0.png");
	PushScene(normal);
	
	shoot = new ZeroSprite("Texture/Player/shooting.png");
	PushScene(shoot);

	move = new ZeroAnimation(6.0f);
	PushScene(move);
	move->PushSprite("Texture/Player/1.png");
	move->PushSprite("Texture/Player/2.png");
	move->PushSprite("Texture/Player/3.png");
	move->PushSprite("Texture/Player/4.png");
	move->PushSprite("Texture/Player/5.png");
	move->PushSprite("Texture/Player/6.png");

	this->SetWidth(normal->Width());
	this->SetHeight(normal->Height());
	this->SetScalingCenter(Width() / 2, Height() / 2);
	this->SetRotCenter(Width() / 2, Height() / 2);
}


Player::~Player(void)
{
}

void Player::Update(float eTime)
{
	ZeroIScene::Update(eTime);


	if (m_vPos.x <= 0) // �÷��̾ �� ���� ���� ���� �� �������� ����
		SetPosX(0);
	if (m_vPos.x >= 2942)
		SetPosX(2942);

	if (shooting) // �÷��̾ ���� �� �� �ݵ����� ���� �ݵ��� ���� ��¦ ����
	{
		GeTime += eTime;
		if (GeTime >= 0.5f)
		{
			shooting = false;
			GeTime = 0.f;
		}
	}

	if (reversing) // �߷��� �������� ��
	{
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

		if (JeTime <= 0)
		{
			JeTime = 0;
		}

		if (jumping)
		{
			if (JumpNum == 1) // �÷��̾ �������� ��
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

			if (JumpNum == 2) // ���� ���� ��
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

		else if (Pos().y > 0) // ���߿� ���� �� �ٴ����� ������
		{
			this->AddPosY(-1 * (jumpH - JeTime) * eTime);
			JeTime -= 30.f;
		}

		if (this->Pos().y <= 0) // �÷��̾ ������ �ٴڿ� ����
		{
			this->SetPosY(0);
			if (jumping)
				jumping = false;
			falling = false;
			JeTime = 0.f;
			JumpNum = 0;
		}
	}

	else // �߷��� ������ ��
	{
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

		if (JeTime <= 0)
		{
			JeTime = 0;
		}

		if (jumping)
		{
			if (JumpNum == 1) // �÷��̾ �������� ��
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

			if (JumpNum == 2) // ���� ���� ��
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
		}

		else if (falling)
		{
			if (Pos().y < 548)
			{
				this->AddPosY((jumpH - JeTime) * eTime);
				JeTime -= 30.f;
			}
		}

		else if (Pos().y < 548) // ���߿� ���� �� �ٴ����� ������
		{
			this->AddPosY((jumpH - JeTime) * eTime);
			JeTime -= 30.f;
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

		if (this->Pos().y >= 548) // �÷��̾ ������ �ٴڿ� ����
		{
			this->SetPosY(548);
			if (jumping)
				jumping = false;
			falling = false;
			JeTime = 0.f;
			JumpNum = 0;
		}
	}
}

void Player::Render()
{
	ZeroIScene::Render();

	if (shooting)
	{
		shoot->Render();
	}

	else if (moving)
	{
		move->Render();
		moving = false;
	}

	else
	{
		normal -> Render();
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
		this->m_vPos.x += _dx;
		moving = true;
	}
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

bool Player::isJump()
{
	return this -> jumping;
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