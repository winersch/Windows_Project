#include "MToolScene.h"
#include "MObject.h"
#include "..\\Maple_Engine_Windows\\Contents\\MTile.h"
#include "MTilemapRenderer.h"
#include "MResources.h"
#include "MTexture.h"
#include "MCamera.h"
#include "MRenderer.h"

namespace maple {

	ToolScene::ToolScene() {
	}

	ToolScene::~ToolScene() {
	}

	void ToolScene::Initialize() {
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::Particle, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		Tile* tile = object::Instantiate<Tile>(eLayerType::Tile);
		TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();


		tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));

		Scene::Initialize();
	}

	void ToolScene::Update() {
		Scene::Update();
	}

	void ToolScene::LateUpdate() {
		Scene::LateUpdate();
	}

	void ToolScene::Render(HDC hdc) {
		Scene::Render(hdc);

		for (size_t i = 0; i < 50; i++) {
			MoveToEx(hdc, (16 * 3) * i, 0, NULL);
			LineTo(hdc, (16 * 3) * i, 1000);
		}

		for (size_t i = 0; i < 50; i++) {
			MoveToEx(hdc, 0, (16 * 3) * i, NULL);
			LineTo(hdc, 1000, (16 * 3) * i);
		}
	}

	void ToolScene::OnEnter() {
		Scene::OnEnter();
	}

	void ToolScene::OnExit() {
		Scene::OnExit();
	}
}