#pragma once
#include "..\\Maple_Engine_SOURCE\\MSceneManager.h"

#include "MPlayScene.h"
#include "MTitleScene.h"

//#ifdef _DEBUG
//#pragma comment(lib, "..\\x64\\Debug\\Maple_Engine_Windows.lib")
//#else
//#pragma comment(lib, "..\\x64\\Release\\Maple_Engine_Windows.lib")
//#endif // _DEBUG


namespace maple {

	void LoadScenes() {

		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		
		SceneManager::LoadScene(L"PlayScene");


	}
}
