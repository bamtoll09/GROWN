#pragma once
#include "ZeroIShader.h"

class ZeroTrRandomCircleReveal : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pCloudTex;
	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrRandomCircleReveal(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrRandomCircleReveal();

	void Update(float eTime);
};