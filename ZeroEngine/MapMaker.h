#pragma once
#include <Zero.h>
class MapMaker :
	public ZeroIScene
{
private:
	FILE *map;
	int stage;
	int w, h;
public:
	MapMaker(int _stage, int _w, int _h);
	~MapMaker();

	int stages[100][100];

	virtual void Update(float eTime);
	virtual void Render();
};

