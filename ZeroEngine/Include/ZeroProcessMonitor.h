#pragma once
#include <Pdh.h>

class ZeroProcessMonitor{
        // 생성자/소멸자
public:
        ZeroProcessMonitor();
        virtual ~ZeroProcessMonitor();

        // 멤버 함수
public:
        HRESULT Create();
        void Close();

        float GetCpuUsage();
        DWORD GetMemoryUsage();

protected:
        HRESULT CreateCpuUsageCounter();
        void CloseCpuUsageCounter();

        // 멤버 변수
protected:
        HANDLE m_hProcess;
        TCHAR m_szProcessName[ MAX_PATH ];

        HQUERY m_hCpuUsageQuery;
        HCOUNTER m_hCpuUsageCounter;
};