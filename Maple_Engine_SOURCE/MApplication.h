#pragma once
#include "CommonInclude.h"
#include "MGameObject.h"
#include "MGraphicDevice_DX11.h"

namespace maple {
	class Application {

	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
		void Destroy();
		void Release();

		HWND GetHwnd() const { return mHwnd; }
		HDC GetHdc() const { return mHdc; }
		UINT GetWidth() const { return mWidth; }
		UINT GetHeight() const { return mHeight; }

	private:
		void clearRenderTarget();
		void copyRenterTarget(HDC cource, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void intitializeEct();



	private:
		std::unique_ptr<graphics::GraphicDevice_DX11> mGraphicDevice;

		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

	};

}


