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
#include "MAnimator.h"
#include "..\\Maple_Engine_Windows\Contents\MCat.h"
#include "..\\Maple_Engine_Windows\Scripts\MCatScript.h"

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

			mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);

			PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();


			graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
			Animator* playerAnimator = mPlayer->AddComponent<Animator>();
			playerAnimator->CreateAnimation(L"Idle", playerTex
				, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
			playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex
				, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.005f);

			playerAnimator->PlayAnimation(L"Idle", false);

			playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);

			//playerAnimator->

			mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
			mPlayer->GetComponent<Transform>()->SetRotation(0.0f);
			mPlayer->GetComponent<Transform>()->SetScale(Vector2(3.0f, 3.0f));


			Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
			cat->AddComponent<CatScript>();

			graphics::Texture* catTexture = Resources::Find<graphics::Texture>(L"Cat");
			Animator* catAnimator = cat->AddComponent<Animator>();
			catAnimator->CreateAnimation(L"DownWalk", catTexture
				, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"RightWalk", catTexture
				, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"UpWalk", catTexture
				, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"LeftWalk", catTexture
				, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"SitDown", catTexture
				, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"Grooming", catTexture
				, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"LayDown", catTexture
				, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

			catAnimator->PlayAnimation(L"SitDown", false);

			cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
			cat->GetComponent<Transform>()->SetRotation(0.0f);
			cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
			cameraComp->SetTarget(cat);

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

