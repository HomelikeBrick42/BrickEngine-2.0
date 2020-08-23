#pragma once

#include <entt.hpp>

#include "BrickPhysics/CollisionData.h"

namespace BrickEngine {

	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& tag = std::string());
		Entity CreateCubeEntity(const std::string& tag = std::string(), const glm::vec4& color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
		Entity FindEntityByTag(const std::string& tag);

		void OnUpdate(float delta);
		void DrawScene();
	private:
		entt::registry m_Registry;

		friend class Entity;
	};

}
