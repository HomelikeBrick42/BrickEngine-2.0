#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

namespace BrickEngine {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void Quit();

		virtual void OnStart() = 0;
		virtual void OnUpdate(float delta) = 0;
		virtual void OnEvent(Event& e) = 0;

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		void EventCallback(Event& e);
		bool OnWindowClosed(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();

}
