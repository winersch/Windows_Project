#include "MSpriteRenderer.h"
#include "MGameObject.h"
#include "MTransform.h"
#include "MTexture.h"
#include "MRenderer.h"
#include "MCamera.h"

#include "MResources.h"

namespace maple {
	using namespace math;
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mSprite(nullptr)
		, mMaterial(nullptr)
		, mMesh(nullptr) {
	}

	SpriteRenderer::~SpriteRenderer() {
	}

	void SpriteRenderer::Initialize() {
		mMesh = Resources::Find<Mesh>(L"RectMesh");
	}

	void SpriteRenderer::Update() {
	}

	void SpriteRenderer::LateUpdate() {
	}

	void SpriteRenderer::Render() {
		if (mMesh)
			mMesh->Bind();

		if (mMaterial)
			mMaterial->BindShader();

		if (mSprite)
			mSprite->Bind(eShaderStage::PS, (UINT)eTextureType::Albedo);

		if (mMesh)
			graphics::GetDevice()->DrawIndexed(mMesh->GetIndexCount(), 0, 0);
	}



}