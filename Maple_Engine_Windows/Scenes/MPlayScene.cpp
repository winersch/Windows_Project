#include "MPlayScene.h"
#include "MGameObject.h"
#include "MTransform.h"
#include "MSpriteRenderer.h"
#include "..\\Maple_Engine_SOURCE\\MSceneManager.h"
#include "..\\Maple_Engine_Windows\Contents\MPlayer.h"
#include "MInput.h"

namespace maple {

	PlayScene::PlayScene()
	
	{

	}

	PlayScene::~PlayScene() {
	}

	void PlayScene::Initialize() {
		Scene::Initialize();

		{
			bg = new Player();
			Transform* tr
				= bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"C:\\projects\\C\\Windows_Project\\Maple_Engine_SOURCE\\CloudOcean.png");

			AddGameObject(bg, eLayerType::BackGround);

		}
	}

	void PlayScene::Update() {
		Scene::Update();
	}

	void PlayScene::LateUpdate() {
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC hdc) {
		Scene::Render(hdc);
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter() {
	}

	void PlayScene::OnExit() {
		bg->GetComponent<Transform>()->SetPos(Vector2(0, 0));

	}

}

