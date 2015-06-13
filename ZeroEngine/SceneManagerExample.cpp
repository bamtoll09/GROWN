#include "SceneManagerExample.h"
#include "FPSExample.h"

/*--------------------------------------------------------------------------------*/
//
//							생성자 부분에서 변수 초기화
//
/*--------------------------------------------------------------------------------*/
SceneManagerExample::SceneManagerExample() {
	m_pFont = new ZeroFont(20, "SceneManagerExample");
	m_pFont->SetColor(0xff000000);
	PushScene(m_pFont);
}
/*--------------------------------------------------------------------------------*/
//
//										소멸자
//
/*--------------------------------------------------------------------------------*/
SceneManagerExample::~SceneManagerExample() {
}
/*--------------------------------------------------------------------------------*/
//
//							Update 함수에서는 기능을 검사
//
/*--------------------------------------------------------------------------------*/
void SceneManagerExample::Update(float eTime) {
	ZeroIScene::Update(eTime);

	//스페이스바 키를 누르면 FPSExample로 넘어갑니다~
	//주로 메인화면에서 게임화면으로 넘어갈때 자주씀
	if (ZeroInputMgr->GetKey(VK_SPACE) == INPUTMGR_KEYDOWN) {
		ZeroSceneMgr->ChangeScene(new FPSExample());
	}
}
/*--------------------------------------------------------------------------------*/
//
//							Render함수에서는 그리기만 한다.
//
/*--------------------------------------------------------------------------------*/
void SceneManagerExample::Render() {
	ZeroIScene::Render();
	m_pFont->Render();
}