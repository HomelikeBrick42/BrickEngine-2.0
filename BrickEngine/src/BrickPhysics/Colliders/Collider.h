#pragma once

#include <glm/glm.hpp>

namespace BrickEngine {

	enum class ColliderType
	{
		None = 0,
		Sphere,
		AABB
	};

	class Collider
	{
	public:
		const ColliderType& GetType() const { return m_Type; }
		virtual glm::vec3& Position() { return m_Position; }
		virtual const glm::vec3& Position() const { return m_Position; }
		virtual glm::vec3& Rotation() { return m_Rotation; }
		virtual const glm::vec3& Rotation() const { return m_Rotation; }
	protected:
		Collider(const ColliderType& type)
			: m_Type(type) {}
		Collider(const ColliderType& type, const glm::vec3& position)
			: m_Position(position), m_Type(type) {}
		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
		glm::vec3 m_Rotation = { 0.0f, 0.0f, 0.0f };
	private:
		ColliderType m_Type = ColliderType::None;
	};

	class SphereCollider : public Collider
	{
	public:
		SphereCollider()
			: Collider(ColliderType::None), m_Radius(0.0f) {}
		SphereCollider(float radius)
			: Collider(ColliderType::Sphere), m_Radius(radius) {}
		SphereCollider(float radius, const glm::vec3& position)
			: Collider(ColliderType::Sphere, position), m_Radius(radius) {}
	public:
		float& Radius() { return m_Radius; }
		const float& Radius() const { return m_Radius; }
	private:
		float m_Radius = 0.0f;
	};

	class AABBCollider : public Collider
	{
	public:
		AABBCollider()
			: Collider(ColliderType::None), m_MinExtents(0.0f), m_MaxExtents(0.0f) {}
		AABBCollider(const glm::vec3& minExtents, const glm::vec3& maxExtents)
			: Collider(ColliderType::AABB), m_MinExtents(minExtents), m_MaxExtents(maxExtents) {}
	public:
		glm::vec3& MinExtents() { return m_MinExtents; }
		const glm::vec3& MinExtents() const { return m_MinExtents; }
		glm::vec3& MaxExtents() { return m_MaxExtents; }
		const glm::vec3& MaxExtents() const { return m_MaxExtents; }
	private:
		glm::vec3 m_MinExtents = { 0.0f, 0.0f, 0.0f };
		glm::vec3 m_MaxExtents = { 0.0f, 0.0f, 0.0f };
	};

}
