#include "MPlayScene.h"
#include "MGameObject.h"
#include "MTransform.h"
#include "MSpriteRenderer.h"
#include "..\\Maple_Engine_SOURCE\\MSceneManager.h"
#include "..\\Maple_Engine_Windows\Contents\MPlayer.h"
#include "MInput.h"
#include "MObject.h"
#include "MTexture.h"
#include "MResources.h"
#include "..\\Maple_Engine_Windows\\Scripts\\MPlayerScript.h"
#include "MCamera.h"
#include "MRenderer.h"
#include "iostream"

namespace maple {

	PlayScene::PlayScene()
		:mPlayer()
	
	{

	}

	PlayScene::~PlayScene() {
	}

	void PlayScene::Initialize() {

		{
			// main camera
			GameObject* camera =object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 440.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			renderer::mainCamera = cameraComp;
			//camera->AddComponent<PlayerScript>();


			mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
			SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
			sr->SetSize(Vector2(3.0f, 3.0f));
			mPlayer->AddComponent<PlayerScript>();

			graphics::Texture* pacmanTexture = Resources::Find<graphics::Texture>(L"PacMan");
			sr->SetTexture(pacmanTexture);

			GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::BackGround);
			SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
			bgsr->SetSize(Vector2(3.0f, 3.0f));

			graphics::Texture* bgTex = Resources::Find<graphics::Texture>(L"Map");
			bgsr->SetTexture(bgTex);
			

			Scene::Initialize();
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
		
		/*

		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);*/
	}

	void PlayScene::OnEnter() {
	}

	void PlayScene::OnExit() {
		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(0, 0));

	}

}

