#pragma once

#include "brickpch.h"

#include "BrickCore/Core.h"

#include <glm/glm.hpp>

namespace BrickEngine {

	class Shader
	{
	public:
		virtual ~Shader() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetUniformVec3(const std::string& name, const glm::vec3& value) = 0;
		virtual void SetUniformVec4(const std::string& name, const glm::vec4& value) = 0;
		virtual void SetUniformMat4(const std::string& name, const glm::mat4& value) = 0;

		static Ref<Shader> Create(const std::string& vertexShader, const std::string& fragmentShader);
	protected:
		Shader() {}
		uint32_t m_RendererID;
	};

}
