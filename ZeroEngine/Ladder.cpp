#include "stdafx.h"
#include "Ladder.h"


Ladder::Ladder(Player *_player)
{
	player = _player;

	ladder = new ZeroSprite("");
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
