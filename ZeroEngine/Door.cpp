#include "stdafx.h"
#include "Door.h"
#include "Scene.h"

Door::Door(int no)
	:entered(false)
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
		case 1: // StartScene
			ZeroSceneMgr->ChangeScene(new BlankScene<StartScene>(1.f, 0.5f), TR::Fade, 0.5);
			break;

		case 2: // 1-1
			ZeroSceneMgr->ChangeScene(new BlankScene<Stage1_1>(1.f, 0.5f), TR::Fade, 0.5);
			//ZeroSceneMgr->ChangeScene(new Stage1_1, 3, 2.f, TR::Fade);
			break;

		case 3: // 1-2
			ZeroSceneMgr->ChangeScene(new BlankScene<Stage1_2>(1.f, 0.5f), TR::Fade, 0.5);
			break;

		case 4: // 1-3
			//ZeroSceneMgr->ChangeScene(new BlankScene<StartScene>(1.f, 0.5f), TR::Fade, 0.5);
			break;

		case 5: // 2-1
			//ZeroSceneMgr->ChangeScene(new BlankScene<StartScene>(1.f, 0.5f), TR::Fade, 0.5);
			break;

		case 6: // 2-2
			//ZeroSceneMgr->ChangeScene(new BlankScene<StartScene>(1.f, 0.5f), TR::Fade, 0.5);
			break;

		case 7: // 2-3
			//ZeroSceneMgr->ChangeScene(new BlankScene<StartScene>(1.f, 0.5f), TR::Fade, 0.5);
			break;

		case 8: // 3-1
			//ZeroSceneMgr->ChangeScene(new BlankScene<StartScene>(1.f, 0.5f), TR::Fade, 0.5);
			break;

		case 9: // 3-2
			//ZeroSceneMgr->ChangeScene(new BlankScene<StartScene>(1.f, 0.5f), TR::Fade, 0.5);
			break;

		case 10: // 3-3
			//ZeroSceneMgr->ChangeScene(new BlankScene<StartScene>(1.f, 0.5f), TR::Fade, 0.5);
			break;

		case 11: // AchievementScene
			//ZeroSceneMgr->ChangeScene(new BlankScene<StartScene>(1.f, 0.5f));
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