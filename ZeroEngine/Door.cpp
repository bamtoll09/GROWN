#include "stdafx.h"
#include "Door.h"
#include "BlankScene.h"
#include "BlankSceneExit.h"


Door::Door(int no)
{
	doorNum = no;

	door = new ZeroSprite("Texture/Door/door.png");
	this->SetWidth(door->Width());
	this->SetHeight(door->Height());
	PushScene(door);
}


Door::~Door()
{
}

void Door::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	if (entered)

	{
		switch (doorNum)
		{
		case 1:
			//ZeroSceneMgr->ChangeScene(new BlankScene(GameScene, 2.f, 2.f), TR::Fade, 1);
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			break;

		case 8:
			break;

		case 9:
			break;
		}
	}
}

void Door::Render()
{
	ZeroIScene::Render();
	door->Render();
}

void Door::isEntered(bool tr)
{
	this->entered = tr;
}

bool Door::isEntered()
{
	return this->entered;
}