#include "brickpch.h"
#include "Scene.h"

#include <entt.hpp>

#include <glm/glm.hpp>

#include "BrickRenderer/Renderer.h"

#include "Components.h"

#include "Entity.h"

#include "BrickRenderer/MeshLibrary.h"

namespace BrickEngine {

	Scene::Scene()
	{
	}

	Scene::~Scene()
	{
	}

	Entity Scene::CreateEntity(const std::string& tag)
	{
		Entity entity = { m_Registry.create(), this };
		entity.AddComponent<TransformComponent>();
		entity.AddComponent<TagComponent>(tag.empty() ? "Entity" : tag);
		return entity;
	}

	Entity Scene::CreateCubeEntity(const std::string& tag, const glm::vec4& color)
	{
		Entity& entity = CreateEntity(tag);
		entity.AddComponent<MeshRendererComponent>(Material(ShaderLibrary::Get("Default"), color), MeshLibrary::Get("SharpEdgeCube"));
		if (color.w < 1.0)
			entity.AddComponent<TransparentComponent>();
		return entity;
	}

	Entity Scene::FindEntityByTag(const std::string& tag)
	{
		auto view = m_Registry.view<TagComponent>();
		for (auto entity : view)
		{
			if (m_Registry.get<TagComponent>(entity).Tag == tag)
			{
				return { entity, this };
			}
		}
		return { entt::null, this };
	}

	void Scene::OnUpdate(float delta)
	{

	}

	void Scene::DrawScene()
	{
		Camera* mainCamera = nullptr;
		glm::mat4* cameraTransform = nullptr;
		auto cameras = m_Registry.view<CameraComponent>();
		for (auto& entity : cameras)
		{
			auto& [transform, camera] = m_Registry.get<TransformComponent, CameraComponent>(entity);

			if (camera.Primary)
			{
				cameraTransform = &transform.Transform;
				mainCamera = &camera.Camera;
				break;
			}
		}

		if (mainCamera)
		{
			Renderer::Begin(*mainCamera, *cameraTransform);

			auto view = m_Registry.view<TransformComponent>();
			for (auto entity : view)
			{
				if (m_Registry.has<MeshRendererComponent>(entity) && !m_Registry.has<TransparentComponent>(entity))
				{
					auto& [transform, mesh] = m_Registry.get<TransformComponent, MeshRendererComponent>(entity);

					Renderer::Draw(mesh.Material, mesh.Mesh, transform.Transform);
				}
			}
			auto transparent = m_Registry.view<TransparentComponent>();
			for (auto entity : transparent)
			{
				if (m_Registry.has<MeshRendererComponent>(entity) && m_Registry.has<TransformComponent>(entity))
				{
					auto& [transform, mesh] = m_Registry.get<TransformComponent, MeshRendererComponent>(entity);

					Renderer::Draw(mesh.Material, mesh.Mesh, transform.Transform);
				}
			}

			Renderer::End();
		}
	}

}
