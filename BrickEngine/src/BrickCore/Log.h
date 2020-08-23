#pragma once

#include "brickpch.h"

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace BrickEngine {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
	
}

#define BRICKENGINE_CORE_TRACE(...)			::BrickEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BRICKENGINE_CORE_INFO(...)			::BrickEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BRICKENGINE_CORE_WARN(...)			::BrickEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BRICKENGINE_CORE_ERROR(...)			::BrickEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BRICKENGINE_CORE_FATAL(...)			::BrickEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define BRICKENGINE_TRACE(...)				::BrickEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BRICKENGINE_INFO(...)				::BrickEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define BRICKENGINE_WARN(...)				::BrickEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BRICKENGINE_ERROR(...)				::BrickEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define BRICKENGINE_FATAL(...)				::BrickEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
