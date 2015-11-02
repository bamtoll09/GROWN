#include "stdafx.h"
#include "MapMaker.h"


MapMaker::MapMaker(int _stage, int _w, int _h, Player *_player, Ladder *_ladder, Door *_door[5], Tile *_border[1500]/*= NULL*/)
	:n(0), o(0)
{
	player = _player;
	ladder = _ladder;

	if (_border != NULL)
		for (int i = 0; i < 1500; i++)
			border[i] = _border[i];
	else
		border[0] = NULL;

	for (int i = 0; i < 5; i++)
		door[i] = _door[i];
	stage = _stage;
	w = _w;
	h = _h;
	
	switch (stage)
	{
	case 00:
		map = fopen("Map/start.dat", "r");
		break;

	case 11:
		map = fopen("Map/stage1_1.dat", "r");
		break;
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (fscanf(map, "%d", &stages[i][j]) == EOF)
				break;
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (border[0] != NULL)
			{
				if (stages[i][j] == 1)
				{
					border[n]->SetPos(j * 11, i * 10);
					n++;
				}
			}
			else if (stages[i][j] == 2)
				player->SetPos(j * 11, i * 10);
			else if (stages[i][j] == 4)
				ladder->SetPos(j * 11, i * 10);
			else if (stages[i][j] == 8)
			{
				door[o]->SetPos(j * 11, i * 10);
				o++;
			}
		}
	}
}


MapMaker::~MapMaker()
{
}

void MapMaker::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}

void MapMaker::Render()
{
	ZeroIScene::Render();
}