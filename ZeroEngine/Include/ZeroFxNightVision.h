#pragma once
#include "ZeroIShader.h"
#include "ZeroResource.h"

class ZeroFxNightVision : public ZeroIShader, public ZeroResource{
private:
	LPDIRECT3DTEXTURE9 m_pTexNoise;
	float m_fTime;
	float m_fBeginTime;

	//경과시간
	float m_fFrame;
public:
	ZeroFxNightVision(float time,char* renderpage);
	~ZeroFxNightVision();

	void Update(float eTime);

private:
	void ReloadResource() ;
};