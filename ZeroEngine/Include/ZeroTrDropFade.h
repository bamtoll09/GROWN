#pragma once
#include "ZeroIShader.h"

class ZeroTrDropFade : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pCloudTex;
	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrDropFade(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrDropFade();

	void Update(float eTime);
};