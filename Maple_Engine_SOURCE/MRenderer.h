#pragma once
#include "MCamera.h"
#include "MGraphicDevice_DX11.h"

#include "MVertexBuffer.h"

namespace maple::renderer {

	extern Camera* mainCamera;
	extern std::vector<graphics::Vertex> vertexes;

	

	extern std::vector<UINT> indices;

	extern graphics::VertexBuffer vertexBuffer;
	extern ID3D11Buffer* indexBuffer;
	extern ID3D11Buffer* constantBuffer;

	extern ID3D11InputLayout* inputLayouts;


	void Initialize();
	void Release();

}
