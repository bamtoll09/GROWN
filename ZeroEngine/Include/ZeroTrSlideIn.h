#pragma once
#include "ZeroIShader.h"

class ZeroTrSlideIn : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrSlideIn(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrSlideIn();

	void Update(float eTime);
};