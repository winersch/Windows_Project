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
#include "MBoxCollider2D.h"
#include "MCollisionManager.h"
#include "..\\Maple_Engine_Windows\\Contents\\MTile.h"
#include "MTilemapRenderer.h"

namespace maple {

	PlayScene::PlayScene()
		:mPlayer()
	
	{

	}

	PlayScene::~PlayScene() {
	}

	void PlayScene::Initialize() {

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, L"..\\Resources\\Home", L"rb");

		while (true) {
			int idxX = 0;
			int idxY = 0;

			int posX = 0;
			int posY = 0;


			if (fread(&idxX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&idxY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;

			Tile* tile = object::Instantiate<Tile>(eLayerType::Tile, Vector2(posX, posY));
			TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
			tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
			tmr->SetIndex(Vector2(idxX, idxY));

			//mTiles.push_back(tile);
		}

		fclose(pFile);

		{
			CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);

			// main camera
			GameObject* camera =object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 440.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			renderer::mainCamera = cameraComp;

			mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
			//object::DontDestroyOnLoad(mPlayer)

			PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();

			//BoxCollider2D* collider = mPlayer->AddComponent<BoxCollider2D>();
			CircleCollider2D* collider = mPlayer->AddComponent<CircleCollider2D>();
			collider->SetOffset(Vector2(-50.0f, -50.0f));


			graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
			Animator* playerAnimator = mPlayer->AddComponent<Animator>();
			playerAnimator->CreateAnimation(L"Idle", playerTex
				, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
			playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex
				, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.005f);

			playerAnimator->PlayAnimation(L"Idle", false);

			playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);

			//playerAnimator->

			mPlayer->GetComponent<Transform>()->SetPosition(Vector2(300.0f, 250.0f));
			//mPlayer->GetComponent<Transform>()->SetRotation(0.0f);
			//mPlayer->GetComponent<Transform>()->SetScale(Vector2(3.0f, 3.0f));


			///CAT
			Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
			//cat->SetActive(true);
			cat->AddComponent<CatScript>();
			//cameraComp->SetTarget(cat);
			graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
			Animator* catAnimator = cat->AddComponent<Animator>();


			CircleCollider2D* boxCatCollider = cat->AddComponent<CircleCollider2D>();

			//BoxCollider2D* boxCatCollider = cat->AddComponent<BoxCollider2D>();

			boxCatCollider->SetOffset(Vector2(-50.0f, -50.0f));

			//catAnimator->CreateAnimation(L"DownWalk", catTex
			//	, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			//catAnimator->CreateAnimation(L"RightWalk", catTex
			//	, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			//catAnimator->CreateAnimation(L"UpWalk", catTex
			//	, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			//catAnimator->CreateAnimation(L"LeftWalk", catTex
			//	, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			//catAnimator->CreateAnimation(L"SitDown", catTex
			//	, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			//catAnimator->CreateAnimation(L"Grooming", catTex
			//	, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			//catAnimator->CreateAnimation(L"LayDown", catTex
			//	, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

			//catAnimator->PlayAnimation(L"SitDown", false);
			catAnimator->CreateAnimationByFolder(L"MushroomIdle", L"..\\Resources\\Mushroom", Vector2::Zero, 0.1f);

			catAnimator->PlayAnimation(L"MushroomIdle", true);

			cat->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
			cat->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));

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

