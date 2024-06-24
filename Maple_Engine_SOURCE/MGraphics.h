#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include <wrl.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include "CommonInclude.h"

namespace maple::graphics
{

	struct Vertex {
		math::Vector3 pos;
		math::Vector4 color;
	};

	enum class eShaderStage {
		VS,		// Vertex Shader
		HS,		// Hull Shader
		DS,		// Domain Shader
		GS,		// Geometry Shader
		PS,		// Pixel Shader
		CS,		// Compute Shader
		All,
		End,
	};

	enum class eCBType {
		Transform,
		End,
	};

	struct GpuBuffer {
		Microsoft::WRL::ComPtr<ID3D11Buffer> buffer;
		D3D11_BUFFER_DESC desc;

		GpuBuffer() = default;
		virtual ~GpuBuffer() = default;
	};
}