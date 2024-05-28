#pragma once
#include "MLayer.h"
#include "MGameObject.h"
#include "MScene.h"
#include "MSceneManager.h"
#include "MComponent.h"
#include "MTransform.h"

namespace maple::object {

	template <typename T>
	static T* Instantiate(enums::eLayerType type) {
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(enums::eLayerType type, math::Vector2 position) {
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}

}