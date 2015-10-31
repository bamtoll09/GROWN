#include "stdafx.h"
#include "Box.h"


Box::Box(Player *_player)
	:SeTime(0)
{
	this->player = _player;
	box = new ZeroSprite("Texture/Box/box.png");
	this->SetWidth(box->Width());
	this->SetHeight(box->Height());
	PushScene(box);
}

Box::~Box()
{
}

void Box::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	if (player->isReverse()) // �߷��� �ٲ��� ��
	{
		if (player->Pos().y < Pos().y + Height() && player->Pos().y >= Pos().y)
		{
			if (player->Pos().x + player->Width() >= Pos().x + 20 && player->Pos().x + player->Width() <= Pos().x + 40) // ���ʿ��� �� ��
				SetPosX(player->Pos().x + player->Width() - 20);
			else if (player->Pos().x <= Pos().x + Width() - 20 && player->Pos().x >= Pos().x + Width() - 40) // �����ʿ��� �� ��
				SetPosX(player->Pos().x - Width() + 20);
		}

		if (Pos().y > 0) // �ο� �� ���� ��
		{
			this->AddPosY(SeTime * eTime);
			SeTime -= 30.f;
		}

		else if (Pos().y <= 0) // ������ �������� �ʵ���
		{
			this->SetPosY(0);
			SeTime = 0;
		}

		if (player->Pos().y <= Pos().y + Height()) // ���� ���� �ö��� ��
		{
			if (player->Pos().x + player->Width() > Pos().x + 30 && player->Pos().x < Pos().x + Width() - 30)
			{
				player->SetPosY(Height());
				if (player->JumpNum != 0)
					player->JumpNum = 0;
				if (!player->isOnBox())
					player->isOnBox(true);
			}
			else if (player->Pos().x + player->Width() <= Pos().x + 30 && player->Pos().x >= Pos().x + Width() - 30 && player->isOnBox())
				player->isOnBox(false);
		}

		if (Pos().x <= 0) // ���ڰ� �� ������ ������ �� (����)
		{
			SetPosX(0);
			if (player->Pos().y < Height() && player->Pos().x <= Pos().x + Width() - 20 && player->Pos().x >= Pos().x + Width() - 40)
				player->SetPosX(Pos().x + Width() - 20);
		}

		if (Pos().x + Width() >= ZeroCameraManager::Instance()->Width()) // (������)
		{
			SetPosX(ZeroCameraManager::Instance()->Width() - Width());
			if (player->Pos().y < Height() && player->Pos().x + player->Width() >= Pos().x + 20 && player->Pos().x + player->Width() <= Pos().x + 40)
				player->SetPosX(ZeroCameraManager::Instance()->Width() - Width() - player->Width() + 20);
		}
	}

	else // �߷��� ���� �� ��
	{
		if (Pos().y < ZeroApplication::Instance()->GetWindowHeight() - Height()) // �ο� �� ���� ��
		{
			this->AddPosY(SeTime * eTime);
			SeTime += 30.f;
		}

		else if (Pos().y >= ZeroApplication::Instance()->GetWindowHeight() - Height()) // ������ �������� �ʵ���
		{
			this->SetPosY(ZeroApplication::Instance()->GetWindowHeight() - Height());
			SeTime = 0;
		}

		if (player->Pos().y + player->Height() > Pos().y && player->Pos().y + player->Height() <= Pos().y + Height())
		{
			if (player->Pos().x + player->Width() >= Pos().x + 20 && player->Pos().x + player->Width() <= Pos().x + 40) // ���ʿ��� �� ��
				SetPosX(player->Pos().x + player->Width() - 20);
			else if (player->Pos().x <= Pos().x + Width() - 20 && player->Pos().x >= Pos().x + Width() - 40) // �����ʿ��� �� ��
				SetPosX(player->Pos().x - Width() + 20);
		}

		if (player->Pos().y + player->Height() >= this->Pos().y) // ���� ���� �ö��� ��
		{
			if (player->Pos().x + player->Width() > this->Pos().x + 30 && player->Pos().x < this->Pos().x + this->Width() - 30)
			{
				player->SetPosY(ZeroApplication::Instance()->GetWindowHeight() - player->Height() - Height());
				if (player->JumpNum != 0)
					player->JumpNum = 0;
				if (!player->isOnBox())
					player->isOnBox(true);
			}
			else if (player->Pos().x + player->Width() <= this->Pos().x + 30 && player->Pos().x >= this->Pos().x + this->Width() - 30 && player->isOnBox())
				player->isOnBox(false);
		}

		if (Pos().x <= 0) // ���ڰ� �� ������ ������ �� (����)
		{
			SetPosX(0);
			if (player->Pos().y + player->Height() > Pos().y && player->Pos().x <= Pos().x + Width() - 20 && player->Pos().x >= Pos().x + Width() - 40)
				player->SetPosX(Pos().x + Width() - 20);
		}

		if (Pos().x + Width() >= ZeroCameraManager::Instance()->Width()) // (������)
		{
			SetPosX(ZeroCameraManager::Instance()->Width() - Width());
			if (player->Pos().y + player->Height() > Pos().y && player->Pos().x + player->Width() >= Pos().x + 20 && player->Pos().x + player->Width() <= Pos().x + 40)
				player->SetPosX(ZeroCameraManager::Instance()->Width() - Width() - player->Width() + 20);
		}
	}
}

void Box::Render()
{
	ZeroIScene::Render();
	box->Render();
}