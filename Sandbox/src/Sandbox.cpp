#include "Sandbox.h"

Sandbox::Sandbox()
{
}

Sandbox::~Sandbox()
{
}

void Sandbox::OnStart()
{
	m_Scene = CreateRef<Scene>();

	m_Cube = m_Scene->CreateCubeEntity("Cube", glm::vec4(0.2f, 0.3f, 0.8f, 1.0f));
	m_Cube.GetComponent<TransformComponent>() = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.0f));

	m_Camera = m_Scene->CreateEntity("Main Camera");
	m_Camera.AddComponent<CameraComponent>(
		glm::perspective(
			70.0f,
			(float)GetWindow().GetWidth() / (float)GetWindow().GetHeight(),
			0.1f,
			1000.0f
		)
	).Primary = true;

	m_CameraController = CameraController(m_Camera);
}

void Sandbox::OnUpdate(float delta)
{
	m_CameraController.Update(delta);
	m_Scene->OnUpdate(delta);

	Renderer::SetClearColor({ 0.2f, 0.2f, 0.2f, 1.0f });
	Renderer::Clear();
	m_Scene->DrawScene();
}

void Sandbox::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowResizeEvent>(std::bind(&Sandbox::ResizeCamera, this, std::placeholders::_1));
}
