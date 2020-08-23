#pragma once

#include "brickpch.h"
#include "BrickCore/Core.h"
#include "VertexArray.h"

namespace BrickEngine {

	class MeshLibrary
	{
	public:
		static void Insert(const std::string& name, const Ref<VertexArray> shader) { s_Instance->InsertImpl(name, shader); }
		static Ref<VertexArray> Get(const std::string& name) { return s_Instance->GetImpl(name); }
		static void Init();
	private:
		void InsertImpl(const std::string& name, const Ref<VertexArray> shader);
		Ref<VertexArray> GetImpl(const std::string& name);
	private:
		static MeshLibrary* s_Instance;
		static bool m_Initalized;
		std::unordered_map<std::string, Ref<VertexArray>> m_Library;
	};

}
