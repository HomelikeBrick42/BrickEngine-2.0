#include "brickpch.h"
#include "CameraController.h"

#include "BrickCore/Input.h"
#include "BrickCore/Scene/Components.h"

namespace BrickEngine {

	CameraController::CameraController(const Entity& camera)
		: m_CameraEntity(camera), m_Position(0.0f), m_Yaw(0.0f), m_Pitch(0.0f)
	{
	}

	void CameraController::Update(float delta)
	{
		ProsessInput(delta);
		UpdateCameraVectors();
	}

	void CameraController::ProsessInput(float delta)
	{
		if (Input::IsKeyPressed(BRICKENGINE_KEY_W))
			m_Position += m_Forward * delta * 5.0f;
		if (Input::IsKeyPressed(BRICKENGINE_KEY_S))
			m_Position -= m_Forward * delta * 5.0f;
		if (Input::IsKeyPressed(BRICKENGINE_KEY_A))
			m_Position -= m_Right * delta * 5.0f;
		if (Input::IsKeyPressed(BRICKENGINE_KEY_D))
			m_Position += m_Right * delta * 5.0f;
		if (Input::IsKeyPressed(BRICKENGINE_KEY_Q))
			m_Position += m_Up * delta * 5.0f;
		if (Input::IsKeyPressed(BRICKENGINE_KEY_E))
			m_Position -= m_Up * delta * 5.0f;

		if (Input::IsKeyPressed(BRICKENGINE_KEY_LEFT))
			m_Yaw += 90.0f * delta;
		if (Input::IsKeyPressed(BRICKENGINE_KEY_RIGHT))
			m_Yaw -= 90.0f * delta;
		if (Input::IsKeyPressed(BRICKENGINE_KEY_UP))
			m_Pitch += 90.0f * delta;
		if (Input::IsKeyPressed(BRICKENGINE_KEY_DOWN))
			m_Pitch -= 90.0f * delta;
	}

	void CameraController::UpdateCameraVectors()
	{
		auto& transform = m_CameraEntity.GetComponent<TransformComponent>().Transform;
		m_Forward = glm::normalize(glm::vec3(transform[2]));
		m_Right = glm::normalize(glm::cross(m_Forward, glm::vec3(0.0f, 1.0f, 0.0f)));
		m_Up = glm::normalize(glm::cross(m_Right, m_Forward));
		transform = glm::translate(glm::mat4(1.0f), m_Position * -1.0f);
		transform = glm::rotate(transform, glm::radians(m_Yaw), glm::vec3(0.0, 1.0, 0.0));
		transform = glm::rotate(transform, glm::radians(m_Pitch), glm::vec3(1.0, 0.0, 0.0));
	}

}
