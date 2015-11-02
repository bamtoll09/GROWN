#include "stdafx.h"
#include "Scene.h"

MainScene::MainScene()
{
	in = ZeroInputMgr;

	bg = new ZeroSprite("Texture/Title/title.png");

	start = new ZeroSprite("Texture/Title/start.png");
	start->SetPos(568, 420);

	exit = new ZeroSprite("Texture/Title/exit.png");
	exit->SetPos(582, 580);

	//cursor = in->GetClientRect();

	startRect.left = start->Pos().x;
	startRect.top = start->Pos().y;
	startRect.right = start->Pos().x + start->Width();
	startRect.bottom = start->Pos().y + start->Height();

	exitRect.left = exit->Pos().x;
	exitRect.top = exit->Pos().y;
	exitRect.right = exit->Pos().x + exit->Width();
	exitRect.bottom = exit->Pos().y + exit->Height();
	
	PushScene(bg);
	PushScene(start);
	PushScene(exit);
}


MainScene::~MainScene()
{
}

void MainScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	if (IntersectRect(&temp, &in->GetClientRect(), &startRect) && in->GetKey(MK_LBUTTON) == INPUTMGR_KEYDOWN)
	{
		f = fopen("Save\\save.dat", "r");

		for (int i = 0; i < 7; i++)
			fscanf(f, "%d", &save[i]);

		fclose(f);

		switch (save[6])
		{
		case 00:
			ZeroSceneMgr->ChangeScene(new BlankScene<StartScene>);
			//ZeroSceneMgr->ChangeScene(new StartScene(), 3, TR::Fade);
			break;

		case 11:
			ZeroSceneMgr->ChangeScene(new BlankScene<Stage1_1>);
			//ZeroSceneMgr->ChangeScene(new StartScene(), 3, TR::Fade);
			break;

		case 12:
			ZeroSceneMgr->ChangeScene(new BlankScene<Stage1_2>);
		}
	}

	if (IntersectRect(&temp, &in->GetClientRect(), &exitRect) && in->GetKey(MK_LBUTTON) == INPUTMGR_KEYDOWN)
	{
		ZeroSceneMgr->ChangeScene(new BlankSceneExit(), TR::Fade);
	}
}

void MainScene::Render()
{
	ZeroIScene::Render();

	bg->Render();

	start->Render();

	exit->Render();
}