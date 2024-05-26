#include "MSceneManager.h"


namespace maple {

	std::map<std::wstring, Scene*> SceneManager::mScene;
	Scene* SceneManager::mActiveScene = nullptr; // ���� �� �ʱ�ȭ


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