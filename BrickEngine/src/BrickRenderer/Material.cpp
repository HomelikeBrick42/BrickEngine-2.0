#include "brickpch.h"
#include "Material.h"

namespace BrickEngine {

	Material::Material(const Ref<Shader> shader, const glm::vec4& color)
		: m_Shader(shader), m_Color(color)
	{
	}

	void Material::Bind() const
	{
		m_Shader->Bind();
		m_Shader->SetUniformVec4("u_Color", m_Color);
	}

}
