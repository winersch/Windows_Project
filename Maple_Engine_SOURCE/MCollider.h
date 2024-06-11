#pragma once
#include "MComponent.h"

namespace maple {


	class Collider : public Component{

	public:
		Collider();
		~Collider();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		Vector2 GetOffset() { return mOffset; }
		void SetOffset(Vector2 offset) { mOffset = offset; }

	private:
		Vector2 mOffset;

	};

}


