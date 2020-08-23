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
		Entity FindEntityByTag(const std::string& tag);

		void OnUpdate(float delta);
		void DrawScene();
	private:
		entt::registry m_Registry;

		friend class Entity;
	};

}
