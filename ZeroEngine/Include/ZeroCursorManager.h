#pragma once

#include "DXUT.h"
#include "ZeroResource.h"

#pragma warning(disable: 4996)

#define ZeroCursorMgr ZeroCursorManager::Instance()

class ZeroCursorManager : public ZeroResource {
private:
	ZeroCursorManager();

	LPDIRECT3DSURFACE9 m_pCursorSurface;
	bool m_bCursor;

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
	void ReloadResource();
};
