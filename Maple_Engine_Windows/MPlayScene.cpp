#include "MPlayScene.h"
#include "MGameObject.h"
#include "MPlayer.h"
#include "MTransform.h"
#include "MSpriteRenderer.h"

namespace maple {

	PlayScene::PlayScene() {

	}

	PlayScene::~PlayScene() {
	}

	void PlayScene::Initialize() {
		Scene::Initialize();

		{
			Player* pl = new Player();
			Transform* tr = pl->AddComponent<Transform>();
			tr->SetPos(800, 450);

			tr->SetName(L"TR");

			SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);

		}
		{
			Player* pl = new Player();
			Transform* tr
				= pl->AddComponent<Transform>();
			tr->SetPos(300, 450);

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);
		}

		{
			Player* pl = new Player();
			Transform* tr
				= pl->AddComponent<Transform>();
			tr->SetPos(100, 650);

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);
		}
	}

	void PlayScene::Update() {
		Scene::Update();
	}

	void PlayScene::LateUpdate() {
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc) {
		Scene::Render(hdc);
	}

}

