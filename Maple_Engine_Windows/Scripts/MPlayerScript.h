#pragma once
#include "..\\Maple_Engine_SOURCE\\MScript.h"
#include "MAnimator.h"

namespace maple {

	class PlayerScript : public Script{

	public:
		enum class eState {
			SitDown,
			Walk,
			Sleep,
			Attack
		};


		PlayerScript();
		~PlayerScript();


		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SitDown();
		void Move();
		void Sleep();
		void Attack();
	private:
		eState mState;
		Animator* mAnimator;
	};

}

