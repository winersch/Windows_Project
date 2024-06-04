#include "MCatScript.h"
#include "MComponent.h"
#include "MTime.h"
#include "MTransform.h"
#include "MInput.h"
#include "MGameObject.h"
#include <time.h>

namespace maple {

	CatScript::CatScript()
		:mState(eState::SitDown)
		,mDirection(eDirection::End)
		, mAnimator(nullptr)
		, mTime(0.0f){
	}

	CatScript::~CatScript() {
	}

	void CatScript::Initialize() {

	}

	void CatScript::Update() {
		if (mAnimator == nullptr) {
			mAnimator = GetOwner()->GetComponent<Animator>();
		}
		switch (mState) {
			case CatScript::eState::SitDown:
				sitDown();
				break;
			case CatScript::eState::Walk:
				move();
				break;
			case CatScript::eState::LayDown:
				layDown();
				break;
			case CatScript::eState::Sleep:
				break;
			case CatScript::eState::Attack:
				break;
			default:
				break;
		}



	}

	void CatScript::LateUpdate() {
	}

	void CatScript::Render(HDC hdc) {
	}


	void CatScript::sitDown() {

		mTime += Time::DeltaTime();
		if (mTime > 2.0f) {
			mTime = 0.0f;
			mState = CatScript::eState::Walk;
			int direction = rand() % 4;
			mDirection = (eDirection)direction;
			playWalkAnimationByDirection(mDirection);
		}
	}

	void CatScript::move() {
		mTime += Time::DeltaTime();
		if (mTime > 1.0f) {
			mTime = 0.0f;
			if (rand() % 2 == 0) {
				mDirection = eDirection::End;
				mState = eState::SitDown;
				mAnimator->PlayAnimation(L"SitDown", false);
				return;
			} else {
				mDirection = eDirection::End;
				mState = eState::LayDown;
				mAnimator->PlayAnimation(L"LayDown", false);
				return;
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		translate(tr);
		
	}

	void CatScript::layDown() {
		mTime += Time::DeltaTime();
		if (mTime > 1.0f) {
			mTime = 0;
			if (rand() % 2 == 0) {
				mDirection = (eDirection)(rand() % 4);
				mState = eState::Walk;
				playWalkAnimationByDirection(mDirection);
			} else {
				mState = eState::SitDown;
				mAnimator->PlayAnimation(L"SitDown", false);
				
			}
		}

	}

	void CatScript::playWalkAnimationByDirection(eDirection dir) {
		switch (dir) {
			case CatScript::eDirection::Left:
				mAnimator->PlayAnimation(L"LeftWalk");
				break;
			case CatScript::eDirection::Right:
				mAnimator->PlayAnimation(L"RightWalk");
				break;
			case CatScript::eDirection::Up:
				mAnimator->PlayAnimation(L"UpWalk");
				break;
			case CatScript::eDirection::Down:
				mAnimator->PlayAnimation(L"DownWalk");
				break;
			case CatScript::eDirection::End:
			default:
				assert(false);
				break;
		}
		
	}

	void CatScript::translate(Transform* tr) {
		Vector2 pos = tr->GetPosition();
		switch (mDirection) {
			case maple::CatScript::eDirection::Left:
				pos.x -= 100.0f * Time::DeltaTime();
				break;
			case maple::CatScript::eDirection::Right:
				pos.x += 100.0f * Time::DeltaTime();
				break;
			case maple::CatScript::eDirection::Up:
				pos.y -= 100.0f * Time::DeltaTime();
				break;
			case maple::CatScript::eDirection::Down:
				pos.y += 100.0f * Time::DeltaTime();
				break;
			default:
				assert(false);
				break;
		}
		tr->SetPosition(pos);

	}



}