#include "stdafx.h"
#include "BlankSceneExit.h"

BlankSceneExit::BlankSceneExit(float delay)
:delay(delay){}

BlankSceneExit::~BlankSceneExit(){}

void BlankSceneExit::Update(float eTime){
	ZeroIScene::Update(eTime);
	delay -= eTime;

	if (delay <= 0){
		exit(0);
	}
}

void BlankSceneExit::Render(){
	ZeroIScene::Render();
	ZeroApp->GetDevice()->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255, 0, 0, 0), 1.0f, 0);
}