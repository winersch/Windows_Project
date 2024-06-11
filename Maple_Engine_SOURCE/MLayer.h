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
		virtual void Destroy();

		virtual void AddGameObject(GameObject* gameobject);
		const std::vector<GameObject*> GetGameObjects() { return mGameObjects; }

	private:
		void findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs);
		void deleteGameObjects(std::vector<GameObject*> gameObjs);
		void eraseGameObject();


	private:
		//enums::eLayerType mType;
		std::vector<GameObject*> mGameObjects;

	};
	typedef std::vector<GameObject*>::iterator GameObjectIter;
}

