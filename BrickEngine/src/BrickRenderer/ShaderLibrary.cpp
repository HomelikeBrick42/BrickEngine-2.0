#include "brickpch.h"
#include "ShaderLibrary.h"

namespace BrickEngine {

	ShaderLibrary* ShaderLibrary::s_Instance = new ShaderLibrary();

	bool ShaderLibrary::m_Initalized = false;

	void ShaderLibrary::Init()
	{
		if (m_Initalized)
			BRICKENGINE_CORE_ERROR("Shader library allready initalized!");
		else
		{
			std::string flatColorVertexShaderSource = R"(
				#version 330 core
		
				layout(location = 0) in vec4 a_Position;
				layout(location = 1) in vec4 a_Normal;
				
				out vec3 v_Normal;
		
				uniform mat4 u_ModelMatrix;
				uniform mat4 u_ProjMatrix;
		
				void main()
				{
					v_Normal = normalize(vec3(a_Normal));
					gl_Position = u_ProjMatrix * u_ModelMatrix * a_Position;
				}
			)";

			std::string flatColorFragmentShaderSource = R"(
				#version 330 core
				
				in vec3 v_Normal;
		
				out vec4 o_Color;
				
				uniform vec3 u_LightColor;
				uniform vec3 u_LightDirection;
		
				void main()
				{
					vec4 color = vec4(1.0, 1.0, 1.0, 1.0);
					
					vec3 ambiantLight = vec3(0.3, 0.3, 0.3);
					
					vec3 u_LightDirection = normalize(u_LightDirection);
					vec3 diffuseColor = color.xyz * (max(dot(normalize(v_Normal), u_LightDirection) - 0.3, 0.0) * u_LightColor);
					
					o_Color = vec4(ambiantLight + diffuseColor, color.w);
				}
			)";

			auto defaultShader = Shader::Create(flatColorVertexShaderSource, flatColorFragmentShaderSource);
			Insert("Default", defaultShader);

			m_Initalized = true;
		}
	}

	void ShaderLibrary::InsertImpl(const std::string& name, const Ref<Shader> shader)
	{
		m_Library[name] = shader;
	}

	Ref<Shader> ShaderLibrary::GetImpl(const std::string& name)
	{
		auto& shader = m_Library[name];
		if (shader == nullptr)
			BRICKENGINE_CORE_ERROR("'{0}' shader does not exist!", name);
		return shader;
	}

}
