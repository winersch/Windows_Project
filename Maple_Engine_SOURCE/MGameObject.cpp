#pragma once 
#include "MGameObject.h"
#include "CommonInclude.h"
#include "MInput.h"
#include "MTime.h"

namespace maple {
	
	
	GameObject::GameObject() {

	}

	GameObject::~GameObject() {
	}

	
	void GameObject::Initialize() {
		for (Component* comp : mComponents) {
			comp->Initialize();
		}
	}

	void GameObject::Update() {
		for (Component* comp : mComponents) {
			comp->Update();
		}
	}
	
	void GameObject::LateUpdate() {
		for (Component* comp : mComponents) {
			comp->LateUpdate();
		}
	}
	void GameObject::Render(HDC hdc) {
		for (Component* comp : mComponents) {
			comp->Render(hdc);
		}
	}
}

