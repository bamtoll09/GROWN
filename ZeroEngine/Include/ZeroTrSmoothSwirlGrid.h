#pragma once
#include "ZeroIShader.h"

class ZeroTrSmoothSwirlGrid : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrSmoothSwirlGrid(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrSmoothSwirlGrid();

	void Update(float eTime);
};