#include "stdafx.h"
#include "Ladder.h"


Ladder::Ladder(int no)
{
	ladderNum = no;

	switch (ladderNum)
	{
	case 0:
		ladder = new ZeroSprite("Texture/Ladder/ladder0.png");
		break;

	case 1:
		ladder = new ZeroSprite("Texture/Ladder/ladder.png");
		break;
	}

	SetWidth(ladder->Width());
	SetHeight(ladder->Height());
	PushScene(ladder);
}

Ladder::~Ladder()
{
}

void Ladder::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}

void Ladder::Render()
{
	ZeroIScene::Render();
	ladder->Render();
}
