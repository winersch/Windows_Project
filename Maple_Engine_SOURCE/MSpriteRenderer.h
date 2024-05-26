#pragma once
#include "MEntity.h"
#include "MComponent.h"

namespace maple {

	class SpriteRenderer : public Component {
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:


	};

}


