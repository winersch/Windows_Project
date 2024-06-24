#include "MRenderer.h"
#include "MGraphicDevice_DX11.h"

#include "MResources.h"
#include "MShader.h"

namespace maple::renderer {
	Camera* mainCamera = nullptr;

	std::vector<graphics::Vertex> vertexes = {};
	std::vector<UINT> indices;

	graphics::VertexBuffer vertexBuffer;
	ID3D11Buffer* indexBuffer = nullptr;
	ID3D11Buffer* constantBuffer = nullptr;

	ID3D11InputLayout* inputLayouts = nullptr;

	void LoadTriangleMesh() {
		renderer::vertexes.resize(3);

		renderer::vertexes[0].pos = Vector3(0.f, 0.5f, 0.0f);
		renderer::vertexes[0].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		renderer::vertexes[1].pos = Vector3(0.5f, -0.5f, 0.0f);
		renderer::vertexes[1].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		renderer::vertexes[2].pos = Vector3(-0.5f, -0.5f, 0.0f);
		renderer::vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		//indices.push_back(0);
		//indices.push_back(2);
		//indices.push_back(3);

		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);
	}

	void LoadMeshes() {
		LoadTriangleMesh();
	}

	void LoadShaders() {
		maple::Resources::Load<graphics::Shader>(L"TriangleShader", L"..\\Shaders_SOURCE\\Triangle");

	}

	void Initialize() {
		LoadMeshes();
		LoadShaders();
	}

	void Release() {
		inputLayouts->Release();
		indexBuffer->Release();
		constantBuffer->Release();

	}
}