#pragma once
#include "MCamera.h"
#include "MGraphicDevice_DX11.h"

#include "MMesh.h"
#include "MConstantBuffer.h"


using namespace maple::math;
using namespace maple::graphics;

namespace maple::renderer {

	extern Camera* mainCamera;
	
	extern Mesh* mesh;

	extern graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End];

	extern ID3D11Buffer* constantBuffer;
	extern ID3D11InputLayout* inputLayouts;


	void Initialize();
	void Release();

}
