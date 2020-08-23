#include "brickpch.h"
#include "OpenGLShader.h"

#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>

namespace BrickEngine {

	Ref<Shader> Shader::Create(const std::string& vertexShader, const std::string& fragmentShader)
	{
		return CreateRef<OpenGLShader>(vertexShader, fragmentShader);
	}

	OpenGLShader::OpenGLShader(const std::string& vertexShader, const std::string& fragmentShader)
	{
		m_RendererID = glCreateProgram();
		uint32_t vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
		uint32_t fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

		glAttachShader(m_RendererID, vs);
		glAttachShader(m_RendererID, fs);
		glLinkProgram(m_RendererID);
		glValidateProgram(m_RendererID);

		glDeleteShader(vs);
		glDeleteShader(fs);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}

	void OpenGLShader::SetUniformVec3(const std::string& name, const glm::vec3& value)
	{
		Bind();
		glUniform3f(GetUniformLocation(name), value.x, value.y, value.z);
	}

	void OpenGLShader::SetUniformVec4(const std::string& name, const glm::vec4& value)
	{
		Bind();
		glUniform4f(GetUniformLocation(name), value.x, value.y, value.z, value.w);
	}

	void OpenGLShader::SetUniformMat4(const std::string& name, const glm::mat4& value)
	{
		Bind();
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
	}

	int OpenGLShader::GetUniformLocation(const std::string& name)
	{
		int location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_CORE_WARN("Uniform {0} not found!", name);
		return location;
	}

	uint32_t OpenGLShader::CompileShader(uint32_t type, const std::string& source)
	{
		uint32_t id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)alloca(length * sizeof(char));
			glGetShaderInfoLog(id, length, &length, message);
			BRICKENGINE_CORE_ERROR("Failed to compile {0} shader!\n{1}", type == GL_VERTEX_SHADER ? "vertex" : "fragment", message);
			glDeleteShader(id);
			return 0;
		}

		return id;
	}

}
