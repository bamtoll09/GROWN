#include "stdafx.h"
#include "Box.h"


Box::Box(ZeroIScene *_target)
{
	this->target = _target;
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
	if (target->Pos().y + target->Height() > Pos().y && target->Pos().y + target->Height() <= Pos().y + Height())
	{
		if (target->Pos().x + target->Width() >= Pos().x + 20 && target->Pos().x + target->Width() <= Pos().x + 40) // ���ʿ��� �� ��
			SetPosX(target->Pos().x + target->Width() - 20);
		else if (target->Pos().x <= Pos().x + Width() - 20 && target->Pos().x >= Pos().x + Width() - 40) // �����ʿ��� �� ��
			SetPosX(target->Pos().x - Width() + 20);
	}

	if (target->Pos().y + target->Height() >= Pos().y) // ���� ���� �ö��� ��
	{
		if (target->Pos().x + target->Width() > Pos().x + 30 && target->Pos().x < Pos().x + Width() - 30)
			target->SetPosY(ZeroApplication::Instance()->GetWindowHeight() - target->Height() - Height());
	}

	if (Pos().x <= 0) // ���ڰ� �� ������ ������ �� (����)
		SetPosX(0);

	if (Pos().x + Width() >= ZeroCameraManager::Instance()->Width()) // (������)
	{
		SetPosX(ZeroCameraManager::Instance()->Width() - Width());
	}
}

void Box::Render()
{
	ZeroIScene::Render();
	box->Render();
}