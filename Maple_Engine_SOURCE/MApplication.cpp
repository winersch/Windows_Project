#include "MApplication.h"



namespace maple {
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mPlayer() {

	}
	Application::~Application() {
	}

	void Application::Initialize(HWND hwnd) {
		this->mHwnd = hwnd;
		this->mHdc = GetDC(hwnd);

	}
	void Application::Run() {
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update() {

		mPlayer.Update();
	}
	void Application::LateUpdate() {

	}

	void Application::Render() {

		mPlayer.Render(mHdc);
		
	}


}

