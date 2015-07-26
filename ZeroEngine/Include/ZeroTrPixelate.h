#pragma once
#include "ZeroIShader.h"

class ZeroTrPixelate : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrPixelate(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrPixelate();

	void Update(float eTime);
};