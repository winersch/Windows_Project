#pragma once
#include "CommonInclude.h"
#include "MComponent.h"
#include "MAnimation.h"

namespace maple {

	class Animator : public Component{

	public:

		struct Event {

			void operator = (std::function<void()> func){
				mEvent = std::move(func);
			}


			void operator()(){
				if (mEvent) {
					mEvent;
				}
			}

			std::function<void()> mEvent;

		};

		struct Events {
			Event mStartEvent;
			Event mCompleteEvent;
			Event mEndEvent;
		};

		Animator();
		~Animator();


		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void CreateAnimation(const std::wstring& name
			, graphics::Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLength
			, float duration);

		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);

		bool IsCompleted() { return mActiveAnimation->IsCompleted(); }


	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;

		std::map<std::wstring, Events*> mEvents;
	};

}

