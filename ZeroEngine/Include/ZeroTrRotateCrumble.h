#pragma once
#include "ZeroIShader.h"

class ZeroTrRotateCrumble : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pCloudTex;
	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrRotateCrumble(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrRotateCrumble();

	void Update(float eTime);
};