#pragma once

#include <BrickEngine.h>

using namespace BrickEngine;

class Sandbox : public BrickEngine::Application
{
public:
	Sandbox();
	~Sandbox();
public:
	virtual void OnStart() override;
	virtual void OnUpdate(float delta) override;
	virtual void OnEvent(Event& e) override;
private:
	Ref<Scene> m_Scene;
	CameraController m_CameraController;
	Entity m_Camera;
	Entity m_Ground;
	Entity m_Glass;
private:
	bool ResizeCamera(WindowResizeEvent& e)
	{
		m_Camera.GetComponent<CameraComponent>().Camera.SetProjection(
			glm::perspective(
				70.0f,
				(float)GetWindow().GetWidth() / (float)GetWindow().GetHeight(),
				0.001f,
				1000.0f
			)
		);
		return false;
	}
};

BrickEngine::Application* BrickEngine::CreateApplication()
{
	return new Sandbox();
}
