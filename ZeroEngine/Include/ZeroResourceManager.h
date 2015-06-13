﻿#pragma once
#include <list>
class ZeroResource ;

#define ZeroResourceMgr ZeroResourceManager::GetInstance()

class ZeroResourceManager
{
private:
	ZeroResourceManager(void);
	~ZeroResourceManager(void);

	typedef std::list<ZeroResource*> ResourceList ;
	ResourceList m_ResourceList ;
public:
	static ZeroResourceManager* GetInstance() ;

	void ReloadAllResource() ;
	void OnPrevDeviceReset() ;
	void OnPostDeviceReset() ;
	void RegisterResource(ZeroResource* _iNewResource) ;
	void UnRegisterResource(ZeroResource* _iRemoveResource) ;
	void CleanUp() ;
};