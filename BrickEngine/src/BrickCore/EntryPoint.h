#pragma once

extern BrickEngine::Application* BrickEngine::CreateApplication();

int main(int argc, char** argv)
{
	BrickEngine::Log::Init();

	auto app = BrickEngine::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
