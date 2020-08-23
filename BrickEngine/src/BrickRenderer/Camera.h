#pragma once

#include "BrickCore/Core.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace BrickEngine {

	class Camera
	{
	public:
		Camera() = default;
		Camera(const Camera& other) = default;
		Camera(const glm::mat4& projection)
			: m_Projection(projection) {}

		const glm::mat4& GetProjection() const { return m_Projection; }
		void SetProjection(const glm::mat4& projection) { m_Projection = projection; }
	protected:
		glm::mat4 m_Projection;
	};

	/*class PerspectiveCamera
	{
	public:
		PerspectiveCamera() {}
		PerspectiveCamera(float width, float height, Ref<Shader> shader)
			: m_Position(0.0f, 0.0f, 0.0f), m_Rotation(0.0f, 0.0f, 0.0f), m_Width(width), m_Height(height), m_Shader(shader)
		{
			RecalculateProjectionMatrix();
		}

		const glm::vec3& GetPosition() const
		{
			return m_Position;
		}

		void SetPosition(const glm::vec3& position)
		{
			m_Position = position;
			RecalculateProjectionMatrix();
		}

		const glm::vec3& GetRotation() const
		{
			return m_Rotation;
		}

		void SetRotation(const glm::vec3& rotation)
		{
			m_Rotation = rotation;
			RecalculateProjectionMatrix();
		}

		void Resize(float width, float height)
		{
			m_Width = width;
			m_Height = height;
			RecalculateProjectionMatrix();
		}

		const glm::mat4& GetMatrix() { return m_ProjectionMatrix; }
	private:
		void RecalculateProjectionMatrix()
		{
			m_ProjectionMatrix =
				glm::perspective(70.0f, m_Width / m_Height, 0.1f, 1000.0f) *
				glm::rotate(glm::rotate(glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)), glm::radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)), glm::radians(m_Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)) *
				glm::translate(glm::mat4(1.0f), m_Position);

			m_Shader->Bind();
			m_Shader->SetUniformMat4("u_ProjMatrix", m_ProjectionMatrix);
		}
	private:
		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
		glm::vec3 m_Rotation = { 0.0f, 0.0f, 0.0f };

		float m_Width = 0.0f;
		float m_Height = 0.0f;

		Ref<Shader> m_Shader;
	};*/

}
