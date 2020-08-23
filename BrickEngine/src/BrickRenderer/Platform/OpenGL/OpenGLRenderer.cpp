#include "brickpch.h"
#include "OpenGLRenderer.h"

#include <glad/glad.h>

namespace BrickEngine {

	Renderer* Renderer::s_Instance = new OpenGLRenderer();

	void OpenGLRenderer::BeginImpl(const Camera& camera, const glm::mat4& transform)
	{
		m_ProjectionMatrix = camera.GetProjection() * glm::inverse(transform);
		m_DirectionalLight = DirectionalLight(glm::vec3(0.7f, 1.0f, 0.6f), glm::vec3(1.0f, 1.0f, 1.0f));
	}

	void OpenGLRenderer::BeginImpl(const Camera& camera, const glm::mat4& transform, const DirectionalLight& light)
	{
		m_ProjectionMatrix = camera.GetProjection() * glm::inverse(transform);
		m_DirectionalLight = light;
	}

	void OpenGLRenderer::EndImpl()
	{
	}

	void OpenGLRenderer::SetClearColorImpl(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLRenderer::ClearImpl()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRenderer::SetViewportSizeImpl(const glm::vec2& size)
	{
		glViewport(0, 0, size.x, size.y);
	}

	void OpenGLRenderer::DrawImpl(const Ref<VertexArray> va, const glm::mat4& transform)
	{
		DrawImpl(ShaderLibrary::Get("Default"), va, transform);
	}

	void OpenGLRenderer::DrawImpl(const Ref<Shader> shader, const Ref<VertexArray> va, const glm::mat4& transform)
	{
		shader->Bind();
		shader->SetUniformMat4("u_ProjMatrix", m_ProjectionMatrix);
		shader->SetUniformMat4("u_ModelMatrix", transform);
		shader->SetUniformVec3("u_LightDirection", m_DirectionalLight.Direction);
		shader->SetUniformVec3("u_LightColor", m_DirectionalLight.Color);
		va->Bind();
		glDrawElements(GL_TRIANGLES, va->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

}
