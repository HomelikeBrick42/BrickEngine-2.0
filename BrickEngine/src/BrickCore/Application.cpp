#include "brickpch.h"
#include "Application.h"

#include "BrickCore/Input.h"

#include "BrickRenderer/Renderer.h"
#include "BrickRenderer/MeshLibrary.h"

#include <GLFW/glfw3.h>

namespace BrickEngine {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application* Application::s_Instance;

	Application::Application()
	{
		if (!s_Instance)
			s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::EventCallback));
		ShaderLibrary::Init();
		MeshLibrary::Init();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		OnStart();
		double lastFrame = glfwGetTime();
		float delta = 0;
		while (m_Running)
		{
			delta = (float)(glfwGetTime() - lastFrame);
			lastFrame = glfwGetTime();
			m_Window->OnUpdate();

			OnUpdate(delta);
		}
	}

	void Application::Quit()
	{
		WindowCloseEvent event;
		OnWindowClosed(event);
	}

	void Application::EventCallback(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClosed));
		dispatcher.Dispatch<WindowResizeEvent>([](WindowResizeEvent& e) -> bool
		{
			Renderer::SetViewportSize({ e.GetWidth(), e.GetHeight() });
			return false;
		});
		OnEvent(e);
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}
