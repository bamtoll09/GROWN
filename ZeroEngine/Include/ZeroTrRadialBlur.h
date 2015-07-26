#pragma once
#include "ZeroIShader.h"

class ZeroTrRadialBlur : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrRadialBlur(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrRadialBlur();

	void Update(float eTime);
};