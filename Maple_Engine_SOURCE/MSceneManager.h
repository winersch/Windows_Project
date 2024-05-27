#pragma once
#include "MScene.h"

namespace maple {

	class SceneManager {

	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& name) {
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name) {
			std::map <std::wstring, Scene*>::iterator iter
				= mScene.find(name);
			if (iter == mScene.end()) {
				return nullptr;
			}
			if (mActiveScene != nullptr) {
				mActiveScene->OnExit();
			}
			mActiveScene = iter->second;
			mActiveScene->OnEnter();
			return mActiveScene;
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);


	private:
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;


	};

}

