#pragma once
#include "ZeroIShader.h"

class ZeroTrCrumble : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pCloudTex;
	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrCrumble(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrCrumble();

	void Update(float eTime);
};