#pragma once

#include "Shader.h"

#include "brickpch.h"

#include "glm/glm.hpp"

namespace BrickEngine {

	class Material
	{
	public:
		Material() = default;
		Material(const Ref<Shader> shader, const glm::vec4& color);

		void Bind() const;

		inline const Ref<Shader> GetShader() const { return m_Shader; }
	private:
		Ref<Shader> m_Shader;
		glm::vec4 m_Color;
	};

}
