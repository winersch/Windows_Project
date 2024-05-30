#pragma once
#include "..\\Maple_Engine_SOURCE\\MScript.h"

namespace maple {

	class PlayerScript : public Script{

	public:
		PlayerScript();
		~PlayerScript();


		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};

}

