#pragma once
#include "ZeroIShader.h"

class ZeroTrBandedSwirl : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrBandedSwirl(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrBandedSwirl();

	void Update(float eTime);
};