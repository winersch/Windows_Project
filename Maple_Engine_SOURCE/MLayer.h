#pragma once
#include "MEntity.h"
#include "CommonInclude.h"
#include "MGameObject.h"

namespace maple {

	class Layer : public Entity{

	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void AddGameObject(GameObject* gameobject);

	private:
		eLayerType mType;
		std::vector<GameObject*> mGameObjects;

	};

}

