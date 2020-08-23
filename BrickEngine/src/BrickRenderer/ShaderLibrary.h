#pragma once

#include "Shader.h"
#include "BrickCore/Core.h"
#include "brickpch.h"

namespace BrickEngine {

	class ShaderLibrary
	{
	public:
		static void Insert(const std::string& name, const Ref<Shader> shader) { s_Instance->InsertImpl(name, shader); }
		static Ref<Shader> Get(const std::string& name) { return s_Instance->GetImpl(name); }
		static void Init();
	private:
		void InsertImpl(const std::string& name, const Ref<Shader> shader);
		Ref<Shader> GetImpl(const std::string& name);
	private:
		static ShaderLibrary* s_Instance;
		static bool m_Initalized;
		std::unordered_map<std::string, Ref<Shader>> m_Library;
	};

}
