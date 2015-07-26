#pragma once

#include <Windows.h>
#include "ZeroMathManager.h"

class ZeroRegulator {
private:
	float m_fUpdatePeriod;
	DWORD m_dwNextUpdateTime;

public:
	ZeroRegulator(float NumUpdatePerSecond) {
		m_dwNextUpdateTime = (DWORD) (timeGetTime() + ZeroMathMgr->RandFloat(0, 1) * 1000);

		if (NumUpdatePerSecond > 0)
			m_fUpdatePeriod = 1000.0f / NumUpdatePerSecond;
		else if (NumUpdatePerSecond < 0)
			m_fUpdatePeriod = -1.0f;
		else
			m_fUpdatePeriod = 0.0f;
	}

	bool IsReady() {
		if (m_fUpdatePeriod == 0) return true;
		if (m_fUpdatePeriod < 0) return false;

		DWORD dwCurrentTime = timeGetTime();

		//변화를 주기 위한 아주 조그마한 수
		static const float UpdatePeriodVariator = 10.0f;

		if (dwCurrentTime > m_dwNextUpdateTime) {
			m_dwNextUpdateTime = (DWORD) (dwCurrentTime + m_fUpdatePeriod + ZeroMathMgr->RandFloat(-UpdatePeriodVariator, UpdatePeriodVariator));
			return true;
		}

		return false;
	}
};
