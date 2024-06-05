#include "MAnimator.h"

namespace maple {



	Animator::Animator()
		: Component(enums::eComponentType::Animator)
		, mAnimations{}
		, mActiveAnimation(nullptr)
		, mbLoop(false)
		
	{
	}

	Animator::~Animator() {
		for (auto& iter : mEvents) {
			delete iter.second;
			iter.second = nullptr;
		}
		for (auto& iter : mAnimations) {
			delete iter.second;
			iter.second = nullptr;
		}
	}

	void Animator::Initialize() {
	}

	void Animator::Update() {
		if (mActiveAnimation) {
			mActiveAnimation->Update();

			Events* events = FindEvents(mActiveAnimation->GetName());

			if (mActiveAnimation->IsCompleted() == true) {
				if (events) {
					events->CompleteEvent();
				}
				if (mbLoop == true) {
					mActiveAnimation->Reset();
				}
			}
		}
	}

	void Animator::LateUpdate() {
	}

	void Animator::Render(HDC hdc) {
		if (mActiveAnimation) {
			mActiveAnimation->Render(hdc);
		}
	}

	void Animator::CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration) {
		Animation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr) {
			return;
		}
		animation = new Animation();
		animation->SetName(name);
		animation->CreateAnimation(name, spriteSheet, leftTop, size, offset, spriteLength, duration);
		animation->SetAnimator(this);

		Events* events = new Events();
		mEvents.insert(std::make_pair(name, events));

		mAnimations.insert(std::make_pair(name, animation));

	}

	Animation* Animator::FindAnimation(const std::wstring& name) {
		auto iter = mAnimations.find(name);
		if (iter == mAnimations.end()) {
			return nullptr;
		}

		return iter->second;
	}

	void Animator::PlayAnimation(const std::wstring& name, bool loop) {
		Animation* animation = FindAnimation(name);
		if (animation == nullptr) {
			return;
		}
		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mbLoop = loop;
		Events* currentEvents = FindEvents(mActiveAnimation->GetName());
		if (currentEvents) {
			currentEvents->EndEvent();
		}
		Events* nextEvents = FindEvents(mActiveAnimation->GetName());
		if (nextEvents) {
			nextEvents->StartEvent();
		}
	}

	Animator::Events* Animator::FindEvents(const std::wstring& name) {
		auto iter = mEvents.find(name);
		if (iter == mEvents.end()) {
			return nullptr;
		}

		return iter->second;
	}

	std::function<void()>& Animator::GetStartEvent(const std::wstring& name) {
		// TODO: ���⿡ return ���� �����մϴ�.
		Events* events = FindEvents(name);
		return events->StartEvent.mEvent;
	}

	std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name) {
		// TODO: ���⿡ return ���� �����մϴ�.
		Events* events = FindEvents(name);
		return events->CompleteEvent.mEvent;
	}

	std::function<void()>& Animator::GetEndEvent(const std::wstring& name) {
		// TODO: ���⿡ return ���� �����մϴ�.
		Events* events = FindEvents(name);
		return events->EndEvent.mEvent;
	}

}