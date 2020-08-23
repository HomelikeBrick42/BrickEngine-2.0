#pragma once

#include "Colliders/Collider.h"

#include "BrickCore/Core.h"

namespace BrickEngine {

	class CollisionData
	{
	public:
		CollisionData(const Collider& c1, const Collider& c2)
		{
			if (c1.GetType() == ColliderType::Sphere && c2.GetType() == ColliderType::Sphere)
			{
				SphereCollideSphere(*(SphereCollider*)&c1, *(SphereCollider*)&c2);
			}
			else if (c1.GetType() == ColliderType::AABB && c2.GetType() == ColliderType::AABB)
			{
				AABBCollidingAABB(*(AABBCollider*)&c1, *(AABBCollider*)&c2);
			}
			else
			{
				BRICKENGINE_CORE_WARN("Invalid collider type!");
			}
		}
	public:
		const bool& IsColliding() const { return m_Colliding; }
		const float& GetDistance() const { return m_Distance; }
		const glm::vec3& GetDirection() const { return m_Direction; }
	private:
		void SphereCollideSphere(const SphereCollider& s1, const SphereCollider& s2)
		{
			float distance = glm::distance(s1.Position(), s2.Position());
			m_Colliding = distance <= s1.Radius() + s2.Radius();
			m_Distance = distance - s1.Radius() + s2.Radius();
			m_Direction = glm::normalize(s1.Position() - s2.Position()) * m_Distance;
		}
		void AABBCollidingAABB(const AABBCollider& b1, const AABBCollider& b2)
		{
			glm::vec3 distances1 = b2.MinExtents() - b1.MaxExtents();
			glm::vec3 distances2 = b1.MinExtents() - b2.MaxExtents();
			glm::vec3 distances = glm::max(distances1, distances2);

			float maxDistance = std::max(distances.x, std::max(distances.y, distances.z));

			m_Colliding = maxDistance <= 0;
			m_Distance = maxDistance;
			m_Direction = glm::normalize(b1.Position() - b2.Position()) * m_Distance;
		}
	private:
		bool m_Colliding = false;
		float m_Distance = 0.0f;
		glm::vec3 m_Direction = { 0.0f, 0.0f, 0.0f };
	};

}
