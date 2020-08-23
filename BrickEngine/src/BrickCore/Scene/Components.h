#pragma once

#include <glm/glm.hpp>

#include "BrickRenderer/VertexArray.h"
#include "BrickRenderer/Shader.h"

#include "BrickRenderer/Camera.h"

#include "BrickPhysics/Colliders/Collider.h"

namespace BrickEngine {

	struct TagComponent
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string& tag)
			: Tag(tag) {}

		operator std::string& () { return Tag; }
		operator const std::string& () const { return Tag; }
	};

	struct TransformComponent
	{
		glm::mat4 Transform = glm::mat4(1.0f);

		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::mat4& transform)
			: Transform(transform) {}

		operator glm::mat4& () { return Transform; }
		operator const glm::mat4& () const { return Transform; }
	};

	struct MeshRendererComponent
	{
		Ref<VertexArray> Mesh;
		Ref<Shader> Material;

		MeshRendererComponent() = default;
		MeshRendererComponent(const MeshRendererComponent&) = default;
		MeshRendererComponent(const Ref<Shader> shader, const Ref<VertexArray> mesh)
			: Material(shader), Mesh(mesh) {}
	};

	struct CameraComponent
	{
		BrickEngine::Camera Camera;
		bool Primary = false;

		CameraComponent() = default;
		CameraComponent(const CameraComponent&) = default;
		CameraComponent(const glm::mat4& projection)
			: Camera(projection) {}
		CameraComponent(const BrickEngine::Camera& camera)
			: Camera(camera) {}
	};

	struct ColliderComponent
	{
		BrickEngine::Collider& Collider;

		ColliderComponent() = default;
		ColliderComponent(const ColliderComponent&) = default;
		ColliderComponent(BrickEngine::Collider& collider)
			: Collider(collider) {}
		ColliderComponent(BrickEngine::Collider&& collider)
			: Collider(collider) {}

		operator BrickEngine::Collider& () { return Collider; }
		operator const BrickEngine::Collider& () const { return Collider; }
	};

}
