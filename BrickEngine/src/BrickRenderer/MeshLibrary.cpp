#include "brickpch.h"
#include "MeshLibrary.h"

namespace BrickEngine {

	MeshLibrary* MeshLibrary::s_Instance = new MeshLibrary();

	bool MeshLibrary::m_Initalized = false;

	void MeshLibrary::Init()
	{
		if (m_Initalized)
			BRICKENGINE_CORE_ERROR("Shader library allready initalized!");
		else
		{
			VertexBufferLayout layout;
			layout.AddElement(VertexBufferLayout::Type::FLOAT, 3);
			layout.AddElement(VertexBufferLayout::Type::FLOAT, 3);

			const float sharpCubeVertices[24 * 6] = {
				// Front
				-0.5, -0.5, 0.5, 0.0, 0.0,  1.0,
				-0.5,  0.5, 0.5, 0.0, 0.0,  1.0,
				 0.5,  0.5, 0.5, 0.0, 0.0,  1.0,
				 0.5, -0.5, 0.5, 0.0, 0.0,  1.0,
				// Back
				-0.5, -0.5, -0.5, 0.0, 0.0, -1.0,
				-0.5,  0.5, -0.5, 0.0, 0.0, -1.0,
				 0.5,  0.5, -0.5, 0.0, 0.0, -1.0,
				 0.5, -0.5, -0.5, 0.0, 0.0, -1.0,
				// Left
				 0.5, -0.5, -0.5,  1.0, 0.0, 0.0,
				 0.5, -0.5,  0.5,  1.0, 0.0, 0.0,
				 0.5,  0.5,  0.5,  1.0, 0.0, 0.0,
				 0.5,  0.5, -0.5,  1.0, 0.0, 0.0,
				// Right
				-0.5, -0.5, -0.5, -1.0, 0.0, 0.0,
				-0.5, -0.5,  0.5, -1.0, 0.0, 0.0,
				-0.5,  0.5,  0.5, -1.0, 0.0, 0.0,
				-0.5,  0.5, -0.5, -1.0, 0.0, 0.0,
				// Top
				-0.5,  0.5, -0.5, 0.0,  1.0, 0.0,
				-0.5,  0.5,  0.5, 0.0,  1.0, 0.0,
				 0.5,  0.5,  0.5, 0.0,  1.0, 0.0,
				 0.5,  0.5, -0.5, 0.0,  1.0, 0.0,
				// Bottom
				-0.5, -0.5, -0.5, 0.0, -1.0, 0.0,
				-0.5, -0.5,  0.5, 0.0, -1.0, 0.0,
				 0.5, -0.5,  0.5, 0.0, -1.0, 0.0,
				 0.5, -0.5, -0.5, 0.0, -1.0, 0.0,
			};
			const uint32_t sharpCubeIndices[6 * 6] = {
				0,  1,  2,  0,  2,  3,  // Front
				6,  5,  4,  7,  6,  4,  // Back
				8,  9,  10, 8,  10, 11, // Left
				14, 13, 12, 15, 14, 12, // Right
				18, 17, 16, 19, 18, 16, // Top
				20, 21, 22, 20, 22, 23, // Bottom
			};

			Ref<VertexBuffer> sharpCubeVertexBuffer = VertexBuffer::Create(sharpCubeVertices, sizeof(sharpCubeVertices));
			Ref<IndexBuffer> sharpCubeIndexBuffer = IndexBuffer::Create(sharpCubeIndices, sizeof(sharpCubeIndices));
			Ref<VertexArray> sharpCubeVertexArray = VertexArray::Create(sharpCubeVertexBuffer, sharpCubeIndexBuffer, layout);

			Insert("SharpEdgeCube", sharpCubeVertexArray);

			m_Initalized = true;
		}
	}

	void MeshLibrary::InsertImpl(const std::string& name, const Ref<VertexArray> vertexArray)
	{
		m_Library[name] = vertexArray;
	}

	Ref<VertexArray> MeshLibrary::GetImpl(const std::string& name)
	{
		auto& vertexArray = m_Library[name];
		if (vertexArray == nullptr)
			BRICKENGINE_CORE_ERROR("'{0}' vertexArray does not exist!", name);
		return vertexArray;
	}

}
