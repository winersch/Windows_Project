#include "MSpriteRenderer.h"
#include "MGameObject.h"
#include "MTransform.h"
#include "MTexture.h"
#include "MRenderer.h"
#include "MCamera.h"

namespace maple {
	using namespace math;
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(Vector2::One){
	}

	SpriteRenderer::~SpriteRenderer() {
	}

	void SpriteRenderer::Initialize() {
	}

	void SpriteRenderer::Update() {
	}

	void SpriteRenderer::LateUpdate() {
	}

	void SpriteRenderer::Render(HDC hdc) {
		/*
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));*/

		if (mTexture == nullptr) { // 텍스처 세팅
			assert(false);
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos = renderer::mainCamera->CalculatePosition(pos);
		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp) {


			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y
				, mTexture->GetHdc(), 0, 0
				, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
		}

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png) {
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage(), Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
		}

	}



}