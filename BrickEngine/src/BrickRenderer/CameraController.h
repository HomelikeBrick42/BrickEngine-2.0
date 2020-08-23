#pragma once

#include "Camera.h"
#include "BrickCore/Scene/Entity.h"

namespace BrickEngine {

	class CameraController
	{
	public:
		CameraController() = default;
		CameraController(const Entity& camera);

		void Update(float delta);
	public:
		glm::vec3& Position() { return m_Position; }
		const glm::vec3& Position() const { return m_Position; }
	private:
		void ProsessInput(float delta);
		void UpdateCameraVectors();
	private:
		Entity m_CameraEntity;
		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
		float m_Pitch = 0.0f;
		float m_Yaw = 0.0f;
	private:
		glm::vec3 m_Forward = { 0.0f, 0.0f, 0.0f };
		glm::vec3 m_Up = { 0.0f, 0.0f, 0.0f };
		glm::vec3 m_Right = { 0.0f, 0.0f, 0.0f };
		glm::vec3 m_WorldUp = { 0.0f, 1.0f, 0.0f };
	};

}
