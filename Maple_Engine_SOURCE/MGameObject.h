#pragma once
#include "CommonInclude.h"

namespace maple {

	
	class GameObject {
	public:
		GameObject();
		~GameObject();

		void SetPosition(float x, float y);
		float GetPositionX();
		float GetPositionY();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);


	private:
		float mX;
		float mY;


	};

}

