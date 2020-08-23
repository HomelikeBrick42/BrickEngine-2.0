#include "brickpch.h"
#include "OpenGLIndexBuffer.h"

#include <glad/glad.h>

namespace BrickEngine {

	Ref<IndexBuffer> IndexBuffer::Create(const uint32_t* data, uint32_t size)
	{
		return CreateRef<OpenGLIndexBuffer>(data, size);
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(const uint32_t* data, uint32_t size)
	{
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		m_Count = size / sizeof(uint32_t);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLIndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}
