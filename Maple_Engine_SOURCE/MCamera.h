#pragma once
#include "MComponent.h"
#include "MGameObject.h"

namespace maple {
	using namespace maple::math;
	class Camera : public Component{
	public:
		Vector2 CalculatePosition(Vector2 pos) {return pos - mDistance;};
		
		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


	private:
		//std::vector<GameObject*> mGameObjects;
		class GameObject* mTarget;

		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;
		
	};


}


