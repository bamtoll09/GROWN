#pragma once
#include "ZeroIShader.h"

class ZeroTrCircleReveal : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrCircleReveal(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrCircleReveal();

	void Update(float eTime);
};