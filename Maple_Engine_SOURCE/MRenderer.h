#pragma once
#include "MCamera.h"
#include "MGraphicDevice_DX11.h"

#include "MConstantBuffer.h"


using namespace maple::math;
using namespace maple::graphics;

namespace maple::renderer {

	extern Camera* mainCamera;

	extern graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End];

	void Initialize();
	void Release();

}
