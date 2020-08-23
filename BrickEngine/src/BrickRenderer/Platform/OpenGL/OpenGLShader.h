#pragma once

#include "BrickRenderer/Shader.h"

namespace BrickEngine {

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexShader, const std::string& fragmentShader);
		~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void SetUniformVec3(const std::string& name, const glm::vec3& value) override;
		virtual void SetUniformVec4(const std::string& name, const glm::vec4& value) override;
		virtual void SetUniformMat4(const std::string& name, const glm::mat4& value) override;
	private:
		int GetUniformLocation(const std::string& name);
		uint32_t CompileShader(uint32_t type, const std::string& source);
	};

}
