#pragma once

#include "brickpch.h"

#include "BrickCore/Core.h"

namespace BrickEngine {

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		uint32_t GetCount() const { return m_Count; }

		static Ref<IndexBuffer> Create(const uint32_t* data, uint32_t size);
	protected:
		IndexBuffer() {}
		uint32_t m_RendererID;
		uint32_t m_Count;
	};

}
