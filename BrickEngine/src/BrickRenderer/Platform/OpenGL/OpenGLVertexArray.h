#pragma once

#include "BrickRenderer/VertexArray.h"

namespace BrickEngine {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray(const Ref<VertexBuffer> vb, const Ref<IndexBuffer> ib, VertexBufferLayout& layout);
		~OpenGLVertexArray();

		virtual void Bind() const;
		virtual void Unbind() const;

		virtual Ref<VertexBuffer> GetVertexBuffer() const;
		virtual Ref<IndexBuffer> GetIndexBuffer() const;
	};

}
