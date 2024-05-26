#include "MScene.h"

namespace maple {

	Scene::Scene()
		: mGameObjects{} {
	}

	Scene::~Scene() {
	}

	void Scene::Initialize() {
		GameObject* go = new GameObject();
		
		mGameObjects.push_back(go);
	}

	void Scene::Update() {
		for (GameObject* gameObj : mGameObjects) {
			gameObj->Update();
		}
	}

	void Scene::LateUpdate() {
		for (GameObject* gameObj : mGameObjects) {
			gameObj->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc) {
		for (GameObject* gameObj : mGameObjects) {
			gameObj->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObject) {
		mGameObjects.push_back(gameObject);
	}


}


