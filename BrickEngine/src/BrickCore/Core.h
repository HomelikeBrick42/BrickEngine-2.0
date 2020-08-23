#pragma once

#include "Log.h"

#ifdef BRICKENGINE_DEBUG
	#define BRICKENGINE_ASSERT(x, ...) { if (!(x)) { BRICKENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define BRICKENGINE_CORE_ASSERT(x, ...) { if (!(x)) { BRICKENGINE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BRICKENGINE_ASSERT(x, ...)
	#define BRICKENGINE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

namespace BrickEngine {

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}
