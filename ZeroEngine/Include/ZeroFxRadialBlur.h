#pragma once
#include "ZeroIShader.h"

class ZeroFxRadialBlur : public ZeroIShader{
private:
	float m_fTime;
	float m_fBeginTime;
	float m_fPower;

	D3DXVECTOR4 m_vCenter;
	float m_fBlurStart;
	float m_fBlurWidth;
public:
	ZeroFxRadialBlur(float time,float power_0_1,char* renderpage);
	~ZeroFxRadialBlur();

	void Update(float eTime);

	void SetCenter(float x,float y){m_vCenter.x=x;m_vCenter.y=y;}
};