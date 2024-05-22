#pragma once
#include "CommonInclude.h"
#include "MGameObject.h"

namespace maple {
	class Application {

	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();

		void Render();


	private:
		HWND mHwnd;
		HDC mHdc;

		GameObject mPlayer;
	};

}


