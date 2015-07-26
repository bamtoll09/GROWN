#pragma once
#include "ZeroIShader.h"

class ZeroTrSaturate : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrSaturate(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrSaturate();

	void Update(float eTime);
};