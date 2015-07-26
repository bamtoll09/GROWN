#pragma once
#include "ZeroIShader.h"

class ZeroTrCloudReveal : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pCloudTex;
	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrCloudReveal(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrCloudReveal();

	void Update(float eTime);
};