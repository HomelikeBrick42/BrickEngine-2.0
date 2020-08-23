#pragma once

#include "brickpch.h"

#include "BrickCore/Core.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace BrickEngine {

	struct VertexBufferElement
	{
		int type;
		int size;
		int count;

		VertexBufferElement(uint32_t type, int size, int count)
			: type(type), size(size), count(count) {}
	};

	class VertexBufferLayout
	{
	public:
		VertexBufferLayout()
			: m_Stride(0) {}
		enum class Type
		{
			NONE = 0,
			FLOAT,
			DOUBLE
		};
		void AddElement(Type type, int count);
		
		inline std::vector<VertexBufferElement> GetElements() { return m_Elements; }
		inline uint32_t GetStride() { return m_Stride; }
	private:
		std::vector<VertexBufferElement> m_Elements;
		uint32_t m_Stride;
	};

	class VertexArray
	{
	public:
		virtual ~VertexArray() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		inline Ref<VertexBuffer> GetVertexBuffer() { return m_VertexBuffer; }
		inline Ref<IndexBuffer> GetIndexBuffer() { return m_IndexBuffer; }

		static Ref<VertexArray> Create(const Ref<VertexBuffer> vb, const Ref<IndexBuffer> ib, VertexBufferLayout& layout);
	protected:
		VertexArray() {}
		uint32_t m_RendererID;
		Ref<VertexBuffer> m_VertexBuffer;
		Ref<IndexBuffer> m_IndexBuffer;
	};

}
