#include "MLayer.h"

namespace maple {

	Layer::Layer()
		: mGameObjects{}
	{

	}

	Layer::~Layer() {
		for (auto* gameobj : mGameObjects) {
			if (gameobj == nullptr) {
				continue;
			}

			delete gameobj;
			gameobj = nullptr;
		}
	}

	void Layer::Initialize() {
		for (GameObject* gameobj : mGameObjects) {
			if (gameobj == nullptr) {
				continue;
			}
			gameobj->Initialize();
		}

	}

	void Layer::Update() {
		for (GameObject* gameobj : mGameObjects) {
			if (gameobj == nullptr) {
				continue;
			}
			GameObject::eState state = gameobj->GetActive();
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead) {
				continue;
			}

			gameobj->Update();
		}

	}

	void Layer::LateUpdate() {
		for (GameObject* gameobj : mGameObjects) {
			if (gameobj == nullptr) {
				continue;
			}
			GameObject::eState state = gameobj->GetActive();
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead) {
				continue;
			}

			gameobj->LateUpdate();
		}
	}

	void Layer::Render(HDC hdc) {
		for (GameObject* gameobj : mGameObjects) {
			if (gameobj == nullptr) {
				continue;
			}
			GameObject::eState state = gameobj->GetActive();
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead) {
				continue;
			}

			gameobj->Render(hdc);
		}
	}

	void Layer::Destroy() {

		for (GameObjectIter iter = mGameObjects.begin(); iter != mGameObjects.end(); ) {
			GameObject::eState active = (*iter)->GetActive();
			if (active == GameObject::eState::Dead) {
				GameObject* deathObj = (*iter);
				iter = mGameObjects.erase(iter);
				delete deathObj;
				deathObj = nullptr;
			} else {
				++iter;
			}
		}
	}

	void Layer::AddGameObject(GameObject* gameobject) {
		if (gameobject == nullptr) {
			return;
		}
		mGameObjects.push_back(gameobject);
	}

}