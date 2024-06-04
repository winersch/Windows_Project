#pragma once
#include "..\\Maple_Engine_SOURCE\\MScript.h"
#include "MAnimator.h"
#include "MTransform.h"

namespace maple {

	class CatScript : public Script {

	public:
		enum class eState {
			SitDown,
			Walk,
			Sleep,
			LayDown,
			Attack
		};

		enum class eDirection {
			Left,
			Right,
			Up,
			Down,
			End
		};


		CatScript();
		~CatScript();


		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void sitDown();
		void move();
		void layDown();
		void playWalkAnimationByDirection(eDirection dir);
		void translate(Transform* tr);

	private:
		eState mState;
		eDirection mDirection;
		Animator* mAnimator;
		float mTime;
	};

}

