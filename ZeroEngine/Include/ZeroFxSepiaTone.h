#pragma once

#include "ZeroIShader.h"

class ZeroFxSepiaTone : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

public:
	ZeroFxSepiaTone(float time, char* renderpage);
	~ZeroFxSepiaTone();

	void Update(float eTime);
};
