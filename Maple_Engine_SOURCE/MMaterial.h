#pragma once
#include "MResource.h"
#include "MTexture.h"
#include "MShader.h"



namespace maple
{
	class Material : public Resource{
	public:

		struct Data {
			std::wstring albedo; //difuuse
		};

		Material();
		virtual ~Material();

		virtual HRESULT Save(const std::wstring& path) override;
		virtual HRESULT Load(const std::wstring& path) override;

		void Bind();

		void SetShader(graphics::Shader* shader) { mShader = shader; }

	private:
		graphics::eRenderingMode mMode;
		Material::Data mData;

		//Texture* mTexture;
		graphics::Shader* mShader;
	};
}

