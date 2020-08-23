#pragma once

#include <glm/glm.hpp>

#include "Shader.h"
#include "VertexArray.h"

#include "Camera.h"

#include "ShaderLibrary.h"
#include "Material.h"

namespace BrickEngine {

	struct DirectionalLight
	{
		glm::vec3 Direction;
		glm::vec3 Color;

		DirectionalLight() = default;
		DirectionalLight(const glm::vec3& direction, const glm::vec3& color)
			: Direction(direction), Color(color) {}
	};

	class Renderer
	{
	public:
		Renderer() = default;

		inline static void Begin(const Camera& camera, const glm::mat4& transform) { s_Instance->BeginImpl(camera, transform); }
		inline static void Begin(const Camera& camera, const glm::mat4& transform, const DirectionalLight& light) { s_Instance->BeginImpl(camera, transform, light); }
		inline static void End() { s_Instance->EndImpl(); }

		inline static void SetClearColor(const glm::vec4& color) { s_Instance->SetClearColorImpl(color); }
		inline static void Clear() { s_Instance->ClearImpl(); }

		inline static void SetViewportSize(const glm::vec2& size) { s_Instance->SetViewportSizeImpl(size); }

		inline static void Draw(const Ref<VertexArray> va, const glm::mat4& transform) { s_Instance->DrawImpl(va, transform); }
		inline static void Draw(const Material& material, const Ref<VertexArray> va, const glm::mat4& transform) { s_Instance->DrawImpl(material, va, transform); }
	protected:
		virtual void BeginImpl(const Camera& camera, const glm::mat4& transform) = 0;
		virtual void BeginImpl(const Camera& camera, const glm::mat4& transform, const DirectionalLight& light) = 0;
		virtual void EndImpl() = 0;

		virtual void SetClearColorImpl(const glm::vec4& color) = 0;
		virtual void ClearImpl() = 0;

		virtual void SetViewportSizeImpl(const glm::vec2& size) = 0;

		virtual void DrawImpl(const Ref<VertexArray> va, const glm::mat4& transform) = 0;
		virtual void DrawImpl(const Material& material, const Ref<VertexArray> va, const glm::mat4& transform) = 0;
	private:
		static Renderer* s_Instance;
	};

}
