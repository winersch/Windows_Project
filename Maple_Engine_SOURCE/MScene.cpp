#include "MScene.h"


namespace maple {

	Scene::Scene()
		: mLayers{} {
		mLayers.resize((UINT)enums::eLayerType::Max);
		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++) {
			mLayers[i] = new Layer();
		}
	}

	Scene::~Scene() {
		for (Layer* layer : mLayers) {
			delete layer;
			layer = nullptr;
		}
	}

	void Scene::Initialize() {
		for (Layer* layer : mLayers) {
			if (layer == nullptr) {
				continue;
			}
			layer->Initialize();
		}
	}

	void Scene::Update() {
		for (Layer* layer : mLayers) {
			if (layer == nullptr) {
				continue;
			}
			layer->Update();
		}
	}

	void Scene::LateUpdate() {
		for (Layer* layer : mLayers) {
			if (layer == nullptr) {
				continue;
			}
			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc) {
		for (Layer* layer : mLayers) {
			if (layer == nullptr) {
				continue;
			}
			layer->Render(hdc);
		}
	}

	void Scene::OnEnter() {
	}

	void Scene::OnExit() {
	}

	void Scene::AddGameObject(GameObject* gameobject, const enums::eLayerType type) {
		if (gameobject == nullptr) {
			return;
		}
		mLayers[(UINT)type]->AddGameObject(gameobject);
	}


}


