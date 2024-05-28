#pragma once
#include "MEntity.h"
#include "MGameObject.h"
#include "MLayer.h"

namespace maple {


	class Scene : public Entity {
		
	public:
		Scene();
		~Scene();
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		
		void AddGameObject(GameObject* gameObject, const enums::eLayerType type);
		Layer* GetLayer(const enums::eLayerType type) { return mLayers[(UINT)type]; }

	private:
		std::vector<Layer*> mLayers;

	};

}


