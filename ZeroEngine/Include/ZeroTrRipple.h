#pragma once
#include "ZeroIShader.h"

class ZeroTrRipple : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrRipple(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrRipple();

	void Update(float eTime);
};