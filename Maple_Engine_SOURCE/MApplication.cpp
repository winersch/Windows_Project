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

		// ������ �ػ󵵿� �´� �����(��ȭ��) ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// ����۸� ����ų DC����
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

		// BackBuffer�� �ִ°� ���� Buffer�� ����
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}


}

