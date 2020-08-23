#pragma once

#include "brickpch.h"

#include "BrickCore/Core.h"

namespace BrickEngine {

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static Ref<VertexBuffer> Create(const void* data, uint32_t size);
	protected:
		VertexBuffer() {}
		uint32_t m_RendererID;
	};

}
