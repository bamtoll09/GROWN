#include "stdafx.h"
#include "MapMaker.h"


MapMaker::MapMaker(int _stage, int _w, int _h)
{
	stage = _stage;
	w = _w;
	h = _h;
	
	switch (stage)
	{
	case 11:
		map = fopen("Map/stage1_1.dat", "r");
		break;
	}

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (fscanf(map, "%d", stages[i][j]) == EOF) {
				break;
			}
		}
		if (i == w - 1)
			break;
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