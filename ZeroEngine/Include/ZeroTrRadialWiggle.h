#pragma once
#include "ZeroIShader.h"

class ZeroTrRadialWiggle : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pCloudTex;
	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrRadialWiggle(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrRadialWiggle();

	void Update(float eTime);
};