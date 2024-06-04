#include "MPlayerScript.h"
#include "MComponent.h"
#include "MTime.h"
#include "MTransform.h"
#include "MInput.h"
#include "MGameObject.h"

namespace maple {

	PlayerScript::PlayerScript()
		:mState(eState::SitDown)
		, mAnimator(nullptr){
	}

	PlayerScript::~PlayerScript() {
	}

	void PlayerScript::Initialize() {
		
	}

	void PlayerScript::Update() {
		if (mAnimator == nullptr) {
			mAnimator = GetOwner()->GetComponent<Animator>();
		}
		switch (mState) {
			case PlayerScript::eState::SitDown:
				SitDown();
				break;
			case PlayerScript::eState::Walk:
				Move();
				break;
			case PlayerScript::eState::Sleep:
				break;
			case PlayerScript::eState::Attack:
				break;
			default:
				break;
		}


		
	}

	void PlayerScript::LateUpdate() {
	}

	void PlayerScript::Render(HDC hdc) {
	}

	void PlayerScript::SitDown() {

		if (Input::GetKey(eKeyCode::Right)) {
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk");
		}
		if (Input::GetKey(eKeyCode::Left)) {
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"LeftWalk");
		}
		if (Input::GetKey(eKeyCode::Up)) {
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"UpWalk");
		}
		if (Input::GetKey(eKeyCode::Down)) {
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"DownWalk");
		}
	}

	void PlayerScript::Move() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right)) {
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Left)) {
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up)) {
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down)) {
			pos.y += 100.0f * Time::DeltaTime();
		}
		tr->SetPosition(pos);
		if (Input::GetKeyUp(eKeyCode::Right) || Input::GetKeyUp(eKeyCode::Left) || Input::GetKeyUp(eKeyCode::Up) || Input::GetKeyUp(eKeyCode::Down)) {
			mState = PlayerScript::eState::SitDown;
			mAnimator->PlayAnimation(L"SitDown",false);
		}
	}

	void PlayerScript::Sleep() {
	}

	void PlayerScript::Attack() {
	}


}