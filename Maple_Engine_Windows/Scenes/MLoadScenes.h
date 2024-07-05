#pragma once
#include "..\\Maple_Engine_SOURCE\\MSceneManager.h"

#include "MLoadingScene.h"
#include "MPlayScene.h"
#include "MTitleScene.h"
#include "MToolScene.h"



namespace maple {

	void LoadScenes() {

		SceneManager::CreateScene<LoadingScene>(L"LoadingScene");
		//SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");
		//SceneManager::LoadScene(L"PlayScene");
		//SceneManager::CreateScene<ToolScene>(L"ToolScene");

		SceneManager::LoadScene(L"LoadingScene");
	}
}
