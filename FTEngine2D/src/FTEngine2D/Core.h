#pragma once

#ifdef  FTE_PLATFORM_WINDOWS
	#ifdef FTE_BUILD_DLL
		#define FTE_API _declspec(dllexport)
	#else
		#define FTE_API _declspec(dllimport)
	#endif
#else
	#error FTE only support windows
#endif

#ifdef FTE_ENABLE_ASSERTS
	#define FTE_ASSERT(x, ...) { if(!(x)) { FTE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define FTE_CORE_ASSERT(x, ...) { if(!(x)) { FTE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define FTE_ASSERT(x, ...)
	#define FTE_CORE_ASSERT(x, ...)
#endif



#define BIT(x) (1 << x)