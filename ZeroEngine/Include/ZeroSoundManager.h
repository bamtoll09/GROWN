#pragma once

#include <map>
#include <string>
#include <stdarg.h>
#include "SDKSound.h"

using namespace std;

#define ZeroSoundMgr ZeroSoundManager::Instance()

class ZeroSoundManager {
private:
	ZeroSoundManager();

	typedef map<string, CSound*> SOUND;
	SOUND m_Sounds;

	CSoundManager m_SndMgr;

public:
	~ZeroSoundManager();

	static ZeroSoundManager* Instance();

	void PushSound(LPWSTR filepath, char* name, ...);
	void PopSound(char* name, ...);

	void Play(char* name, ...);

	void Stop();
	void Stop(char* name, ...);

	void Reset();
	void Reset(char* name, ...);
};
