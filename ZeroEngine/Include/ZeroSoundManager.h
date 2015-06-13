#pragma once
#include "SDKSound.h"
#include <map>
#include <string>
#include <stdarg.h>
using namespace std;

#define ZeroSoundMgr ZeroSoundManager::Instance()

class ZeroSoundManager{
private:
	typedef map<string,CSound*> SOUND;
	SOUND m_Sounds;

	CSoundManager m_SndMgr;
	ZeroSoundManager();
public:
	
	~ZeroSoundManager();

	static ZeroSoundManager* Instance();

	void PushSound(LPWSTR filepath,char* name, ...);
	void PopSound(char* name, ...);

	void Play(char* name, ...);

	void Stop();
	void Stop(char* name, ...);

	void Reset();
	void Reset(char* name, ...);
};