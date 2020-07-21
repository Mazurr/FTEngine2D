#pragma once

#ifdef  FTE_PLATFORM_WINDOWS
	#ifdef FTE_BUILD_DLL
		#define FTE_API _declspec(dllexport)
	#else
		#define FTE_API _declspec(dllimport)
	#endif
#else
	#error FTE only support windows
#endif //  HZ_PLATFORM_WINDOWS
