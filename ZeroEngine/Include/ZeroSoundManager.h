#pragma once

#include <Windows.h>
#include "fmod.hpp"
#include <map>
#include <list>
#include <tuple>
#include <stdarg.h>

#define ZeroSoundMgr ZeroSoundManager::Instance()

class ZeroSoundManager {
private:
	ZeroSoundManager();
	
	FMOD::System *system;
	std::map<std::string, std::tuple<FMOD::Sound*, std::list<FMOD::Channel*>, int>> soundList;
	FMOD_RESULT result;

public:
	~ZeroSoundManager();

	static ZeroSoundManager* Instance();

	void Update(float _eTime);

	void PushSound(char* filepath, char* name, ...);
	void PopSound(char* name, ...);

	void SetConcurrency(int _concurrency, char* _name, ...);

	void Play(const char* name, ...);

	void Stop();
	void Stop(char* name, ...);

	void Reset();
	void Reset(char* name, ...);
};
