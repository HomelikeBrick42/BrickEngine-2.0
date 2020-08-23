#include "brickpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace BrickEngine {

	Ref<VertexArray> VertexArray::Create(const Ref<VertexBuffer> vb, const Ref<IndexBuffer> ib, VertexBufferLayout& layout)
	{
		return CreateRef<OpenGLVertexArray>(vb, ib, layout);
	}

	OpenGLVertexArray::OpenGLVertexArray(const Ref<VertexBuffer> vb, const Ref<IndexBuffer> ib, VertexBufferLayout& layout)
	{
		m_VertexBuffer = vb;
		m_IndexBuffer = ib;

		glGenVertexArrays(1, &m_RendererID);
		Bind();

		auto& elements = layout.GetElements();
		uint32_t offset = 0;
		for (uint32_t i = 0; i < elements.size(); i++)
		{
			auto& element = elements.at(i);
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, element.count, element.type, GL_FALSE, layout.GetStride(), (const void*)offset);
			offset += element.size;
		}
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
		m_VertexBuffer->Bind();
		m_IndexBuffer->Bind();
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	Ref<VertexBuffer> OpenGLVertexArray::GetVertexBuffer() const
	{
		return m_VertexBuffer;
	}

	Ref<IndexBuffer> OpenGLVertexArray::GetIndexBuffer() const
	{
		return m_IndexBuffer;
	}

	void VertexBufferLayout::AddElement(Type type, int count)
	{
		switch (type)
		{
			case BrickEngine::VertexBufferLayout::Type::NONE:
			{
				BRICKENGINE_ASSERT(false, "Invalid Type");
			} break;

			case BrickEngine::VertexBufferLayout::Type::FLOAT:
			{
				VertexBufferElement element(GL_FLOAT, count * sizeof(float), count);
				m_Elements.push_back(element);
				m_Stride += count * sizeof(float);
			} break;

			case BrickEngine::VertexBufferLayout::Type::DOUBLE:
			{
				VertexBufferElement element(GL_DOUBLE, count * sizeof(double), count);
				m_Elements.push_back(element);
				m_Stride += count * sizeof(double);
			} break;
		}
	}

}
