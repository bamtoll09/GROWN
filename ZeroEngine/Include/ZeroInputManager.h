#pragma once

#include <d3d9.h>
#include "ZeroVec.h"
#include "ZeroRect.h"

#define ZeroInputMgr ZeroInputManager::Instance()

enum {
	INPUTMGR_KEYNONE,
	INPUTMGR_KEYON,
	INPUTMGR_KEYDOWN,
	INPUTMGR_KEYUP,

	INPUTMGR_WHEELNONE,
	INPUTMGR_WHEELDOWN,
	INPUTMGR_WHEELUP,
};

class ZeroInputManager {
private:
	ZeroInputManager();

	bool m_bPreviousKey[256];
	bool m_bCurrentKey[256];
	bool m_bLockKey[256];

	int m_iWheel;

public:
	~ZeroInputManager();

	static ZeroInputManager* Instance();

	void KeyState();
	int GetKey(int key);
	void LockKey(int key);
	void UnlockKey(int key);

	ZeroVec GetClientPoint();
	ZeroVec GetScreenPoint();
	ZeroRect GetClientRect();
	ZeroRect GetScreenRect();

	int GetWheel();
	void WheelState(WPARAM wParam);
};