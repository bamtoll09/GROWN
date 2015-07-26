#pragma once
#include "ZeroIShader.h"

class ZeroTrFade : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrFade(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrFade();

	void Update(float eTime);
};