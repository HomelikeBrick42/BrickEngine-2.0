#pragma once

#include "BrickRenderer/Renderer.h"

namespace BrickEngine {

	class OpenGLRenderer : public Renderer
	{
	public:
		OpenGLRenderer() {}

		virtual void BeginImpl(const Camera& camera, const glm::mat4& transform) override;
		virtual void BeginImpl(const Camera& camera, const glm::mat4& transform, const DirectionalLight& light) override;
		virtual void EndImpl() override;

		virtual void SetClearColorImpl(const glm::vec4& color) override;
		virtual void ClearImpl() override;

		virtual void SetViewportSizeImpl(const glm::vec2& size) override;

		virtual void DrawImpl(const Ref<VertexArray> va, const glm::mat4& transform) override;
		virtual void DrawImpl(const Ref<Shader> shader, const Ref<VertexArray> va, const glm::mat4& transform) override;
	private:
		glm::mat4 m_ProjectionMatrix;
		DirectionalLight m_DirectionalLight;
	};

}
