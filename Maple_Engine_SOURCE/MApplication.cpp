#pragma once
#include "MApplication.h"
#include "MInput.h"
#include "MTime.h"

namespace maple {
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mPlayer()
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(nullptr)
		, mBackBitmap(nullptr)
	{

	}
	Application::~Application() {
	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height) {
		this->mHwnd = hwnd;
		this->mHdc = GetDC(hwnd);
		this->mWidth = width;
		this->mHeight = height;

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
		
		SetWindowPos(mHwnd, nullptr, 30, 30, rect.right - rect.left, rect.bottom - rect.top, 0);
		ShowWindow(mHwnd, true);

		// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// 백버퍼를 가리킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		mPlayer.SetPosition(0, 0);

		Input::Initailize();
		Time::Initialize();
	}
	void Application::Run() {
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update() {
		Input::Update();
		mPlayer.Update();
		Time::Update();
	}
	void Application::LateUpdate() {

	}

	void Application::Render() {
		Rectangle(mBackHdc, -10, -10, 1600, 900);

		mPlayer.Render(mBackHdc);
		Time::Render(mBackHdc);

		// BackBuffer에 있는거 원본 Buffer에 복사
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}


}

