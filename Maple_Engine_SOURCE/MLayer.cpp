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
			GameObject::eState state = gameobj->GetState();
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
			GameObject::eState state = gameobj->GetState();
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
			GameObject::eState state = gameobj->GetState();
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead) {
				continue;
			}

			gameobj->Render(hdc);
		}
	}

	void Layer::Destroy() {

		for (GameObjectIter iter = mGameObjects.begin(); iter != mGameObjects.end(); ) {
			GameObject::eState active = (*iter)->GetState();
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

	void Layer::findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs) {
		for (GameObject* gameObj : mGameObjects) {
			GameObject::eState active = gameObj->GetState();
			if (active == GameObject::eState::Dead)
				gameObjs.push_back(gameObj);
		}
	}

	void Layer::deleteGameObjects(std::vector<GameObject*> deleteObjs) {
		for (GameObject* obj : deleteObjs) {
			delete obj;
			obj = nullptr;
		}
	}

	void Layer::eraseGameObject() {
		std::erase_if(mGameObjects,
			[](GameObject* gameObj) {
				return (gameObj)->IsDead();
			});
	}

}