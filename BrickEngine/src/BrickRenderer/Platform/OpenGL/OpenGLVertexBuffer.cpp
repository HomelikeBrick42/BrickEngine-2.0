#include "brickpch.h"
#include "OpenGLVertexBuffer.h"

#include <glad/glad.h>

namespace BrickEngine {

	Ref<VertexBuffer> VertexBuffer::Create(const void* data, uint32_t size)
	{
		return CreateRef<OpenGLVertexBuffer>(data, size);
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(const void* data, uint32_t size)
	{
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

}
