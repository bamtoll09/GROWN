#pragma once
#include "ZeroIShader.h"

class ZeroFxShake : public ZeroIShader{
private:
	float m_fStrength;
	float m_fTime;
	float m_fBeginTime;
public:
	ZeroFxShake(float power_0_0p25,float time,char* renderpage);
	~ZeroFxShake();

	void Update(float eTime);
};