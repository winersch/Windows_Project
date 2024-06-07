#include "MTexture.h"
#include "MApplication.h"
#include "MResources.h"

// 해당 전역변수가 존재함을 알리는 키워드
extern maple::Application application;

namespace maple::graphics {





	Texture* Texture::Create(const std::wstring& name, UINT width, UINT height) {
		Texture* image = Resources::Find<Texture>(name);
		
		if (image != nullptr) {
			return image;
		}

		image = new Texture();
		image->SetName(name);
		image->SetWidth(width);
		image->SetHeight(height);

		HDC hdc = application.GetHdc();
		HWND hwnd = application.GetHwnd();


		image->mBitmap = CreateCompatibleBitmap(hdc, width, height);
		image->mHdc = CreateCompatibleDC(hdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
		DeleteObject(oldBitmap);

		Resources::Insert(name, image);

		return image;
	}

	Texture::Texture()
		: Resource(enums::eResourceType::Texture)
		, mbAlpha(false)
		
	{

	}

	Texture::~Texture() {
	}

	HRESULT Texture::Load(const std::wstring& path) {

		//bmp 
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);

		if (ext == L"bmp") {
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (mBitmap == nullptr) {
				return S_FALSE;
			}

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;
			if (info.bmBitsPixel == 32) {
				mbAlpha = true;
			} else {
				mbAlpha = false;
			}

			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);
			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(oldBitmap);
		}

		//png

		if (ext == L"png") {
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());
			if (mImage == nullptr) {
				return S_FALSE;
			}

			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}


		return S_OK;
	}

}