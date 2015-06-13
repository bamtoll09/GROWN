#pragma once
#include "DXUT.h"
#include "ZeroResource.h"

#define ZeroCursorMgr ZeroCursorManager::Instance()

class ZeroCursorManager : public ZeroResource{
private:
	LPDIRECT3DSURFACE9 m_pCursorSurface;

	bool m_bCursor;

	ZeroCursorManager();
public:
	~ZeroCursorManager();

	void SetCursorShape();

	void UpdateCursorShape();

	void SetCursorOn();
	void SetCursorOff();
	void SetCursorToggle();
	bool IsShowingCursor();
	
	static ZeroCursorManager* Instance();

private:
	void ReloadResource() ;
};