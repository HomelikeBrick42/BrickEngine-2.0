#pragma once

#include "BrickRenderer/IndexBuffer.h"

namespace BrickEngine {

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(const uint32_t* data, uint32_t size);
		~OpenGLIndexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;
	};

}
