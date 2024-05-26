#include "MSceneManager.h"


namespace maple {

	std::map<std::wstring, Scene*> SceneManager::mScene;
	Scene* SceneManager::mActiveScene = nullptr; // 정의 및 초기화


	void SceneManager::Initialize() {
	

	}


	void SceneManager::Update() {
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate() {
		mActiveScene->LateUpdate();

	}

	void SceneManager::Render(HDC hdc) {
		mActiveScene->Render(hdc);

	}


}