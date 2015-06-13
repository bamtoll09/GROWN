#pragma once
#include "DXUT.h"
#include "ZeroRingBuffer.h"
#include "ZeroProcessMonitor.h"
#include "ZeroRegulator.h"

#define ZeroApp ZeroApplication::Instance()

class ZeroApplication{
private:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pD3D9Device;
	D3DPRESENT_PARAMETERS m_D3D9DeviceProperty ;

	HWND m_Hwnd;

	ZeroRingBuffer<LONGLONG,10> m_Times;
	ZeroProcessMonitor m_ProcessMonitor;
	ZeroRegulator* m_pProcessCpuUsageRegulator;
	ZeroRegulator* m_pProcessMemoryUsageRegulator;

	float m_fFPS;
	float m_fMemoryUsage;
	float m_fCpuUsage;

	int m_WindowWidth ;
	int m_WindowHeight ;

	ZeroApplication();
public:
	~ZeroApplication();

	static ZeroApplication* Instance();
	
	void RegisterWindowSize(int _iWindowWidth, int _iWindowHeight) ;
	HRESULT InitD3D(HWND hWnd, bool _iIsFullScreen = false);
	void Cleanup();
	void Update(float eTime);
	void Render();
	static LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );

	void CalculateFPS();
	void CalculateMemoryUsage();
	void CalculateCpuUsage();

	void SetHwnd(HWND hwnd){m_Hwnd = hwnd;}
	HWND GetHwnd()const{return m_Hwnd;}
	LPDIRECT3DDEVICE9 GetDevice()const{return m_pD3D9Device;}
	float GetFPS()const{return m_fFPS;}
	float GetMemoryUsage()const{return m_fMemoryUsage;}
	float GetCpuUsage()const{return m_fCpuUsage;}
	int GetWindowWidth() ;
	int GetWindowHeight() ;

private:
	bool CheckAndResetDevice() ;
};