#pragma once
#include "ZeroIShader.h"

class ZeroTrCircleStretch : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

	LPDIRECT3DTEXTURE9 m_pSecondTex;
public:
	ZeroTrCircleStretch(float time, char* renderpage, LPDIRECT3DTEXTURE9 secondTex);
	~ZeroTrCircleStretch();

	void Update(float eTime);
};